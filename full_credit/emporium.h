#ifndef _EMPORIUM_H
#define _EMPORIUM_H

#include "server.h"
#include "order.h"
#include <string>

namespace Mice
{

  class Emporium
  {
  public:
    Emporium(
      std::string branch_name,
      std::vector<Container>& containers,
      std::vector<Scoop>& scoops,
      std::vector<Topping>& toppings,
      std::vector<Order>& orders,
      std::vector<Server>& servers,
      double cash_register = 0,
      double revenue = 0,
      double spent_on_servers = 0,
      double spent_on_stock = 0);

    //I can't decrement quantity on emporium unless I pass it references
    //so I can just pass it references to my objects that should be decrementing
    void decrement_quantity_topping(int which_topping, int numDecrements); //I'm not sure if I want these here, or up on mainwin
    void decrement_quantity_scoop(int which_scoop, int numDecrements);
    void decrement_quantity_container(int which_container, int numDecrements);
    void add_order(Order order);
    std::string name();
    std::vector <Container> containers() const;
    std::vector <Scoop> scoops() const;
    std::vector <Topping> toppings() const;
    std::vector <Server> servers() const;
    Order get_order(int index);
    Server get_server(int index);
    Scoop get_scoops(int index);

    void restock_container(int which_container);
    void restock_scoops(int which_scoop);
    void restock_toppings(int which_topping);


    //void get_quantity(); //I'm not sure if I really need this
    void update_register_server_pay(Order order, int serverIndex);
    double get_cash_register();
    void update_register_cost(Order order);
    void update_register_employee_price(Server server);
    void buy_inventory(double cost);
    double get_spent_on_stock();
    double get_spent_on_servers();
    void set_revenue(double cost);
    double get_revenue();
    //void pay_servers(int serverIndex, double pay);
    //this is the outline for the potential methods I want to have on emporium.h
    //I need to put references to the objects in?
    void print_servers(); //TESTING SERVERS


  private:
    std::string _branch_name;
    double& _cash_register;
    std::vector<Container>& _containers;
    std::vector<Scoop>& _scoops;
    std::vector<Topping>& _toppings;
    //I may need both of these?
    std::vector<Order>& _orders; // this one is questionable as to whether I need it or not
    //Order& _order; //it's very likely it shoudl be this, where I just pass a single order once it's paid
    std::vector<Server>& _servers; //this is most likely necessary
    double _spent_on_servers;
    double _revenue;
    double _spent_on_stock;
  };

}
//operator overload!
std::ostream& operator<<(std::ostream& es, const Mice::Emporium& emporium);

#endif
