#include <iostream>

template<class A>
bool gt(A lhs,A rhs) {

	return lhs - rhs > 0;
}


using std::cout;
using std::endl;

//using if statement
int main() {
	if (int ret = gt(2, 4)) {
		cout << "greater than" << endl;
	}else
		cout << "less than or equal to" << endl;

	return 0;
}