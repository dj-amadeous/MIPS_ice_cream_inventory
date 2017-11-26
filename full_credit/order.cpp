#include "order.h"
#include <iostream>

namespace Mice
{
  Order::Order(int server_id, int idNum, double cost, int state) : _cost{cost}, _idNum{idNum}, _state{state}, _server_id{server_id} {}
  void Order::add_serving(Serving serving)
  {
    _servings.push_back(serving);
    _cost += serving.price();
    return;
  }

  std::vector<Serving> Order::servings() const
  {
    return _servings;
  }

  Serving Order::get_serving(int index) const
  {
    return _servings[index];
  }
  double Order::get_cost()
  {
    return _cost;
  }
  int Order::order_num()
  {
    return _idNum;
  }
  int Order::get_state()
  {
    return _state;
  }
  void Order::update_state()
  {
    _state++;
  }
  void Order::order_canceled()
  {
    _state = 4;
  }
  int Order::get_server_id()
  {
    return _server_id;
  }
  std::string Order::to_string()
  {
    std::string stateval;
    if(_state == UNFILLED)
    {
      stateval = "Unfilled";
    }
    else if(_state == FILLED)
    {
      stateval = "Filled";
    }
    else if(_state == PAID)
    {
      stateval = "Paid";
    }
    else if (_state == CANCELED)
    {
      stateval = "Canceled";
    }
    std::string return_val;
    return_val = "Server ID: " + std::to_string(_server_id) + "\n";
    return_val += "Order ID: " + std::to_string(_idNum) + "\n";
    return_val += "State: " + stateval + "\n";
    return_val += "Cost: " + std::to_string(_cost) + "\n";

    return return_val;
  }
}
