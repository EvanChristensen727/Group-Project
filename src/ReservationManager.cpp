#include "ReservationManager.h"

void ReservationManager::SearchReservation(int id)
{
    //TODO
}

void ReservationManager::SearchReservation(string rId)
{
    //TODO
}

string ReservationManager::AddReservation(Reservation r)
{
    //resource checked for availability before this

    //check if it has an id
    if (r.get_reservation_ID() == -1) 
    {
        if (currentReservs.empty()) //if this is the first reservation and there's no preexisting ID
            r.set_reservation_ID(1);
        else
             r.set_reservation_ID(currentReservs.back().get_reservation_ID() + 1); //add 1 to the last reservation
    }

    //add it
    currentReservs.push_back(r);
    return r.get_resource_ID();
}

string ReservationManager::CancelReservation(int id)
{
    //search for id
    list<Reservation>::iterator it;
    for (it = currentReservs.begin(); it != currentReservs.end(); it++)
    {
        if ((*it).get_reservation_ID() == id)
        {
            //TODO: make resource available
            string rId = (*it).get_resource_ID()
            cancelledReservs.push(*it);
            currentReservs.erase(it);
            cout << "Reservation ID " << id << " Cancelled." << endl; 
            return rId; //exit function.
        }
    }
    cout << "Reservation ID " << id << " Does Not Exist." << endl; 
    return "";
}

void ReservationManager::UndoCancel()
{
    if (cancelledReservs.empty())
    {
        cout << "No Reservations To Restore." << endl;
        return;
    }
    currentReservs.push_back(cancelledReservs.top());
    cancelledReservs.pop();
    cout << "Reservation Restored Successfully." << endl;
}

void ReservationManager::PrintReservations()
{
    list<Reservation>::iterator it;
    int i = 0; //TODO
    for (it = currentReservs.begin(); it != currentReservs.end(); it++)
    {
        cout << i << endl;
    }
}
