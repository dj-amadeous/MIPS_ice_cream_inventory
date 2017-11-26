#include "serving.h"
#include <iostream>

namespace Mice {

Serving::Serving(Container& container) : _container{container}
{
  //container.consume();
}
Container Serving::container() const {return _container;}
std::vector<Scoop> Serving::scoops() const {return _scoops;}
std::vector<Topping> Serving::toppings() const {return _toppings;}

void Serving::add_scoop(Scoop& scoop)
{
  //scoop.consume();
  _scoops.push_back(scoop);

}
void Serving::add_topping(Topping& topping) {
  //topping.consume();
  _toppings.push_back(topping);

}
//void Serving::add_ID(int numID) {}

double Serving::cost() const {
    double total = _container.cost();
    for (Scoop scoop : _scoops) total += scoop.cost();
    for (Topping topping : _toppings) total += topping.cost();
    return total;
}

double Serving::price() const {
    double total = _container.price();
    for (Scoop scoop : _scoops) total += scoop.price();
    for (Topping topping : _toppings) total += topping.price();
    return total;
}

}

std::ostream& operator<<(std::ostream& os, const Mice::Serving& serving) {
    os << serving.container();
    for (Mice::Scoop s : serving.scoops()) os << std::endl << s;
    for (Mice::Topping t : serving.toppings()) os << std::endl << t;
    return os;
}
