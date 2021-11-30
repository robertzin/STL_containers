#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <vector>
#include <typeinfo>

struct trivial {
    int val;
};

int main() {
	int myints[] = {16,2,77,29};
	std::vector<int> v(myints, myints + 4);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::vector<int>::iterator it;
	it = v.begin();
	v.erase(it, it + 2);
	while (it != v.end()) {
		std::cout << *it << " ";
		it++;
	}
	v.insert(v.begin(), 15);
	it = v.begin();
	while (it != v.end()) {
		std::cout << *it << " ";
		it++;
	}


	// for (int i = 0; i < 10; ++i) 
	// 	std::cout << v[i] << std::endl;
	return (0);
}


// clang++ -Wall -Wextra -Werror main.cpp -o main