#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::confirm_dlg(Mice::Serving serving)
{
  Gtk::Dialog confirm_dialog("Order Confirmation", *this);
  const int WIDTH = 15;
  //container section
  Gtk::HBox b_contain;

  Gtk::Label l_contain{"Container:"};
  l_contain.set_width_chars(WIDTH);
  b_contain.pack_start(l_contain, Gtk::PACK_SHRINK);
  Gtk::Label l_containName{(serving.container().name() + "\n")};
  l_containName.set_width_chars(WIDTH*2);
  b_contain.pack_start(l_containName, Gtk::PACK_SHRINK);

  //ice cream scoops section
  std::string s = "\n";
  for(Mice::Scoop scoop : serving.scoops()) s += scoop.name() + "\n";
  //figure out some way to loop this? I tried putting it in a for loop but the scope makes it not work
  Gtk::HBox b_scoops;
  Gtk::Label l_scoops{"Scoops:"};
  l_scoops.set_width_chars(WIDTH);
  b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);
  Gtk::Label l_scoopName{s};
  l_scoopName.set_width_chars(WIDTH*2);
  b_scoops.pack_start(l_scoopName, Gtk::PACK_SHRINK);

  //toppings section
  s = "";
  for(Mice::Topping topping: serving.toppings()) s += topping.name() + "\n";

  Gtk::HBox b_toppings;
  Gtk::Label l_toppings{"Toppings:"};
  l_toppings.set_width_chars(WIDTH);
  b_toppings.pack_start(l_toppings, Gtk::PACK_SHRINK);
  Gtk::Label l_toppingName{s};
  l_toppingName.set_width_chars(WIDTH*2);
  b_toppings.pack_start(l_toppingName, Gtk::PACK_SHRINK);


  confirm_dialog.get_vbox()->pack_start(b_contain, Gtk::PACK_SHRINK);
  confirm_dialog.get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);
  confirm_dialog.get_vbox()->pack_start(b_toppings, Gtk::PACK_SHRINK);



  confirm_dialog.add_button("Cancel", 0);
  confirm_dialog.add_button("OK", 1);
  confirm_dialog.show_all();
  confirm_dialog.run();
}
