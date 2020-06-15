#include <iostream>

template<class A>
bool gt(A lhs,A rhs) {

	return lhs - rhs > 0;
}


using std::cout;
using std::endl;

//using if statement
int main_if_stmt() {
	if (int ret = gt(2, 4)) {
		cout << "greater than" << endl;
	}else
		cout << "less than or equal to" << endl;

	return 0;
}

//initializer_list
//RAII: Resource Acquisition Is Initialization
class Vector {
	int size;
	double * buf;

public:
	//lst.size() size_t type, cast needed
	Vector(std::initializer_list<double> lst) : buf(new double[lst.size()]), size{ static_cast<int>(lst.size()) } {
		//init every element in lst
		std::copy(lst.begin(), lst.end(), buf);
	}

	~Vector(){
		delete[] buf;
	}
};

class Vector_s :public Vector {

};

//4.5 Class Hierarchies
int main() {
	Vector vec = { 1,3,4,5 };

	//convert to specific type from given type, nullptr if failed
	//Vector_s * vs = dynamic_cast<Vector_s*>(vp);//polymorphical
	//Vector_s & vs = dynamic_cast<Vector_s&>(vp);//std::bad_cast exception if failed
	return 0;
}