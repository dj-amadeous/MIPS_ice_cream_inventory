#include "test_emporium.h"
#include "emporium.h"
#include <iostream>

bool test_emporium()
{
  bool passed = true;
  int quantity_expected = 24;
  //create vectors
  double cash_register = 20;
  std::vector<Mice::Container> containers;
  std::vector<Mice::Scoop> scoops;
  std::vector<Mice::Topping> toppings;

  std::vector<Mice::Order> orders;
  std::vector<Mice::Server> servers;

  //make the objects and put them in
  //container
  std::string x_name = "Waffle Cone";
  std::string x_description = "A dry, cone-shaped pastry with a waffle texture";
  double x_cost = 0.30;
  double x_price = 0.99;
  int x_max_scoops = 3;
  Mice::Container container{x_name, x_description, x_cost, x_price, x_max_scoops};
  container.restock();
  containers.push_back(container);
  //scoops
  std::string b_name = "Fudge Ripple";
  std::string b_description = "Chocolatey goodness in vanilla swirl";
  double b_cost = 0.75;
  double b_price = 1.50;
  Mice::Scoop scoop{b_name, b_description, b_cost, b_price};
  scoop.restock();
  scoops.push_back(scoop);
  //toppings
  std::string c_name = "Maraschino Cherry";
  std::string c_description = "A sweet, plump cherry preserved in maraschino syrup";
  double c_cost = 0.10;
  double c_price = 0.50;
  int c_amount = Mice::Topping::EXTRA_AMOUNT;
  Mice::Topping topping{c_name, c_description, c_cost, c_price, c_amount};
  topping.restock();
  toppings.push_back(topping);
  //make the order with the serving
  Mice::Serving serving(containers[0]);
  serving.add_scoop(scoops[0]);
  serving.add_topping(toppings[0]);
  Mice::Order order;
  order.add_serving(serving);

  //servers
  //boolean because kyra forgot to set the default arguments
  bool active = true;
  double salary = 20;
  std::string d_name = "Kyra Belgica";
  std::string d_phone = "68438648";
  Mice::Server server(d_name, 1, d_phone, active, salary);
  servers.push_back(server);

  //finally test the actual emporium branch
  Mice::Emporium emporium(containers, scoops, toppings, orders, servers, cash_register);
  emporium.add_order(order);


  //do a mock order to decrement quantity
  //if you make a vector of scoops to pass to emporium, and you expect it to consume on the first go around
  //with the vector of servings, you have to make sure that you pass the vector of scoops to serving
  //as oppossed to the single scoop object. You must pass the scoop object from the vector!
  emporium.update_register(emporium.get_order(0), emporium.get_order(0).get_cost());
  //long test of the entire branch
  //if(emporium.)
  std::cout << emporium.get_scoops(0).quantity() << std::endl;
  //std::cout << scoops

  return passed;

}
