#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

void Mainwin::generate_report_profit(Mice::Emporium branch)
{
  double profit = branch.get_revenue() - branch.get_spent_on_servers() - branch.get_spent_on_stock();
  //generate the report
  Glib::ustring s = "Spent Servers \t Spent Inventory \t Profit\n";
  s += std::to_string(branch.get_spent_on_servers()) + " \t" + std::to_string(branch.get_spent_on_stock()) + "\t " + std::to_string(profit);

  Gtk::MessageDialog dialog(*this, s);

  dialog.run();
}
