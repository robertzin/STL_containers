#include <iostream>
#include "iterator.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "tree.hpp"
#include "map.hpp"

int main(void) {

	ft::map<int, int> m;
	m.insert(ft::make_pair(10,10));
	m.insert(ft::make_pair(20,10));
	m.insert(ft::make_pair(30,10));
	m.insert(ft::make_pair(40,10));
	m.insert(ft::make_pair(50,10));
	ft::map<int, int>::iterator it = m.begin();
	ft::map<int, int>::reverse_iterator rit = m.rbegin();
	ft::map<int, int>::reverse_iterator rite = m.rend();

	std::cout << rit->first << "-> " << rit->second << std::endl;
	
	std::cout << m.max_size() << std::endl;

	// std::cout << rite->first << "-> " << rite->second << std::endl;

	// rit = m.rbegin(); rite = m.rend();
	// while (it != ite)
		// std::cout << "[rev] " << printPair(it++, false) << std::endl;
	// std::cout << rite->first << "-> " << rite->second << std::endl;


	// while (rite != rit) {
	// 	rite++;
	// 	std::cout << rite->first << "-> " << rite->second << std::endl;
	// }

	// while (3-- > 0) {
	// 	--it;
	// }
	// while (n-- > 0)
	// 	++it;
	// return (it);


	// rit--;
	// std::cout << it->first << std::endl;
	// std::cout << rit->first << std::endl;

	// ft::vector<int>::iterator ite = v.end();
	// ft::vector<int>::reverse_iterator rite = v.rend();


	// std::cout << v.size() << std::endl;

    // for (int i = 0, j = 0; i < 500000; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));

    // mp.erase(mp.begin(), --mp.end());
    // v.push_back(mp.begin()->first);

    // ft::vector<int>::iterator z = v.begin();
    // ft::vector<int>::iterator zz = v.end();

	// for (; z != zz; z++) {
	// 	std::cout << *z << " ";
	// }
	// std::cout << mp.size() << std::endl;

    // for (int i = 0, j = 0; i < 10 ; ++i, ++j)
    //     m.insert(ft::make_pair(i, j));
	// ft::map<int, int>::iterator it = m.begin();
	// ft::map<int, int>::iterator ite = m.end();
	// ite--;
	// for (; ite != it; ite--)
	// 	std::cout << ite->first << " / " << ite->second << std::endl;


	// std::cout << m.max_size() << std::endl;
	// std::cout << std::boolalpha << m.empty() << std::endl;
    // mp2.erase(2);
    // mp2.erase(7);
    // ft::map<int, int>::iterator it3 = mp2.begin();
    // for (; it3 != mp2.end(); ++it3) {
    //     v.push_back(it3->first);
    //     v.push_back(it3->second);
    // }

	// ft::vector<int> v;
	// ft::map<int, int> mp;
    // ft::map<int, int> mp2;
    // mp.insert(ft::make_pair(10, 10));
    // if (mp.lower_bound(11) == mp.end()) {
    //     v.push_back(1);
	// }

	// mp.insert(ft::make_pair(20, 20));
    // mp.insert(ft::make_pair(30, 30));
    // mp.insert(ft::make_pair(40, 40));
    // mp.insert(ft::make_pair(50, 50));
    // mp.insert(ft::make_pair(60, 60));

    // mp2.insert(ft::make_pair(10, 10));
	// if (mp2.lower_bound(1) == mp2.end())
    //     v.push_back(1);
	// mp2.insert(ft::make_pair(20, 20));
    // mp2.insert(ft::make_pair(30, 30));
    // mp2.insert(ft::make_pair(40, 40));
    // mp2.insert(ft::make_pair(50, 50));
    // mp2.insert(ft::make_pair(60, 60));
	// ft::map<int, int>::iterator it1 = mp.begin();
	// ft::map<int, int>::iterator it2 = mp2.begin();
	// for (ft::map<int, int>::iterator ite1 = mp.end(); it1 != ite1; it1++)
			// std::cout << it1->first << " / " << it1->second << std::endl;

	// std::cout << "for-loop" << std::endl;
	// ft::map<int, int>::iterator it;
    // for (int i = 1; i < 60; i += 10) {
    //     it = mp.lower_bound(i);
    //     v.push_back(it->first);
    // }

    // for (int i = 10; i < 70; i += 10) {
    //     it = mp2.lower_bound(i);
    //     v.push_back(it->first);
    // }

	// ft::vector<int>::iterator z = v.begin();
	// for (ft::vector<int>::iterator zz = v.end(); z != zz; z++)
	// 	std::cout << *(z) << " ";
	// // std::cout << "check_2" << std::endl;
	// ft::map<int, int> mp3;
    // for (int i = 0, j = 0; i < 500000; ++i, ++j) {
    //     mp3.insert(ft::make_pair(i, j));
    // }
    // mp3.lower_bound(490000);

	// ft::vector<ft::pair<std::string,double> > vN;

	// ft::map <int, int> l;

	// l.insert(ft::map<int, int>::value_type(12, 20));
	// l.insert(ft::map<int, int>::value_type(2, 30));
	// l.insert(ft::pair<int, int>(7, 25));
	// for (int i = 0, j = 0; i < 100000; ++i, ++j)
	// 	l.insert(ft::make_pair(i, j));
	// for (int i = 0; i < 43; ++i)
	// 	l.erase(i);
	// std::cout << l.size() << std::endl;

	// ft::map <int, int>::iterator beg = l.begin();
	// ft::map <int, int>::iterator end = l.end();

	// std::cout << (*beg).first << std::endl;
	// std::cout << (*end).second << std::endl;

	// ft::map<char,int> mymap;
	// ft::map<char,int>::iterator itlow,itup;
	// ft::map<char,int>::reverse_iterator rit;

	// mymap['a']=20;
	// mymap['b']=40;
	// mymap['c']=60;
	// mymap['d']=80;
	// mymap['e']=100;
	// itlow = mymap.begin();
	// rit = mymap.rbegin();
	// std::cout << "begin: " << itlow->first << " => " << itlow->second << '\n';
	// std::cout << "rbegin: " << rit->first << " => " << rit->second << '\n';
	// itlow = mymap.end();
	// rit = mymap.rend();
	// // std::cout << "end: " << itlow->first << " => " << itlow->second << '\n';
	// std::cout << "rend: " << rit->first << " => " << rit->second << '\n';


	// itlow = mymap.lower_bound ('b');  // itlow points to b
	// itup = mymap.upper_bound ('d');   // itup points to e (not d!)

	// std::cout << "first: " << itlow->first << " => " << itlow->second << '\n';
	// std::cout << "first: " << itup->first << " => " << itup->second << '\n';
	// for (ft::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it) {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// }


	// std::cout << "SIZE:" << std::endl;
	// std::cout << mymap.size() << std::endl;
	// mymap.erase(itlow,itup);        // erases [itlow,itup)
	// std::cout << mymap.size() << std::endl;
	// std::cout << "---xxx---" << std::endl;

	// std::cout << mymap.begin()->first << " / " << mymap.begin()->second << std::endl;
	// std::cout << mymap.rbegin()->first << " / " << mymap.rbegin()->second << std::endl;
	// std::cout << mymap.end()->second << std::endl;


	// print content:
	// for (ft::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it) {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// }

	// ft::map<int, int>::iterator beg = l.begin();
	// for (ft::map<int, int>::iterator end = l.end(); beg != end; beg++)
	// 	std::cout << (*beg).first << " / " << (*beg).second << std::endl;

	// std::cout << "reverse\n";
	// ft::map<int, int>::reverse_iterator rbeg = l.rbegin();
	// for (ft::map<int, int>::reverse_iterator rend = l.rend(); rbeg != rend; rbeg++)
	// 	std::cout << (*rbeg).first << " / " << (*rbeg).second << std::endl;

	// ft::map<std::string,double>::reverse_iterator rbeg = l.rbegin();
	// ft::map<std::string,double>::reverse_iterator rend = l.rend();
	// std::cout << (*rbeg).first << std::endl;
	// std::cout << (*rbeg).second << std::endl;



	// std::cout << *rend << std::endl;

	// m1.tryFunc(pair);
	// m1.insert(pair);
	// m1.insert(ft::make_pair('c', 30));


	// m1['b'] = 20;
	// m1['c'] = 30;

	// const_iter = iter;
	// iter = const_iter;

	// const_riter = riter;
	// iter = const_iter;

	// ft::vector<int> v1(2, 10);
	// ft::vector<int> v2 = v1;
	// std::map<int, int>::iterator it;

	// ft::pair<int, int> pair = ft::make_pair(50, 100);
	// std::cout << std::boolalpha;
	// std::cout << pair.first << " / " << pair.second <<std::endl;

	ft::Node<ft::pair<int, int> > node;
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
