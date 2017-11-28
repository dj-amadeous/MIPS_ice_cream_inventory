#include "mainwin.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void Mainwin::on_edit_flavor_click()
{
  int scoop_index;
  int WIDTH = 15;
  //select which flavor to change
  scoop_index = select_scoop();

  Gtk::Dialog dialog;
  dialog.set_title("Edit the Flavor");
  dialog.set_transient_for(*this);
  //hbox name
  Gtk::HBox b_name;
  Gtk::Label l_name{"Name: "};
  l_name.set_width_chars(WIDTH);
  b_name.pack_start(l_name, Gtk::PACK_SHRINK);
  Gtk::Entry e_name;
  e_name.set_max_length(WIDTH*4);
  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

//hbox description
  Gtk::HBox b_desc;
  Gtk::Label l_desc{"Description: "};
  l_desc.set_width_chars(WIDTH);
  b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
  Gtk::Entry e_desc;
  e_desc.set_max_length(WIDTH*4);
  b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

//hbox cost
  Gtk::HBox b_cost;
  Gtk::Label l_cost{"Cost: "};
  l_cost.set_width_chars(WIDTH);
  b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);
  Gtk::Entry e_cost;
  e_cost.set_max_length(WIDTH*4);
  b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

//hbox price
  Gtk::HBox b_price;
  Gtk::Label l_price{"Price: "};
  l_price.set_width_chars(WIDTH);
  b_price.pack_start(l_price, Gtk::PACK_SHRINK);
  Gtk::Entry e_price;
  e_price.set_max_length(WIDTH*4);
  b_price.pack_start(e_price, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

  dialog.add_button("Cancel", 0);
  dialog.add_button("OK", 1);
  dialog.show_all();

  bool valid_data = false;
  double price, cost;
  std::string name, description;

  while(!valid_data){
    if(dialog.run() != 1){
      dialog.close();
      return;
    }

    valid_data = true;
    try{
      cost = std::stod(e_cost.get_text());
      price = std::stod(e_price.get_text());
      name = e_name.get_text();
      description = e_desc.get_text();
    } catch(std::exception e){
      e_cost.set_text("*** invalid salary ***");
      e_price.set_text("*** invalid salary ***");
      valid_data = false;
    }
    _scoops[scoop_index].set_price(price);
    _scoops[scoop_index].set_cost(cost);
    _scoops[scoop_index].set_description(description);
    _scoops[scoop_index].set_name(name);
    dialog.close();
  }
}
