#include <iostream>
// #include "iterator.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "tree.hpp"
// #include <vector>
// #include <iterator>
// #include <memory>
#include <stack>
#include <map>

// 10 10 10 10 10

// template <typename T>
// std::vector<int> resize_test(ft::vector<T> vector) {
//     std::vector<int> v;
// 	std::cout << v.size() << std::endl;
// 	std::cout << v.capacity() << std::endl;
//     vector.assign(99000000, 1);
//     vector.resize(50000000);
//     vector.reserve(50000000);
// 	std::cout << v.size() << std::endl;
// 	std::cout << v.capacity() << std::endl;
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
// 	std::cout << v.size() << std::endl;
// 	std::cout << v.capacity() << std::endl;
//     vector.resize(70000000);
// 	std::cout << v.size() << std::endl;
// 	std::cout << v.capacity() << std::endl;
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(153000000, T());
// 	std::cout << v.size() << std::endl;
// 	std::cout << v.capacity() << std::endl;
// 	v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     v.push_back(vector[65]);
// 	std::cout << v.size() << std::endl;
// 	std::cout << v.capacity() << std::endl;
// 	std::cout << v.size() << std::endl;
// 	std::cout << v.capacity() << std::endl;
//     return v;
// }


int main(void) {
	// ft::stack<ft::vector<int> > st;
	// std::stack<int, ft::vector<int> > stack;

	// std::vector<int> v;
	// std::map<int, int>::iterator it;


	
	
	
	
	
	// int myints[] = {16,2,77,29, 35, 102, 44, 87, 112};
	// ft::vector<int> v1(5, 10);
	// ft::vector<int> v1(myints, myints + 4);
	// ft::vector<int> v2(myints + 4, myints + 9);

	// std::cout << *v1.begin() << std::endl;
	// std::cout << *(v1.end() - 1) << std::endl;
	// std::cout << *v2.begin() << std::endl;
	// std::cout << *(v2.end() - 1) << std::endl;
	// std::cout << v1.size() << std::endl;
	// std::cout << v1.capacity() << std::endl;
	// std::cout << v2.size() << std::endl;
	// std::cout << v2.capacity() << std::endl;
	// v1.swap(v2);
	// ft::vector<int>::iterator it1;
	// it1 = v1.begin();
	// while (it1 != v1.end()) {
	// 	std::cout << *it1 << " ";
	// 	it1++;
	// }

	// std::cout << std::endl;
	// ft::vector<int>::iterator it2;
	// it2 = v2.begin();
	// while (it2 != v2.end()) {
	// 	std::cout << *it2 << " ";
	// 	it2++;
	// }
	// std::cout << v1.size() << std::endl;
	// std::cout << v1.capacity() << std::endl;
	// std::cout << v2.size() << std::endl;
	// std::cout << v2.capacity() << std::endl;
	// std::cout << std::endl;
	// std::cout << "size: " << v1.size() << std::endl;
	// std::cout << "capacity: " << v1.capacity() << std::endl;
	// v2.pop_back();
	// v2.pop_back();
	// ft::vector<int>::iterator it1;
	// it1 = v2.begin();
	// v2.erase(it1 + 2);
	// v2.erase(it1, it1 + 2);
	// while (it1 != v2.end()) {
	// 	std::cout << *it1 << " ";
	// 	it1++;
	// }
	// for (int i = 0; i < 10; ++i) 
	// 	std::cout << v1[i] << std::endl;
	
	// ft::vector<int>::const_iterator cit_b;
	// ft::vector<int>::const_iterator cit_e;
	
	// ft::vector<int>::reverse_iterator rit_b;
	// ft::vector<int>::reverse_iterator rit_e;
	
	// ft::vector<int>::iterator it_b;
	// ft::vector<int>::iterator it_e;

	// std::cout << "vector #1: " << " ";
	// rit_b = v1.rbegin();
	// rit_e = v1.rend();
	// while (rit_b != rit_e) {
	// 	std::cout << *rit_b << " ";
	// 	rit_b++;
	// }
	// std::cout << std::endl;
	// std::cout << "vector #2: " << " ";
	// rit_b = v2.rbegin();
	// rit_e = v2.rend();
	// while (rit_b != rit_e) {
	// 	std::cout << *rit_b << " ";
	// 	rit_b++;
	// }
	// swap(v1, v2);
	// std::cout << std::endl << "swapping ..." << std::endl;
	// std::cout << "vector #1: " << " ";
	// rit_b = v1.rbegin();
	// rit_e = v1.rend();
	// while (rit_b != rit_e) {
	// 	std::cout << *rit_b << " ";
	// 	rit_b++;
	// }
	// std::cout << std::endl;
	// std::cout << "vector #2: " << " ";
	// rit_b = v2.rbegin();
	// rit_e = v2.rend();
	// while (rit_b != rit_e) {
	// 	std::cout << *rit_b << " ";
	// 	rit_b++;
	// }

	// std::cout << std::endl;
	// std::cout << std::endl << std::boolalpha << "vector #1 < vector #2: " << (v1 < v2) << std::endl;
	// std::cout << std::boolalpha << "vector #1 <= vector #2: " << (v1 <= v2) << std::endl;
	// std::cout << std::boolalpha << "vector #1 > vector #2: " << (v1 > v2) << std::endl;
	// std::cout << std::boolalpha << "vector #1 >= vector #2: " << (v1 >= v2) << std::endl;
	// std::cout << std::boolalpha << "vector #1 == vector #2: " << (v1 == v2) << std::endl;
	// std::cout << std::boolalpha << "vector #1 != vector #2: " << (v1 != v2) << std::endl;
	// std::cout << std::endl;
	// std::cout << std::boolalpha << "lexicographical_compare (vector #1 & vector #2): "
	// 	<< lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
	// std::cout << std::endl;
	// std::cout << "is_integral<int> == " << std::boolalpha << ft::is_integral<int>::value << std::endl;
	// std::cout << "is_integral<float> == " << std::boolalpha << ft::is_integral<float>::value << std::endl;
	// std::cout << "is_integral<vector> == " << std::boolalpha << ft::is_integral< ft::vector<int> >::value << std::endl;
	// it_b = v2.begin();
	// it_e = v2.end();
	// while (it_b != it_e) {
	// 	std::cout << *it_b << " ";
	// 	it_b++;
	// }
	// std::cout << std::endl;
	// std::cout << "size: " << v2.size() << std::endl;
	// std::cout << "capacity: " << v2.capacity() << std::endl;
	// v2.push_back(200);
	// v2.insert(it_b + 2, 4, 10);
	// std::cout << "size: " << v2.size() << std::endl;
	// std::cout << "capacity: " << v2.capacity() << std::endl;
	// it_b = v2.begin();
	// it_e = v2.end();
	// while (it_b != it_e) {
	// 	std::cout << *it_b << " ";
	// 	it_b++;
	// }
	return 0;
}