#include "Reservation.h"
#include "Resource.h"
#include "ReservationManager.h"

using namespace std;

int main() {
  ReservationManager manager;
  ResourceManager ResourceList;

  ResourceList.getFromFile();

  int userSelect = -1;


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

	  switch (userSelect){
		case 1:
			ResourceList.displayResources();
			cout << "Press any key to continue..." << endl;
			cin.get(); //prevent menu from looping till user gets a look at reasources
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
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
