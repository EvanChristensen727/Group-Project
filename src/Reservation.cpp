using namespace stc;

class Reservation{
  public:
    int get_reservation_ID();
    int get_student_ID();
    int get_student_name();
    int get_resource_ID();
    int get_date();
    Reservation(int s_ID, string s_Name, string resource_id, string date, int reserve_ID);
    Reservation(int s_ID, string s_Name, string resource_id, string date);
  private:
    int reservation_ID;
    int student_ID;
    string student_Name;  
    string resource_ID;
    string date;
};
