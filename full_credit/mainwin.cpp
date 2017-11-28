#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>

Mainwin::Mainwin()
{
  whichOrderIsIt = 0;
    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //
    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   E M P O R I U M
    // (Owner) “Create a New Emporium” Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Emporium", true));
    menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_new_emporium_click));
    filemenu->append(*menuitem_new);

    //          TEST ADD NEW PICTURE
    Gtk::MenuItem *menuitem_pic = Gtk::manage(new Gtk::MenuItem("_New Picture", true));
    menuitem_pic->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_add_picture_click));
    filemenu->append(*menuitem_pic);

    //         E A S T E R   E G G
    // (TODO: Test Only) “Create a New Emporium” Append Easter Egg to the File menu
    Gtk::MenuItem *menuitem_easteregg = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
    menuitem_easteregg->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_easteregg_click));
    filemenu->append(*menuitem_easteregg);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //
    //     C R E A T E
    // Create a Create menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //         O R D E R
    // (All) “Create Delicious Ice Cream Treats” Append Order to the Create menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order...", true));
    menuitem_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    createmenu->append(*menuitem_order);

    //         C U S T O M E R
    // (Server, Manager, Owner) “Create a New Customer” Append Customer to the Create menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer...", true));
    menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_customer_click));
    createmenu->append(*menuitem_customer);

    //        M A N A G E R
    //create a new named manager
    Gtk::MenuItem *menuitem_man_create = Gtk::manage(new Gtk::MenuItem("_Manager...", true));
    menuitem_man_create->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_man_click));
    createmenu->append(*menuitem_man_create);

    //         I T E M
    // (Owner, Manager) “Create a New Container, Ice Cream Flavor, or Topping” Append Item to the Create menu
    Gtk::MenuItem *menuitem_item = Gtk::manage(new Gtk::MenuItem("_Item...", true));
    menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    createmenu->append(*menuitem_item);

    //         S E R V E R
    // (Owner, Manager) “Add a New Employee” Append Server to the Create menu
    Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server...", true));
    menuitem_server->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_server_click));
    createmenu->append(*menuitem_server);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    helpmenu->append(*menuitem_about);

    //      M A N A G E R     M E N U
    //create a manager menu for various manager tasks
    Gtk::MenuItem *menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager", true));
    menubar->append(*menuitem_manager);
    Gtk::Menu *managermenu = Gtk::manage(new Gtk::Menu());
    menuitem_manager->set_submenu(*managermenu);

    //            P R O G R E S S   O R D E R
    //progress order to next stage
    Gtk::MenuItem *menuitem_prog = Gtk::manage(new Gtk::MenuItem("_Next Stage Order", true));
    menuitem_prog->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_progress_order_click));
    managermenu->append(*menuitem_prog);

    //          G E N E R A T E     R E P O R T
    //generate a report of the branch
    Gtk::MenuItem *menuitem_gen = Gtk::manage(new Gtk::MenuItem("_Generate report", true));
    menuitem_gen->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_generate_report_profit_click));
    managermenu->append(*menuitem_gen);

    //          G E N E R A T E   INV R E P O R T
    //generate a report of all the inventory
    Gtk::MenuItem *menuitem_inv = Gtk::manage(new Gtk::MenuItem("_Inventory report", true));
    menuitem_inv->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_inv_report_click));
    managermenu->append(*menuitem_inv);

    //          C H A N G E   S E R V E R   S A L A R Y
    //generate a report of the branch
    Gtk::MenuItem *menuitem_sal = Gtk::manage(new Gtk::MenuItem("_Change Server Salary", true));
    menuitem_sal->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_change_server_salary_click));
    managermenu->append(*menuitem_sal);

    //edit flavor
    Gtk::MenuItem *menuitem_flav = Gtk::manage(new Gtk::MenuItem("_Edit a Flavor", true));
    menuitem_flav->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_edit_flavor_click));
    managermenu->append(*menuitem_flav);

    //edit topping
    Gtk::MenuItem *menuitem_topping = Gtk::manage(new Gtk::MenuItem("_Edit a Topping", true));
    menuitem_topping->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_edit_topping_click));
    managermenu->append(*menuitem_topping);

    //edit container
    Gtk::MenuItem *menuitem_container = Gtk::manage(new Gtk::MenuItem("_Edit a Container", true));
    menuitem_container->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_edit_container_click));
    managermenu->append(*menuitem_container);

    //          D I S P L A Y   S E  R V E R   R E P O R T
    //displays a report of all servers
    Gtk::MenuItem *menuitem_report = Gtk::manage(new Gtk::MenuItem("_Display Server Report", true));
    menuitem_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_display_server_report_click));
    managermenu->append(*menuitem_report);
    // DISPLAY CUSTOMER REPORT
    Gtk::MenuItem *menuitem_cust_report = Gtk::manage(new Gtk::MenuItem("_Display Customer Report", true));
    menuitem_cust_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_generate_cust_report_click));
    managermenu->append(*menuitem_cust_report);

    // DISPLAY ORDER REPORT
    Gtk::MenuItem *menuitem_order_report = Gtk::manage(new Gtk::MenuItem("_Display order report", true));
    menuitem_order_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_display_order_report_click));
    managermenu->append(*menuitem_order_report);

    //      C U S T O M E R
    //create a customer menu
    Gtk::MenuItem *menuitem_custMenu = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menubar->append(*menuitem_custMenu);
    Gtk::Menu *customermenu = Gtk::manage(new Gtk::Menu());
    menuitem_custMenu->set_submenu(*customermenu);

    //      S H OW    O R D E R
    //show all the servings in an order, and prices in an order for the customer
    Gtk::MenuItem *menuitem_show = Gtk::manage(new Gtk::MenuItem("_Show Order and Price", true));
    menuitem_show->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_show_order_click));
    customermenu->append(*menuitem_show);

    //      S E R V E R      M E N U
    // generate a server menu
    Gtk::MenuItem *menuitem_servMenu = Gtk::manage(new Gtk::MenuItem("_Server", true));
    menubar->append(*menuitem_servMenu);
    Gtk::Menu *servermenu = Gtk::manage(new Gtk::Menu());
    menuitem_servMenu->set_submenu(*servermenu);

    //     R E S T O C K    I T E M
    //option for restocking an item
    Gtk::MenuItem *menuitem_restock = Gtk::manage(new Gtk::MenuItem("_Restock an Item", true));
    menuitem_restock->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_restock_item_click));
    servermenu->append(*menuitem_restock);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     N E W   E M P O R I U M
    // Add a new emporium icon
    Gtk::ToolButton *new_emporium_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_emporium_button->set_tooltip_markup("Create a New Emporium");
    new_emporium_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_new_emporium_click));
    toolbar->append(*new_emporium_button);

    //     C R E A T E   O R D E R
    // Add a Create Order icon
    Gtk::Image *create_order_button_image = Gtk::manage(new Gtk::Image("new_order.png"));
    Gtk::ToolButton *create_order_button = Gtk::manage(new Gtk::ToolButton(*create_order_button_image));
    create_order_button->set_tooltip_markup("Create a new order");
    create_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    toolbar->append(*create_order_button);

    //     C R E A T E   C R E A T E   I T E M
    // Add a Create Item icon
    Gtk::Image *create_item_button_image = Gtk::manage(new Gtk::Image("create_item.png"));
    Gtk::ToolButton *create_item_button = Gtk::manage(new Gtk::ToolButton(*create_item_button_image));
    create_item_button->set_tooltip_markup("Create a new item");
    create_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    toolbar->append(*create_item_button);

    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit MICE");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    hide();
}

// void Mainwin::on_about_click() {
// }

void Mainwin::on_create_order_click() {
  Mice::Order order = create_order();
  int branch_num = select_branch();
    try {
        bool createNewServQuestion = true;
        while(createNewServQuestion)
        {
          Mice::Serving serving = create_serving();
          _servings.push_back(serving);
          _orders.push_back(order);
          std::cout << serving << std::endl;  // TODO: Temporary - replace with confirmation dialog: DONE!
          _orders[whichOrderIsIt].add_serving(serving);
          createNewServQuestion = new_serv_dlg();
        }
        confirm_dlg_order(_orders[whichOrderIsIt]); //I have to pass an order to this in order to use it
        _emporiums[branch_num].set_revenue(_orders[whichOrderIsIt].get_cost());
    } catch(std::runtime_error e) { // User canceled order
    }
    whichOrderIsIt++;
    std::cout << "The revenue is " << std::to_string(_emporiums[branch_num].get_revenue()) << std::endl;
}

void Mainwin::on_easteregg_click() {
        _containers.push_back(
            Mice::Container{"Cone", "Crispy airy delight", 0.25, 0.50, 2});
        _containers.push_back(
            Mice::Container{"Waffle Cone", "Crunchy wrapped waffle cake", 0.35, 0.75, 3});
        _scoops.push_back(
            Mice::Scoop{"Chocolate", "Rich smooth chocolate ice cream", 0.20, 0.50});
        _scoops.push_back(
            Mice::Scoop{"Vanilla", "Real vanilla bean ice cream", 0.20, 0.50});
        _scoops.push_back(
            Mice::Scoop{"Strawberry", "Chunks of strawberry wrapped in vanilla ice cream", 0.20, 0.50});
        _toppings.push_back(
            Mice::Topping{"Cherry", "Classic marichino cherry", 0.1, 0.2, 0});
        _toppings.push_back(
            Mice::Topping{"Chocolate Sauce", "Rich thick chocolate", 0.1, 0.25, 0});
        _toppings.push_back(
            Mice::Topping{"Whipped Cream", "Real sweet cream whipped to perfection", 0.1, 0.2, 0});
        _servers.push_back(
          Mice::Server{"Kyra Belgica", 1, "6843864888", 10.25});
        _servers.push_back(
          Mice::Server{"Evan Cornish", 1, "6834868346", 9.25});
        _emporiums.push_back(
          Mice::Emporium{"Branch 1", _containers, _scoops, _toppings, _orders, _servers});
        _customers.push_back(
          Mice::Customer{"George Rice", 1, "8888888888"});
        _customers.push_back(
          Mice::Customer{"Nora Red", 2, "9999999999"});



          std::cout << _emporiums[0] << std::endl; //overloaded << operator

        // Display acknowledgement
        Gtk::MessageDialog dialog{*this, "Added 2 containers, 3 scoops, 3 toppings, 1 branch, 2 customers, and 2 servers"};
        dialog.run();
        dialog.close();
 }

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this);
    dialog.set_program_name("Mav's Ice Cream Emporium");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Sprint 2");
    dialog.set_copyright("Copyright 2017");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice, Evan G. Cornish, Kyra Belgica"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"Logo by Schmidsi, https://pixabay.com/en/ice-ice-cream-cone-ice-ball-pink-1429596/",
                                            "Ice Cream Cone by Patrick Trouvé from the Noun Project, https://thenounproject.com/term/ice-cream-cone/63026/"};
    dialog.set_artists(artists);
    dialog.run();
}
void Mainwin::on_generate_report_profit_click()
{
  int branch_num = select_branch();
  if(branch_num != -1)
  {
    generate_report_profit(_emporiums[branch_num]);
  }


}

void Mainwin::on_restock_item_click()
{
  const int CONTAINER = 0;
  const int SCOOP = 1;
  const int TOPPING = 2;
  int full_restock = 25;
  double cost;
  int server_index = select_server();
  int branch_num = select_branch();
  //Mice::Item type_item;

  if(branch_num != -1) // error checking select_branch didn't hit cancel
  {
    int type_item = select_item_restock();
    if(type_item == CONTAINER)
    {
      //Mice::Container restock_container;
      int container_index = select_container();
      double cost = (full_restock - _containers[container_index].quantity()) * _containers[container_index].price();
      _containers[container_index].restock();
      _emporiums[branch_num].buy_inventory(cost);
      _servers[server_index].update_num_orders_restock();//**** DIFFERENCE ****///
    }
    else if(type_item == SCOOP)
    {
      int scoop_index = select_scoop();
      double cost = (full_restock - _scoops[scoop_index].quantity()) * _scoops[scoop_index].price();
      _scoops[scoop_index].restock();
      _emporiums[branch_num].buy_inventory(cost);
      _servers[server_index].update_num_orders_restock();//**** DIFFERENCE ****///

    }
    else if(type_item == TOPPING)
    {
      int topping_index = select_topping();
      double cost = (full_restock - _toppings[topping_index].quantity()) * _toppings[topping_index].price();
      _toppings[topping_index].restock();
      _emporiums[branch_num].buy_inventory(cost);
      _servers[server_index].update_num_orders_restock();//**** DIFFERENCE ****///
    }
    //update server info on branch
    _emporiums[branch_num].update_register_employee_price(_servers[server_index]);
    _servers[server_index].set_cash();
  }
}
void Mainwin::on_inv_report_click()
{
  inv_report();
}
void Mainwin::on_display_order_report_click()
{
  order_dlg();
}
/*void Mainwin::on_display_cust_report_click()
{
  generate_cust_report()
}*/
