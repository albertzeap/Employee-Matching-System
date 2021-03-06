#include "UI/SimpleUI.hpp"

#include <any>         // any_cast()
#include <iomanip>     // setw()
#include <iostream>    // streamsize
#include <limits>      // numeric_limits
#include <memory>      // unique_ptr, make_unique<>()
#include <string>      // string, getline()
#include <vector>
#include <stdlib.h>    // srand()
#include <time.h>      // time()

#include "Domain/Session/SessionHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"




namespace UI
{
  // Default constructor
  SimpleUI::SimpleUI():
  // : _bookHandler   ( std::make_unique<Domain::Library::Books>()                     ),   // will replace these with factory calls in the next increment
    _loggerPtr     ( TechnicalServices::Logging::LoggerHandler::create()            ),
    _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() )
  {
    _logger << "Simple UI being used and has been successfully initialized";
  }




  // Destructor
  SimpleUI::~SimpleUI() noexcept
  {
    _logger << "Simple UI shutdown successfully";
  }




  // Operations
  void SimpleUI::launch()
  {
    std::string sessionID;
    // 1) Fetch Role legal value list
    std::vector<std::string> roleLegalValues = _persistentData.findRoles();


    // 2) Present login screen to user and get username, password, and valid role
    Domain::Session::UserCredentials credentials  = {"", "",{""}};           // ensures roles[0] exists
    auto &                           selectedRole = credentials.roles[0];     // convenience alias

    std::unique_ptr<Domain::Session::SessionHandler> sessionControl;

    do
    {
      std::cin.ignore(  std::numeric_limits<std::streamsize>::max(), '\n' );

      std::cout << "  name: ";
      std::getline( std::cin, credentials.userName );

      std::cout << "  pass phrase: ";
      std::getline( std::cin, credentials.passPhrase );

      // unsigned menuSelection;
      // do
      // {
      //   for( unsigned i = 0; i != roleLegalValues.size(); ++i )   std::cout << std::setw( 2 ) << i << " - " << roleLegalValues[i] << '\n';
      //   std::cout << "  role (0-" << roleLegalValues.size()-1 << "): ";
      //   std::cin  >> menuSelection;
      // } while( menuSelection >= roleLegalValues.size() );

      Domain::Session::UserCredentials account = _persistentData.findCredentialsByName(credentials.userName);
      for (unsigned i = 0; i != roleLegalValues.size(); ++i)
      {
        
        if (account.roles[0] == roleLegalValues[i])
        {
          selectedRole = account.roles[0];
        }
      }

      // selectedRole = roleLegalValues[menuSelection];
      // selectedRole = credentials.roles[0];

      // 3) Validate user is authorized for this role, and if so create session
      sessionControl = Domain::Session::SessionHandler::createSession( credentials );
      if( sessionControl != nullptr )
      {
        
        srand(static_cast<unsigned> (time(0)));
        int session_id = rand()%10000;
        sessionID = std::to_string(session_id);

        _logger << "Login Successful for \"" + credentials.userName + "\" as role \"" + selectedRole + "\"";
        _logger << "Session ID: " + sessionID;
        
        break;
      }

      std::cout << "** Login failed\n";
      _logger << "Login failure for \"" + credentials.userName + "\" as role \"" + selectedRole + "\"";

    } while( true );


    // 4) Fetch functionality options for this role
    do
    {
      auto        commands = sessionControl->getCommands();
      std::string selectedCommand;
      unsigned    menuSelection;

      do
      {
        for( unsigned i = 0; i != commands.size(); ++i ) std::cout << std::setw( 2 ) << i << " - " << commands[i] << '\n';
        std::cout << std::setw( 2 ) << commands.size() << " - " << "Quit\n";

        std::cout << "  action (0-" << commands.size() << "): ";
        std::cin >> menuSelection;
      } while( menuSelection > commands.size() );

      if( menuSelection == commands.size() ) break;

      selectedCommand = commands[menuSelection];
      _logger << "Command selected \"" + selectedCommand + '"';


      /******************************************************************************************************************************
      **  5) The user interface will collect relevant information to execute the chosen command.  This section requires the UI to
      **     know what information to collect, and hence what the available commands are.  Our goal is loose (minimal) coupling, not
      **     no coupling. This can be achieved in a variety of ways, but one common way is to pass strings instead of strong typed
      **     parameters.
      ******************************************************************************************************************************/
      if( selectedCommand == "Checkout Book" )
      {
        std::vector<std::string> parameters( 3 );

        std::cout << " Enter book's title:  ";  std::cin >> std::ws;  std::getline( std::cin, parameters[0] );
        std::cout << " Enter book's author: ";  std::cin >> std::ws;  std::getline( std::cin, parameters[1] );
        std::cout << " Enter book's ISBN:   ";  std::cin >> std::ws;  std::getline( std::cin, parameters[2] );

        auto results = sessionControl->executeCommand( selectedCommand, parameters );
        if( results.has_value() ) _logger << "Received reply: \"" + std::any_cast<const std::string &>( results ) + '"';
      }

      else if( selectedCommand == "Manage Resume" ) /* ... */ 
      {
        int choice;
        std::vector<std::string> parameters ( 1 );

        std::cout << "0 - Upload Resume\n";  
        std::cout << "1 - Delete Resume\n";
        std::cout << "action (0-1) ";
        std::cin >> choice;
        std::cout << "Command Selected " << choice << std::endl;

        if      (choice == 0) {std::cout << " Enter file name: "; std::cin >> std::ws; std::getline(std::cin, parameters[0]);}
        else if (choice == 1) {std::cout << " Enter file name: "; std::cin >> std::ws; std::getline(std::cin, parameters[0]);}
        else                   std::cout << "INVALID CHOICE\n";
        

        auto results = sessionControl->executeCommand( selectedCommand, parameters );
        if( results.has_value() ) _logger << "Received reply: \"" + std::any_cast<const std::string &>( results ) + '"';
      }

      else if (selectedCommand == "Manage Resume Feedback")
      {
        std::vector<std::string> parameters ( 2 );

        std::cout << "Resumes\n";
        std::cout << "  BobResume.txt\n";
        std::cout << "  StevenResume.txt\n\n";

        std::cout << "Enter resume to begin feedback: "; std::cin >> std::ws; std::getline(std::cin, parameters[0]);
        std::cout << "Enter resume feedback: "         ; std::cin >> std::ws; std::getline(std::cin, parameters[1]);

        auto results = sessionControl->executeCommand( selectedCommand, parameters );
        if( results.has_value() ) _logger << "Received reply: \"" + std::any_cast<const std::string &>( results ) + '"';
      }

      else sessionControl->executeCommand( selectedCommand, {} );
    } while( true );

    _logger << "Ending session " + sessionID + " and terminating";
  }

  
}
