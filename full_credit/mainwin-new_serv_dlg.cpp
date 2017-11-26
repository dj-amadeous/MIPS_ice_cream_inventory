#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

bool Mainwin::new_serv_dlg()
{
  Gtk::Dialog new_serving("More servings", *this);
  const int WIDTH = 15;
  bool returnAns;

  Gtk::HBox b_newServ;

  Gtk::Label l_newServ{"More Servings?"};
  l_newServ.set_width_chars(WIDTH);
  b_newServ.pack_start(l_newServ, Gtk::PACK_SHRINK);

  new_serving.get_vbox()->pack_start(b_newServ, Gtk::PACK_SHRINK);
  new_serving.add_button("Yes", true);
  new_serving.add_button("NO", false);
  returnAns = new_serving.run();
  return returnAns;

}
