#include "mainwin.h"
#include <iostream>

void Mainwin::on_create_server_click()
{
  int WIDTH = 15;
  //all variables for creating the server object
  std::string name, phone, id, salary;
  int id_to_int;
  double salary_to_dub;
  Gtk::Dialog dialog{"Create New Server", *this};
//name entry
  Gtk::HBox b_name;
  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(WIDTH);
  b_name.pack_start(l_name, Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(WIDTH*4);
  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
//server id entry
  Gtk::HBox b_id;
  Gtk::Label l_id{"Server ID:"};
  l_id.set_width_chars(WIDTH);
  b_id.pack_start(l_id, Gtk::PACK_SHRINK);

  Gtk::Entry e_id;
  e_id.set_max_length(WIDTH*4);
  b_id.pack_start(e_id, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

//server phone number entry
  Gtk::HBox b_phone;
  Gtk::Label l_phone{"Phone #:"};
  l_phone.set_width_chars(WIDTH);
  b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

  Gtk::Entry e_phone;
  e_phone.set_max_length(WIDTH*4);
  b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

//server sallary entry
  Gtk::HBox b_sal;
  Gtk::Label l_sal{"Salary:"};
  l_sal.set_width_chars(WIDTH);
  b_sal.pack_start(l_sal, Gtk::PACK_SHRINK);

  Gtk::Entry e_sal;
  e_sal.set_max_length(WIDTH*4);
  b_sal.pack_start(e_sal, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_sal, Gtk::PACK_SHRINK);



  dialog.add_button("Cancel", 0);
  dialog.add_button("OK", 1);
  dialog.show_all();

  int confirmation = dialog.run();

  if(confirmation == 1)
  {
    name = e_name.get_text();
    id = e_id.get_text();
    phone = e_phone.get_text();
    salary = e_sal.get_text();
  }
  id_to_int = stoi(id);
  salary_to_dub = stod(salary);

  Mice::Server server(name, id_to_int, phone, salary_to_dub);
  _servers.push_back(server);


  dialog.close();
}
