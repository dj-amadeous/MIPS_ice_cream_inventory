#include "manager.h"


namespace Mice {

  Manager::Manager(std::string name, int id, std::string phone, bool active)
            : Person(name, id, phone, active) { }
  std::string Manager::type() const {return "Manager";}
/*<<<<<<< HEAD
  Server Manager::create_new_server() {return Server{"Evan Cornish", 123456, "682-290-2193", true, 0, 10};}
=======
  Server Manager::create_new_server() {return Server{"Evan Cornish", 123456, "682-290-2193", true, 10};}
>>>>>>> e58cfd4d9787e592efedd651a2157c733741daf0*/
  }
