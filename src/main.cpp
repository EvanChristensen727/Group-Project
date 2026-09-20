#include "Reservation.h"
#include "Resource.h"
#include "ReservationManager.h"

using namespace std;

int main() {
  ReservationManager manager;
  ResourceManager ResourceList;

  ResourceList.getFromFile();

  int userSelect = -1;
  string userInput;


  //scan in all the things
  while(userSelect != 0){ //I have no compiled yet to check if this works
	  cout << "===== Campus Resource Reservation System =====" << endl;
	  cout << "1) View Resources " << endl; //done
	  cout << "2) Create Reservation" << endl; 
	  cout << "3) Cancel Reservation" << endl;
	  cout << "4) View Waiting List" << endl;
	  cout << "5) Undo Cancellation" << endl;
	  cout << "6) Search Reservations" << endl; //not needed yet
	  cout << "7) Sort Resources" << endl; //not needed yet
	  cout << "8) Generate Report" << endl; //not needed yet?
	  cout << "0) Exit" << endl << endl;

	  cout << "Enter Selection: ";
	  cin >> userSelect;
	  cout << endl;
      string name, res_ID, date, student_ID;

	  switch (userSelect){
		case 1:
			ResourceList.displayResources();
			cout << "Press any key to continue..." << endl;
			cin.get(); //prevent menu from looping till user gets a look at reasources
			break;
		case 2:
			
			
			cout << "Please enter the student ID, resource ID, student name, and current date seperated by commas: ";
			getline(cin, student_ID, ',');
			getline(cin, res_ID, ',');
			getline(cin, name, ',');
			getline(cin, date);
			
			manager.AddReservation(Reservation(stoi(student_ID), name, res_ID, date));
			
			break;
		case 3:
			cout << "Enter The Reservation Id to cancel: ";
			cin >> userInput;
			cout << endl;
			manager.CancelReservation(stoi(userInput));
			//convert CancelResercation too bool so we can tell if complete?
			
			break;
		case 4:
			break;
		case 5:
			manager.UndoCancel();
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 0:
			break;
		default:
			cout << "incorrect selection please try again" << endl;
			break;
		
	  }
  }

  return 0;
}
