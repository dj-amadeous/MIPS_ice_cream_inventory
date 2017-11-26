#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::confirm_dlg_order(Mice::Order order)
{
  int i = 0;
  std::string s = "";

  for(Mice::Serving serving : order.servings())
  {
    s += "serving " + std::to_string(i + 1) + "\n";
    s += "Server: " + _servers[order.get_server_id()].name() + "\n";
    //use i for the serving index
    s += "Container: " + order.get_serving(i).container().name() + "\n";
    s += "Scoops: ";
    for(Mice::Scoop scoop : order.get_serving(i).scoops()) s += scoop.name() + "\n";
    s += "Toppings: ";
    for(Mice::Topping topping : order.get_serving(i).toppings()) s += topping.name() + "\n";
    i++;
  }
  //I could use an about dialog? and just pack the entire message in there instead of using labels?
  //Gtk::HBox
  Gtk::MessageDialog dialog{s};
  dialog.set_transient_for(*this);
  dialog.set_name("Order Confirmation");

  dialog.show_all();
  dialog.run();
}
