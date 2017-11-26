#include "test_order.h"
#include "order.h"
#include "serving.h"
#include "container.h"
#include "scoop.h"
#include "topping.h"
#include <iostream>
#include <sstream>

bool test_order()
{
  std::string expected = "";
  bool passed = true;

  //create the container
  std::string x_name = "Waffle Cone";
  std::string x_description = "A dry, cone-shaped pastry with a waffle texture";
  double x_cost = 0.30;
  double x_price = 0.99;
  int x_max_scoops = 3;

  Mice::Container container{x_name, x_description, x_cost, x_price, x_max_scoops};

  //create the scoop
  std::string b_name = "Fudge Ripple";
  std::string b_description = "Chocolatey goodness in vanilla swirl";
  double b_cost = 0.75;
  double b_price = 1.50;

  Mice::Scoop scoop{b_name, b_description, b_cost, b_price};
  //create scoop 2
  std::string c_name = "Chocolate stuff";
  std::string c_description = "chocolate stuff in a cone";
  double c_cost = 0.75;
  double c_price = 1.50;

  Mice::Scoop scoopB{c_name, c_description, c_cost, c_price};

  //create toppings
  std::string d_name = "Maraschino Cherry";
  std::string d_description = "A sweet, plump cherry preserved in maraschino syrup";
  double d_cost = 0.10;
  double d_price = 0.50;
  int d_amount = Mice::Topping::EXTRA_AMOUNT;

  Mice::Topping topping{d_name, d_description, d_cost, d_price, d_amount};

  Mice::Serving serving{container};
  serving.add_scoop(scoop);
  serving.add_topping(topping);

  Mice::Order order;
  order.add_serving(serving);



  //std::cout << order.servings()[0] << "\n";
  return passed;
}
