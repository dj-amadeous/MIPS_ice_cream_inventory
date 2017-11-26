#ifndef _PERSON_H
#define _PERSON_H

#include <string>

namespace Mice {

class Person {
  public:
    Person(std::string name, int id, std::string phone, bool active);
    void toggle_active();
    virtual std::string type() const;
    virtual std::string name() const;
    int id() const;
    std::string phone() const;
    bool active() const;

  private:
    int _id;
    std::string _phone;
    std::string _name;
    bool _active;
};
}


#endif
