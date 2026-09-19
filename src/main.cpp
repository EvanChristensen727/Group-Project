#include "Reservation.h"
#include "Resource.h"
#include "ReservationManager.h"

using namespace std;

int main() {
  ReservationManager manager;
  int userSelect = -1;


  //scan in all the things
  while(userSelect != 0){
	  cout << "===== Campus Resource Reservation System =====" << endl;
	  cout << "1) View Resources " << endl;
	  cout << "2) Create Reservation" << endl;
	  cout << "3) Cancel Reservation" << endl;
	  cout << "4) View Waiting List" << endl;
	  cout << "5) Undo Cancellation" << endl;
	  cout << "6) Search Reservations" << endl;
	  cout << "7) Sort Resources" << endl;
	  cout << "8) Generate Report" << endl;
	  cout << "0) Exit" << endl << endl;

	  cout << "Enter Selection: ";
	  cin >> userSelect;
	  cout << endl;

	  switch (userSelect){
		case 1:
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
