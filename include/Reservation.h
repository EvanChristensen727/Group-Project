#ifndef RESERVATION_H

#define RESERVATION_H
using namespace std;  
class Reservation{
  public: 
    int get_reservation_ID();
    int get_student_ID();
    string get_student_name();
    string get_resource_ID();
    string get_date();
    void set_reservation_ID(int id);
    Reservation(int s_ID, string s_Name, string resource_id, string date, int reserve_ID);
    Reservation(int s_ID, string s_Name, string resource_id, string date);
    
  private:
    int reservation_ID;
    int student_ID;
    string student_Name;  
    string resource_ID;
    string date;
};
#endif
