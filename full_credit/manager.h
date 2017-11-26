#ifndef _MANAGER_H
#define _MANAGER_H

#include "person.h"
//<<<<<<< HEAD
#include "server.h"
/*=======
#include "server.h"
>>>>>>> e58cfd4d9787e592efedd651a2157c733741daf0*/

namespace Mice {

class Manager : public Person {
  public:
    Manager(std::string name, int id, std::string phone, bool active = true);
    std::string type() const override;
    //Server create_new_server();
  private:

};

}
#endif
