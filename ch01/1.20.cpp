#include <iostream>
#include "../include/Sales_item.h"

int main_in_si() {
  Sales_item item;
  //输入，如：0-201-12345-X 3 20.00
  while (std::cin >> item)
    //输出，如：0-201-12345-X 3 60 20
    std::cout << item << std::endl;

  return 0;
}
