#include "mainwin.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


void Mainwin::on_progress_order_click()
{

  int confirmation;
  std::string selection;
  ///////////////
  // select which type of progress
  Gtk::Dialog dialog_type_order{"Select Which Progress Type", *this};
  const int WIDTH = 15;

  Gtk::HBox b_type;

  Gtk::Label l_type{"Progress Type:"};
  l_type.set_width_chars(WIDTH);
  b_type.pack_start(l_type, Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_type;
  c_type.set_size_request(WIDTH*10);
  const int UNFILLEDtoFILLED = 0;
  c_type.append("Unfilled->Filled");
  const int FILLEDtoPAID = 1;
  c_type.append("Filled->Paid");
  const int UNFILLEDtoPAID = 2;
  c_type.append("Unfilled->canceled");
  b_type.pack_start(c_type, Gtk::PACK_SHRINK);

  dialog_type_order.get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

  //show the dialog for picking which progress order
  dialog_type_order.add_button("Cancel", 0);
  dialog_type_order.add_button("OK", 1);
  dialog_type_order.show_all();
  if(dialog_type_order.run() != 1)
  {
    dialog_type_order.close();
    return;
  }

  int type = c_type.get_active_row_number();

  dialog_type_order.close();


  Gtk::Dialog dialog;
  dialog.set_transient_for(*this);


  Gtk::HBox b_orders;

  Gtk::Label l_orders{"Order Nums:"};
  b_orders.pack_start(l_orders, Gtk::PACK_SHRINK);
  Gtk::ComboBoxText c_orders;
  c_orders.set_size_request(WIDTH);

//display only relevant orders
  if(type == UNFILLEDtoFILLED)
  {
    dialog.set_title("List of Unfilled Orders");
    for(Mice::Order o : _orders)
    {
      if(o.get_state() == Mice::Order::UNFILLED)
      {
        c_orders.append(std::to_string(o.order_num()));
      }
    }
  }
  else if (type == FILLEDtoPAID)
  {
    dialog.set_title("List of Filled Orders");
    for(Mice::Order o : _orders)
    {
      if(o.get_state() == Mice::Order::FILLED)
      {
        c_orders.append(std::to_string(o.order_num()));
      }
    }
  }
  else
  {
    dialog.set_title("List of Unfilled Orders");
    for(Mice::Order o : _orders)
    {
      if(o.get_state() == Mice::Order::UNFILLED)
      {
        c_orders.append(std::to_string(o.order_num()));
      }
    }
  }
  b_orders.pack_start(c_orders, Gtk::PACK_SHRINK);
  dialog.get_vbox()->pack_start(b_orders, Gtk::PACK_SHRINK);




  //buttons and hsow dialog for testing
  dialog.add_button("Cancel", 0);
  dialog.add_button("OK", 1);
  dialog.show_all();

  int select_to_text;
  confirmation = dialog.run();

  if(confirmation == 1)
  {
    selection = c_orders.get_active_text();
    select_to_text = std::stoi(selection);
    select_to_text--;
    int select_a_branch = select_branch();
    //update the state of the order
    if(type == UNFILLEDtoFILLED)
    {
      _orders[select_to_text].update_state();
      _emporiums[select_a_branch].update_register_server_pay(_orders[select_to_text], _orders[select_to_text].get_server_id()); // the first argument is a branch, the second argument is the server associated with this order
      //I'm making this act on the emporium branch version of _servers because I want to be able to extend it to accomodate multiple branches in the future
    Mice::Server& server_for_order = _emporiums[select_a_branch].servers()[_orders[select_to_text].get_server_id()];
    server_for_order.set_cash();

    }
    else if (type == FILLEDtoPAID)
    {
      _orders[select_to_text].update_state();
      _emporiums[select_a_branch].update_register_cost(_orders[select_to_text]);
    }
    else
    {
      _orders[select_to_text].order_canceled();
    }
  }
  else
  {
    dialog.close();
    return;
  }
  dialog.close();
  return;
}
