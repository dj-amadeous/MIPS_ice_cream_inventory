#ifndef MAINWIN_H
#define MAINWIN_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include "order.h"
#include "emporium.h"
#include "person.h"
#include "manager.h"
#include "server.h"
#include <gtkmm.h>
#include <string>

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        //void on_file_new_click();                   // Create a new Emporium
        void on_create_order_click();                 // Create a new order
        //void on_create_customer_click();            // Create a new customer
        void on_create_item_click();                  // Create a new item
        void on_new_emporium_click();
        void on_create_server_click();              // Create a new server
        void on_create_man_click();
        void on_about_click();                        // Display About dialog
        void on_quit_click();                         // Exit the program
        void on_easteregg_click();                    // TODO: For test only
        void on_progress_order_click();
        void on_show_order_click();                //customer show order
        void on_add_picture_click();                //working at testing the picture adding

        void confirm_dlg_customer(Mice::Order order);               //second method to pass to show order so I can pass arguments (couldn't figure out how to do this the "right" way)
        void confirm_dlg(Mice::Serving serving);   //confirmation dialog of order (Just serving for now)(change from passing serving to order in future)
        void confirm_dlg_order(Mice::Order order);
        bool new_serv_dlg();
        void generate_report_profit();
        void on_generate_report_profit_click();
        void on_restock_item_click();
        void generate_report_profit(Mice::Emporium);
        int choose_item_type();
        void on_change_server_salary_click();
        void on_display_server_report_click();
        void on_inv_report_click();
        void on_display_order_report_click();
        void inv_report();
        void order_dlg();
    private:
        //void create_order();                        // Create a new order
        Mice::Serving create_serving();             // Create a new serving
        Mice::Order create_order();                 // Create a new order
        int select_branch();                          // select a branch index
        int select_server();
        int select_container();                       // Select a container index
        int select_scoop();                           // Select a scoop index
        int select_topping();                         // Select a container index
        int select_item_restock();
        int select_from_vector
            (std::vector<std::string> names,
             std::string title);                      // Select from a list of strings
        void add_picture();

        int whichOrderIsIt;
        std::vector<Mice::Container> _containers;     // All defined containers
        std::vector<Mice::Scoop> _scoops;             // All defined scoops
        std::vector<Mice::Topping> _toppings;         // All defined toppings
        std::vector<Mice::Serving> _servings;         // All defined servings
        std::vector<Mice::Order> _orders;             // All defined orders
        std::vector<Mice::Server> _servers;           // All defined servers
        std::vector<Mice::Emporium> _emporiums;     // All defined emporiums
        std::vector<Mice::Manager> _managers;       //all defined managers
};
#endif
