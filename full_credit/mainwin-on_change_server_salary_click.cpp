#include "mainwin.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


void Mainwin::on_change_server_salary_click()
{

    int server_index;
    int WIDTH = 15;
    //select which server to change
    server_index = select_server();

    Gtk::Dialog dialog;
    dialog.set_title("Change Server Salary");
    dialog.set_transient_for(*this);
    Gtk::HBox b_salary;
    Gtk::Label l_salary{"New Salary:"};
    l_salary.set_width_chars(WIDTH);
    b_salary.pack_start(l_salary, Gtk::PACK_SHRINK);

    Gtk::Entry e_salary;
    e_salary.set_max_length(WIDTH*4);
    b_salary.pack_start(e_salary, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_salary, Gtk::PACK_SHRINK);

    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

    bool valid_data = false;
    double salary;

    while(!valid_data) {
      if (dialog.run() != 1) {
          dialog.close();
          return;
    }

    std::cout << _servers[server_index].name() << " was paid $"
              << _servers[server_index].get_salary() << " per hour." << std::endl;

    valid_data = true;
    try {
        salary = std::stod(e_salary.get_text());
    } catch(std::exception e) {
        e_salary.set_text("*** invalid salary ***");
        valid_data = false;
    }
    _servers[server_index].set_salary(salary);

    std::cout << _servers[server_index].name() + " now gets paid $"
              +  std::to_string(_servers[server_index].get_salary()) + " per hour.\n" << std::endl;

    dialog.close();
    }
}
