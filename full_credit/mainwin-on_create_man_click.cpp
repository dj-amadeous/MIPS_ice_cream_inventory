#include "mainwin.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void Mainwin::on_create_man_click()
{
  int WIDTH = 15;
  Gtk::Dialog dialog;
  dialog.set_title("Create Manager");
  dialog.set_transient_for(*this);
  //Name
  Gtk::HBox b_name;
  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(WIDTH);
  b_name.pack_start(l_name, Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(WIDTH*4);
  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

  Gtk::HBox b_id;
  Gtk::Label l_id{"ID:"};
  l_id.set_width_chars(WIDTH);
  b_id.pack_start(l_id, Gtk::PACK_SHRINK);

  Gtk::Entry e_id;
  e_id.set_max_length(WIDTH*4);
  b_id.pack_start(e_id, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

  Gtk::HBox b_phone;
  Gtk::Label l_phone{"Phone:"};
  l_phone.set_width_chars(WIDTH);
  b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

  Gtk::Entry e_phone;
  e_phone.set_max_length(WIDTH*4);
  b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);


/*  Gtk::HBox b_active;
  Gtk::Label l_active{"Active:"};
  l_active.set_width_chars(WIDTH);
  b_active.pack_start(l_active, Gtk::PACK_SHRINK);*/

// I don't need to set active or not since it's automatically active on created
  /*Gtk::ComboBoxText c_active;
  c_active.set_max_length(WIDTH*4);
  c_active.append("No");
  c_active.append("Yes");*/

  dialog.add_button("Cancel", 0);
  dialog.add_button("OK", 1);
  dialog.show_all();


    bool valid_data = false;
    std::string name, phone;
    int id;

  while(!valid_data) {
      if (dialog.run() != 1) {
          dialog.close();
          return;
      }

      valid_data = true;
      try {
          name = e_name.get_text();
      } catch(std::exception e) {
          e_name.set_text("*** invalid name ***");
          valid_data = false;
      }
      try {
          id = std::stoi(e_id.get_text());
      } catch(std::exception e) {
          e_id.set_text("*** invalid id ***");
          valid_data = false;
      }
        try {
            phone = e_phone.get_text();
        } catch(std::exception e) {
            e_phone.set_text("*** invalid number ***");
            valid_data = false;
        }

      for (Mice::Manager m : _managers) if (m.name() == e_name.get_text()) {
          e_name.set_text("*** duplicate name ***");
          valid_data = false;
      }
  }
  Mice::Manager m{name, id, phone};
  _managers.push_back(m);

  std::cout << _managers[0].name() << std::endl;

  dialog.close();
}
