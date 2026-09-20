#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H
    //resource -> reservation -> reservation manager (?)
    #include <iostream>
    #include <list>  // linked list for active reservation storage
    #include <stack> // stack for cancellation history
    #include <queue> // queue for placing reservations
    #include "Reservation.h"

    using namespace std;

    class ReservationManager
    {
        public:
            void SearchReservation(int id); //search by reservation id
            void SearchReservation(string rId); //search by resource id
            string AddReservation(Reservation r); // for adding a new reservation, string returned is resource ID to set to unavailable
            string CancelReservation(int id); //cancel a reservation, string returned is resource ID to set to available
            void AddToWaitingList(Reservation r); //adds to waiting list.
            void UndoCancel();
            void PrintReservations();
	        void ReservationsFromFile();
        private:
            list<Reservation> currentReservs;
            stack<Reservation> cancelledReservs;
            queue<Reservation> waitingList;
    };

#endif
