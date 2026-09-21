#ifndef RESERVATION_H

#define RESERVATION_H

#include <string>

class Reservation{
  public: 
    int get_reservation_ID();
    int get_student_ID();
    std::string get_student_name();
    std::string get_resource_ID();
    std::string get_date();
    void set_reservation_ID(int id);
    static Reservation load_reservation(std::string line);
    Reservation(int s_ID, std::string s_Name, std::string resource_id, std::string date, int reserve_ID);
    Reservation(int s_ID, std::string s_Name, std::string resource_id, std::string date);
    
  private:
    int reservation_ID;
    int student_ID;
    std::string student_Name;  
    std::string resource_ID;
    std::string date;
};
#endif
