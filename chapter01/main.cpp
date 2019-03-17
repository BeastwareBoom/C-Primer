#include <iostream>

//using namespace std;
int main() {

    int v1=0,v2=0;
    //string literal
    std::cout<<"Please input the numbers:"<<std::endl;
    std::cin>>v1>>v2;
//    std::cout<<"Please input the second num:"<<std::endl;
//    std::cin>>v2;

    std::cout<<"Numbers are: "<<v1<<","<<v2<<std::endl;

    return EXIT_SUCCESS;
#if false
    std::cout << "Hello, World!" << std::endl;
    std::cerr << "Hello, cerr!" << std::endl;
    std::clog << "Hello, clog!" << std::endl;
    return EXIT_SUCCESS;//0
//    return EXIT_FAILURE;//1
//    return -1;

#endif
}