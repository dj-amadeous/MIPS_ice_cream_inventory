#ifndef _MANAGER_H
#define _MANAGER_H

#include "person.h"
#include "server.h"


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
