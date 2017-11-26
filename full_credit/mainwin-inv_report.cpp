#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::inv_report()
{
  int test_containers, test_scoops, test_toppings, test_all;
  test_containers = _containers.size();
  test_scoops = _scoops.size();
  test_toppings = _toppings.size();
  test_all = test_containers * test_scoops * test_toppings;
  Glib::ustring ss = "";
  for(Mice::Container c : _containers)
  {
    ss += c.to_string();
  }
  for(Mice::Scoop s : _scoops)
  {
    ss += s.to_string();
  }
  for(Mice::Topping t : _toppings)
  {
    ss += t.to_string();
  }

  std::cout << ss << std::endl;

  if(test_all)
  {
    Gtk::MessageDialog dialog{*this, ss};
    dialog.run();
    dialog.close();
  }
  else
  {
    Gtk::MessageDialog dialog{*this, "There are no items currently in inventory"};
    dialog.run();
    dialog.close();
  }

}
