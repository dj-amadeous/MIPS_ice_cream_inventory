#ifndef _SERVER_H
#define _SERVER_H

#include "person.h"

namespace Mice {

class Server : public Person {
  public:
    Server(std::string name, int id, std::string phone, double salary,
          bool active = true, int num_orders = 0, int num_orders_lifetime = 0, double cash = 0);
    std::string type() const override;
    bool fill_order_and_pay();
    bool restock_and_pay();
    double pay_server();
    void iterate_num_orders();
    double get_salary();//DON'T TOUCH! WILL BREAK STUFF!
    int get_num_orders();
    int get_num_orders_lifetime();
    void reset_num_orders();
    void update_num_orders_restock();
    void set_cash();
    void set_salary(double salary);
    std::string to_string();
    //just for testing
    //int get_num_orders();
  private:
    int _num_orders;
    int _num_orders_lifetime;
    double _salary;
    double _cash;
};

}
#endif
