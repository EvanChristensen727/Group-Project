#include "Reservation.h"

Reservation::Reservation(int s_ID, string s_Name, string resource_id, string date, int reserve_ID){
  student_ID = s_ID;
  student_Name = s_Name;
  resource_ID = resource_id;
  this->date* = date;
  reservation_ID = reserve_ID;
}

Reservation::Reservation(int s_ID, string s_Name, string resource_id, string date){
  student_ID = s_ID;
  student_Name = s_Name;
  resource_ID = resource_id;
  this->date* = date;
  reservation_ID = -1;
}

string Reservation::get_date(){
  return date;
}

int Reservation::get_reservation_ID(){
  return reservation_ID;
}

int Reservation::get_student_ID(){
  return student_ID;
}

string Reservation::get_student_name(){
  return student_Name;
}

string Reservation::get_resource_ID(){
  return resource_ID;
}

void Reservation::set_reservation_ID(int id){
  reservation_ID = id;
}


//Takes a line (string) in the same format as reservations.txt and returns the address of a new Reservation object 
static Reservation Reservation::load_reservation(string line){
  int i = 0;
  string data[5] = ["", "", "", "", ""];
  
  for (char c : line){
    if (c == "|"){
      i++;
      continue;
    }
    data[i] += c;
  }
  return new Reservation(stoi(data[1]), data[2], data[3], data[4], stoi(data[0]));
}

