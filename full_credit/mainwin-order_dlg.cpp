#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::order_dlg()
{
  Glib::ustring title = "Order Report";
  Glib::ustring s = "";
  for(Mice::Order o : _orders)
  {
    if(o.get_state() == Mice::Order::UNFILLED)
    {
      s += o.to_string();
      s += "\n\n";
    }
  }
  s += "\n\n\n\n";
  for(Mice::Order o : _orders)
  {
    if(o.get_state() == Mice::Order::FILLED)
    {
      s += o.to_string();
      s += "\n\n";
    }
  }

  Gtk::MessageDialog dialog{*this, s};
  dialog.set_title(title);

  dialog.run();
  dialog.close();

}
