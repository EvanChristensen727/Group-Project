#include "Reservation.h"
#include "Resource.h"
#include "ReservationManager.h"
#include <map>

using namespace std;

int main() {
  ReservationManager manager;
  ResourceManager ResourceList;

  ResourceList.getFromFile();
  manager.ReservationsFromFile();

  int userSelect = -1;
  string userInput;


  //scan in all the things
  while(userSelect != 0){ //I have no compiled yet to check if this works
	  cout << "===== Campus Resource Reservation System =====" << endl;
	  cout << "1) View Resources " << endl; //done
	  cout << "2) Create Reservation" << endl; //done 
	  cout << "3) Cancel Reservation" << endl; //done
	  cout << "4) View Waiting List" << endl;
	  cout << "5) Undo Cancellation" << endl; //done
	  cout << "6) Search Reservations" << endl; //not needed yet
	  cout << "7) Sort Resources" << endl; //not needed yet
	  cout << "8) Generate Report" << endl; //Working on it - Arin
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

			if (!ResourceList.isAvailable(res_ID))
			{
				manager.AddToWaitingList(Reservation(stoi(student_ID), name, res_ID, date));
			}
			else
			{
				manager.AddReservation(Reservation(stoi(student_ID), name, res_ID, date));
				ResourceList.setResourceAvailability(res_ID, false);
			}

			break;
		case 3:{
			cout << "Enter The Reservation Id to cancel: ";
			cin >> userInput;
			cout << endl;
			string tempRId = manager.CancelReservation(stoi(userInput)); //TRUST THE PROCESS
			if (tempRId != "")
			{
				ResourceList.setResourceAvailability(tempRId, true);
				manager.CheckWaitingList(tempRId); //queue things
			}
			//convert CancelResercation too bool so we can tell if complete?
		       	
			break;
		       }
		case 4:
			manager.PrintReservations(); //eugh
			cout << endl;
			break;
		case 5:
			manager.UndoCancel();
			break;
		case 6:
			cout << "Search by Reservation ID (1) or Resource ID (2)?"
			break;
		case 7:
			break;
		case 8: //Resource Reporting
			{
			map<string, int> resourceCounts; //Key: Resource Id, value: number of times requested
	  		list<Reservation> current = manager.GetReservations();
			map<string, list<int>> resourceStudents; //Key: Resource Id, value: Students IDs that have requested the resource
			list<string> IDs;

			int maxCount = 1;
			string max = current.front().get_resource_ID();
			
			for (list<Reservation>::iterator it = current.begin(); it != current.end(); it++) {
				Reservation r = *it;
				bool found = false;

				for (list<string>::iterator it2 = IDs.begin(); it2 != IDs.end(); it2++){
					if (*it2 == r.get_resource_ID()){
						found = true;
						break;
					}
				}

				if (!found){
					IDs.push_back(r.get_resource_ID());
					
				}

				resourceCounts[r.get_resource_ID()]++;
				if (resourceCounts[r.get_resource_ID()] > maxCount){
					maxCount = resourceCounts[r.get_resource_ID()];
					max = r.get_resource_ID();
				}

				found = false;

				for (list<int>::iterator it2 = resourceStudents[r.get_resource_ID()].begin(); it2 != resourceStudents[r.get_resource_ID()].end(); it2++){
					if (r.get_student_ID() == *it2){
						found = true;
						break;
					}
				}
				if (!found){
					resourceStudents[r.get_resource_ID()].push_back(r.get_student_ID());
				}
				
			}

			cout << "Current number of requests for each resource:"<<endl;
			
			for (list<string>::iterator it = IDs.begin(); it != IDs.end(); it++){
				cout << "-" << *it << ": " << resourceCounts[*it] << endl; 
			}

			cout << endl << "Most requested resource: " << max << endl;

			cout << endl << "Current number of students waiting for each resource:"<<endl;

			for (list<string>::iterator it = IDs.begin(); it != IDs.end(); it++){
				cout << "-" << *it << ": " << resourceStudents[*it].size() << endl; 
			}
			
			}
			break;
		case 0:
			break;
		default:
			cout << "Not a valid option, try again." << endl;
			break;
		
	  }
  }

  return 0;
}
