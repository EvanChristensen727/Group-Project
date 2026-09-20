# Complexity Analysis

## Inserting a Reservation
Inserting and adding a reservation has a time complexity of O(1) because new reservations are added to the end of
the linked list of reservations, without having to go to travel to the end of it.

## Removing a Reservation
Canceling and removing a reservation, handled by CancelResrvation(), has a time complexity of O(n). The
CancelReservation() function does a linear search [ O(n) ] for the ID to be removed, before pushing and erasing,
with both having a time complexity of O(1), leading to a O(n) time complexity.

## Waiting List Processing
Because the Waiting List is processed in a queue, all it's processes have a time complexity of O(1).

## Undoing a Reservation
Undoing a reservation just uses push and pop functions to handle a queue and re-add the reservation to the linked
list, leading to a time complexity of O(1).