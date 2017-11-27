#include "manager.h"


namespace Mice {

  Manager::Manager(std::string name, int id, std::string phone, bool active)
            : Person(name, id, phone, active) { }
  std::string Manager::type() const {return "Manager";}
  }
