#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

Mice::Serving Mainwin::create_serving() {
    int container = select_container();
    if (container == -1) throw std::runtime_error("Canceled");

    Mice::Serving serving{_containers[container]};
    _containers[container].consume();

    bool has_no_scoops = true;
    for (int i=0; i<_containers[container].max_scoops(); ++i) {
        int scoop = select_scoop();
        if (scoop == -1) break;
        serving.add_scoop(_scoops[scoop]);
        _scoops[scoop].consume();
        has_no_scoops = false;
    }
    if (has_no_scoops) throw std::runtime_error("Canceled");

    while (true) {
        int topping = select_topping();
        if (topping == -1) break;
        else
        {
          serving.add_topping(_toppings[topping]);
          _toppings[topping].consume();
        }
    }

    return serving;
}
