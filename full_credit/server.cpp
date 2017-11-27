#include "server.h"

namespace Mice {
  Server::Server(std::string name, int id, std::string phone, double salary,
               bool active, int num_orders, int num_orders_lifetime, double cash)
            : Person(name, id, phone, active), _salary{salary}, _num_orders{num_orders}, _num_orders_lifetime{num_orders_lifetime}, _cash{cash}{ }
  std::string Server::type() const {return "Server";}
  bool Server::fill_order_and_pay() {return true;}
  bool Server::restock_and_pay() {return true;}
  double Server::get_salary() {return _salary;} // I accidentally wrote this twice, I left it becasue if i take it out it will break stuff
  //DONT' TOUCH!!!s
  int Server::get_num_orders() {return _num_orders;}
  void Server::reset_num_orders(){_num_orders = 0;}
  double Server::pay_server() {return _salary;}
  void Server::iterate_num_orders()
  {
    _num_orders++;
    _num_orders_lifetime++;
  }
  void Server::set_cash()
  {
    _cash += _num_orders*_salary;
    this->reset_num_orders();
  }
  void Server::update_num_orders_restock()
  {
    _num_orders = _num_orders + 2;
  }
  void Server::set_salary(double salary)
  {
    _salary = salary;
  }
  int Server::get_num_orders_lifetime()
  {
    return _num_orders_lifetime;
  }
  std::string Server::to_string(){
    std::string s = "";
    s += this->name() + "\n" + " (ID: " + std::to_string(this->id()) + ")\n";
    s += "Phone: " + this->phone() + "\n";
    s += "Salary: $" + std::to_string(this->get_salary()) + "/hour\n";
    s += "Orders Served: " + std::to_string(this->get_num_orders_lifetime()) + "\n";
    return s;
  }
}
