#include "ReservationManager.h"

ReservationManager::ReservationManager() 
{

}

void ReservationManager::SearchReservation(int id)
{
    //fuuuuck
}

void ReservationManager::SearchReservation(string rId)
{
    //FUUUUUUCK
}

void ReservationManager::AddReservation(Reservation r)
{
    //TODO: check if the resource is available 

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
}

void ReservationManager::CancelReservation(int id)
{
    //search for id
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
