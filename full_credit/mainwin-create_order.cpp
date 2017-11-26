#include "mainwin.h"
#include <iostream>
#include <stdexcept>
#include <iostream>

Mice::Order Mainwin::create_order()
{
  //I need branch info to iterate the cash register
  int which_branch = select_branch();
  //HERE I account for the cost of the server on the order
  //if(which_branch != -1)
  //{
    int server_id = select_server();
    _servers[server_id].iterate_num_orders();
    _emporiums[which_branch].update_register_employee_price(_servers[server_id]);
    _servers[server_id].set_cash();
    Mice::Order order(server_id, whichOrderIsIt + 1);
    return order;
  //}
  /*Mice::Order order;
  return order;*/


}
