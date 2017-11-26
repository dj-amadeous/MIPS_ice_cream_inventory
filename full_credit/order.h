#ifndef _ORDER_H
#define _ORDER_H

#include "serving.h"
#include <vector>

namespace Mice
{
  class Order
  {
  public:
    Order(int server_id, int idNum, double cost = 0, int state = 1);
    void add_serving(Serving serving);
    std::vector<Serving> servings() const;
    Serving get_serving(int index) const;
    int order_num();
    void update_state();
    int get_state();
    double get_cost();
    int get_server_id();
    void order_canceled();
    std::string to_string();
    const static int UNFILLED = 1;
    const static int FILLED = 2;
    const static int PAID = 3;
    const static int CANCELED = 4;

  private:
    std::vector<Serving> _servings;
    double _cost;
    int _server_id;
    int _idNum; //this is the id number of the order NOT the server
    int _state;
  };
}

#endif
