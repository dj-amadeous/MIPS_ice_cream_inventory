#include "test_item.h"
#include "test_container.h"
#include "test_scoop.h"
#include "test_topping.h"
#include "test_order.h"
#include "test_emporium.h"
#include <iostream>

int main() {
  if (!(test_item() &&
        test_container() &&
        test_scoop() &&
        test_topping() &&
        test_order()  &&
        test_emporium()))

        std::cout << test_emporium() << std::endl;
    std::cerr << "fail" << std::endl;
}
