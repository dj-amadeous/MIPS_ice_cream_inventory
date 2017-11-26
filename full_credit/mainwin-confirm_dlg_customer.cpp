#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::on_show_order_click()
{
  int confirmation;
  std::string array_of_order_str;
  int array_of_order;
  int WIDTH = 15;
  Gtk::Dialog dialog;
  dialog.set_transient_for(*this);
  dialog.set_title("Pick an order number");

  //make combo box for displaying orders
  Gtk::HBox b_orders;
  Gtk::Label l_orders{"Order Numbers:"};
  Gtk::ComboBoxText c_orders;
  c_orders.set_size_request(WIDTH);


  //make a loop to display all orders
  //TODO have the loop look up orders that only match customers phone number
  for(Mice::Order o : _orders)
  {
    c_orders.append(std::to_string(o.order_num()));
  }

  b_orders.pack_start(c_orders, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_orders, Gtk::PACK_SHRINK);

  dialog.add_button("Cancel", 0);
  dialog.add_button("OK", 1);
  dialog.show_all();

  confirmation = dialog.run();
  //dialog.close();
//get the order number from the dialog, and pass it to the customer dialog
  if(confirmation == 1)
  {
    array_of_order_str = c_orders.get_active_text();
    array_of_order = std::stoi(array_of_order_str);
    array_of_order--;
    confirm_dlg_customer(_orders[array_of_order]);
  }
  else
  {
    dialog.close();
  }
  dialog.close();
}
