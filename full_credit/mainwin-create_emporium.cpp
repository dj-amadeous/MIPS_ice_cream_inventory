#include "mainwin.h"
#include <iostream>

void Mainwin::on_new_emporium_click()
{
  int WIDTH = 15;
  Gtk::Dialog dialog{"Create New Branch", *this};
  //dialog.set_title("Create New Branch");
  //dialog.set_transiet_for(*this);

  Gtk::HBox b_name;
  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(WIDTH);
  b_name.pack_start(l_name, Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(WIDTH*4);
  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

  dialog.add_button("Cancel", 0);
  dialog.add_button("OK", 1);
  dialog.show_all();

  std::string name;

  int confirmation = dialog.run();


  if(confirmation == 1)
  {
    name = e_name.get_text();
  }
  else
  {
    return;
  }

  dialog.close();

  Mice::Emporium m{name, _containers, _scoops, _toppings, _orders, _servers, };
  _emporiums.push_back(m);
}
