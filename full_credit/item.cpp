#include "item.h"
#include <iostream>
#include <iomanip>

namespace Mice {

Item::Item(std::string name, std::string description, double cost, double price)
     : _name{name}, _description{description}, _cost{cost}, _price{price}, _quantity{25} { }
Item::Item() { }
std::string Item::type() const {return "Item";}
void Item::restock(int quantity) {_quantity  = quantity;}
void Item::consume(int quantity) {_quantity -= quantity;}
std::string Item::name() const {return _name;}
std::string Item::description() const {return _description;}
double Item::cost() const {return _cost;}
double Item::price() const {return _price;}
int Item::quantity() const {return _quantity;}
// Gtk::Image photo() {return _photo;}

std::string Item::to_string()
{
  std::string s = "";
  s += "Name: " + this->name() + "\n";
  s += "Description: " + this->description() + "\n";
  s += "Cost: " + std::to_string(this->cost()) + "\n";
  s += "Price: " + std::to_string(this->price()) + "\n";
  s += "Quantity " + std::to_string(this->quantity()) + "\n";

  return s;
}
void Item::set_name(std::string name)
{
  _name = name;
}
void Item::set_description(std::string description)
{
  _description = description;
}
void Item::set_price(double price)
{
  _price = price;
}
void Item::set_cost(double cost)
{
  _cost = cost;
}

}

// POLYMORPHISM at item.name()
std::ostream& operator<<(std::ostream& os, const Mice::Item& item) {
    os << std::setw(40) << item.type() + ": " + item.name() << " $"
       << std::setprecision(2) << std::fixed << item.price();
    return os;
}
