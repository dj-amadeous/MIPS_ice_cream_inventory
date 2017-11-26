#include "person.h"
#include <iostream>
#include <iomanip>

namespace Mice {

  Person::Person(std::string name, int id, std::string phone, bool active)
       : _name{name}, _id{id}, _phone{phone}, _active{true} { }

  void Person::toggle_active() { _active = !_active;}
  std::string Person::type() const {return "Person";}
  std::string Person::name() const {return _name;}
  int Person::id() const {return _id;}
  std::string Person::phone() const {return _phone;}
  bool Person::active() const {return _active;}
}
