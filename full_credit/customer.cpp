#include "customer.h"

namespace Mice {
  Customer::Customer(std::string name, int id, std::string phone, bool active)
      : Person(name, id, phone, active) { }
  std::string Customer::type() const {return "Customer";}
  std::string Customer::to_string()
  {
    std::string s = "";
    s += this->name() + "\n" + " (ID: " + std::to_string(this->id()) + ")\n";
    s += "Phone: " + this->phone() + "\n";
    return s;
  }
}
