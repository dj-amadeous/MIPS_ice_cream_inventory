#include "mainwin.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


void Mainwin::on_display_server_report_click()
{
  if (_servers.size() == 0)
  {
    Gtk::MessageDialog dialog{*this, "There are no servers to report on."};
    dialog.run();
    dialog.close();
  }
  else
  {
    Glib::ustring str = "";
    for (int i =0 ; i < _servers.size(); i++)
      str += _servers[i].to_string();
    Gtk::MessageDialog dialog{*this, str};
    dialog.run();
    dialog.close();
  }
}
