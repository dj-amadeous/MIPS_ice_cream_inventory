#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::on_generate_cust_report_click()
{
  if (_customers.size() == 0)
  {
    Gtk::MessageDialog dialog{*this, "There are no customers to report on."};
    dialog.run();
    dialog.close();
  }
  else
  {
    Glib::ustring str = "";
    for (int i =0 ; i < _customers.size(); i++)
      str += _customers[i].to_string();
    Gtk::MessageDialog dialog{*this, str};
    dialog.run();
    dialog.close();
  }

}
