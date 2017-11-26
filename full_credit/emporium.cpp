#include "emporium.h"
#include <iostream>

namespace Mice{
  Emporium::Emporium(
    std::string branch_name,
    std::vector<Container>& containers,
    std::vector<Scoop>& scoops,
    std::vector<Topping>& toppings,
    std::vector<Order>& orders,
    std::vector<Server>& servers,
    double cash_register,
    double spent_on_servers,
    double revenue,
    double spent_on_stock) : _containers{containers},
        _scoops{scoops},
        _toppings{toppings},
        _orders{orders},
        _servers{servers},
        _cash_register{cash_register},
        _branch_name{branch_name},
        _revenue{revenue},
        _spent_on_servers{spent_on_servers},
        _spent_on_stock{spent_on_stock} {}

  void Emporium::decrement_quantity_topping(int which_topping, int numDecrements)
  {
    _toppings[which_topping].consume(numDecrements);
  }
  void Emporium::decrement_quantity_container(int which_container, int numDecrements)
  {
    _containers[which_container].consume(numDecrements);
  }
  void Emporium::decrement_quantity_scoop(int which_scoop, int numDecrements)
  {
    _toppings[which_scoop].consume(numDecrements);
  }
  double Emporium::get_cash_register()
  {
    return _cash_register;
  }
  void Emporium::update_register_server_pay(Order order, int serverIndex)
  {
    //_cash_register += order.get_cost();
    //update it with server salary below here
    _cash_register -= (_servers[serverIndex].get_salary() * _servers[serverIndex].get_num_orders());

    //update quantities of every item below

    /*for(Mice::Serving s : order.servings())
    {
      s.container().consume();
      for(Mice::Scoop ss : s.scoops())
      {
        ss.consume();
      }
      for(Mice::Topping t : s.toppings())
      {
        t.consume();
      }
    }*/
  }
  void Emporium::update_register_cost(Order order)
  {
    _cash_register += order.get_cost();
  }
  std::string Emporium::name()
  {
    return _branch_name;
  }
  Order Emporium::get_order(int index)
  {
    return _orders[index];
  }
  void Emporium::add_order(Order order)
  {
    _orders.push_back(order);
  }
  Server Emporium::get_server(int index)
  {
    return _servers[index];
  }
  Scoop Emporium::get_scoops(int index)
  {
    return _scoops[index];
  }
  std::vector<Container> Emporium::containers() const
  {
    return _containers;
  }
  std::vector<Scoop> Emporium::scoops() const
  {
    return _scoops;
  }
  std::vector<Topping> Emporium::toppings() const
  {
    return _toppings;
  }
  std::vector<Server> Emporium::servers() const
  {
    return _servers;
  }
  void Emporium::restock_container(int which_container)
  {
    _containers[which_container].restock();
  }
  void Emporium::restock_scoops(int which_scoop)
  {
    _scoops[which_scoop].restock();
  }
  void Emporium::restock_toppings(int which_topping)
  {
    _toppings[which_topping].restock();
  }
  void Emporium::buy_inventory(double cost)
  {
    _cash_register -= cost;
    _spent_on_stock += cost;
  }
  void Emporium::update_register_employee_price(Server server)
  {
    _cash_register -= server.get_num_orders() * server.get_salary();
    _spent_on_servers += server.get_num_orders() * server.get_salary();
  }
  void Emporium::print_servers()
  {
    for(Server s : _servers)
    {
      std::cout << s.name() << std::endl;
      std::cout << s.get_num_orders() << std::endl;
    }
  }
  double Emporium::get_spent_on_stock()
  {
    return _spent_on_stock;
  }
  double Emporium::get_spent_on_servers()
  {
    return _spent_on_servers;
  }
  void Emporium::set_revenue(double price)
  {
    _revenue += price;
  }
  double Emporium::get_revenue()
  {
    return _revenue;
  }
}


//operator overload!
std::ostream& operator<<(std::ostream& es, const Mice::Emporium& emporium)
{
  for(Mice::Container c : emporium.containers())
  {
    es << c.name() << std::endl;
  }
  for(Mice::Scoop s : emporium.scoops())
  {
    es << s.name() << std::endl;
  }
  for(Mice::Topping t : emporium.toppings())
  {
    es << t.name() << std::endl;
  }
  return es;
}
