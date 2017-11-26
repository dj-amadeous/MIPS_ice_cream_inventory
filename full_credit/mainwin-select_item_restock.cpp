#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

int Mainwin::select_item_restock()
{
  const int CONTAINER = 0;
  const int SCOOP = 1;
  const int TOPPING = 2;
  int container_index, scoop_index, topping_index;
  Mice::Item to_restock;
  /*Mice::Container to_restock_c;
  Mice::Scoop to_restock_s;
  Mice::Topping to_restock_top;*/
  //int select_item = select_item();
  //mimicking same process as when we created a new item except we're going to just display what's available based on the selection
  Gtk::Dialog dialog_type{"Select Item Type", *this};
  const int WIDTH = 15;

  //type to restock
  int type_restock = choose_item_type();

  /*if(type_restock == CONTAINER)
  {
    container_index = select_container(); // this function will need to be changed because right now it gives you the toppings on mainwin, NOT On branch
    //it cannot currently account for multiple branches!!!!
    to_restock = branch.containers()[container_index];
    to_restock.restock();
  }
  else if (type_restock == SCOOP)
  {
    scoop_index = select_scoop();
    to_restock = branch.scoops()[scoop_index];
    to_restock.restock();
  }
  else if (type_restock == TOPPING)
  {
    topping_index = select_topping();
    to_restock = branch.toppings()[topping_index];
    to_restock.restock();
  }*/
  return type_restock;
}
