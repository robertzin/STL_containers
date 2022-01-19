// clang++ -Wall -Wextra -Werror -std=c++98 -pedantic main_stl.cpp

# include <sys/time.h>
# include <iostream>
# include <ctime>

# include <map>
# include <vector>
# include <stack>
# include <iterator>

bool fncomp (char lhs, char rhs) {return lhs < rhs;}

struct classcomp {
bool operator() (const int& lhs, const int& rhs) const
	{return lhs < rhs;}
};

time_t get_time(void)
{
	struct timeval time_now;

	gettimeofday(&time_now, NULL);
	time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	return(msecs_time);
}

int main(void) {

	std::cout << std::endl;
	std::cout << " ******************************************" << std::endl;
	std::cout << " *              VECTOR PART               *" << std::endl;
	std::cout << " ******************************************" << std::endl;
	std::cout << " __________________________________________" << std::endl;

	time_t start, end, diff;
	start = get_time();

	std::cout << "| constructors:        ";

	std::vector<int> first;
	std::vector<int> second (1000,100);
	std::vector<int> third (second.begin(),second.end());
	std::vector<int> fourth (third);

	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "          | success |" << std::endl;

	std::cout << "| begin:                         ";
	for (int i = 1; i <= 50000; i++) first.push_back(i);
	std::vector<int>::iterator it = first.begin();
	for ( ; it != first.end(); ++it) {}
		// std::cout << ' ' << *it;
	// std::cout << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| end:                           ";
	it = first.begin();
	for ( ; it != first.end(); ++it) {}
		// std::cout << ' ' << *it;
	// std::cout << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| rbegin:                       ";

	int i = 1;
	std::vector<int>::reverse_iterator rit = first.rbegin();
	for (; rit!= first.rend(); ++rit) {
		*rit = i;
		// std::cout << ' ' << *rit;
	}
	std::cout << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| rend:                         ";

	int ie = 5;
	std::vector<int>::reverse_iterator rite = first.rbegin();
	for (; rite!= first.rend(); ++rite) {
		*rite = ie;
		// std::cout << ' ' << *rite;
	}
	std::cout << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| size:                          ";
	if (first.size() == 50000)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| max_size:  ";

	std::cout << first.max_size() << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| resize:                        ";
	first.resize(10000);
	if (first.size() == 10000)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| capacity:                      ";
	for (int l = 0; l < 100000; l++)
		first.push_back(l);

	int cap = first.capacity();
	(void)cap;
		std::cout << "| success |" << std::endl;

	std::cout << "| empty:                         ";
	bool v_before = first.empty();
	first.clear();
	bool v_after = first.empty();
	if (!v_before && v_after)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;


	std::cout << "| reserve:                       ";
	// std::cout << first.capacity() << " / ";
	first.reserve(100000);
	// std::cout << first.capacity() << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| operator[]:                    ";
	first.push_back(1);
	// std::cout << "[0]: " << first[0] << " / ";
	first[0] = 5;
	// std::cout << first[0] << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| operator at:                   ";
	first.at(0) = 3;
	// std::cout << "[0]: " << first.at(0) << " / ";
	first.at(0) = 7;
	// std::cout << first.at(0) << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| front:                         ";
	first.clear();
	for (int y = 0; y < 10000; y ++)
		first.push_back(y);
	// std::cout << first.front() << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| back:                          ";
	// std::cout << first.back() << " ";
	std::cout << "| success |" << std::endl;

	std::cout << "| assign:                        ";
	first.clear();
	second.clear();
	third.clear();

	first.assign (7,100);
	it = first.begin() + 1;
	second.assign (it, first.end() - 1);

	int myintz[] = {1776, 7, 4};
	third.assign (myintz, myintz + 3);
	if (first.size() == 7 && second.size() == 5 && third.size() == 3)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| push_back:                     ";
	first.clear();
	for (int p = 0; p < 10000; p++)
		first.push_back(p);
	if (first.size() == 10000)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| pop_back:                      ";
	first.clear();

	int sum = 0;
	first.push_back (100);
	first.push_back (200);
	first.push_back (300);
	while (!first.empty())
	{
	sum += first.back();
	first.pop_back();
	}
	if (sum == 600)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| insert:                        ";
	std::vector<int> sixth (3,100);

	it = sixth.begin();
	it = sixth.insert (it, 200);
	sixth.insert (it, 2, 300);

	it = sixth.begin();

	std::vector<int> anothervector (2,400);
	sixth.insert (it + 2, anothervector.begin(), anothervector.end());

	int myarray [] = { 501, 502, 503 };
	sixth.insert (sixth.begin(), myarray, myarray+3);
	std::cout << "| success |" << std::endl;

	std::cout << "| erase:                         ";

	first.clear();
	for (int i = 1; i <= 10; i++)
		first.push_back(i);

	first.erase (first.begin()+5);
	first.erase (first.begin(),first.begin()+3);
	std::cout << "| success |" << std::endl;

	std::cout << "| swap:                          ";
	std::vector<int> foo (3000,100);
	std::vector<int> bar (5000,200);
	foo.swap(bar);
	if (foo[0] == 200 && bar[0] == 100)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| clear:                         ";
	foo.clear();
	if (foo.empty())
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| get_allocator:                 ";

	std::vector<int> zz;
	int *p;
	unsigned int iz;

	p = zz.get_allocator().allocate(5);

	for (iz = 0; iz < 5; iz++)
		zz.get_allocator().construct(&p[i],i);
	for (iz = 0; iz < 5; iz++)
		zz.get_allocator().destroy(&p[iz]);
	zz.get_allocator().deallocate(p, 5);
	std::cout << "| success |" << std::endl;

	std::cout << "| relational operators:          ";

	std::vector<int> fooz (3000,100);
	std::vector<int> barz (2000,200);

	bool q = fooz == barz;
	bool w = fooz != barz;
	bool e = fooz < barz;
	bool r = fooz > barz;
	bool t = fooz <= barz;
	bool y = fooz >= barz;

	if (!q && w && e && !r && t && !y )
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "|__________________________________________|" << std::endl;
	std::cout << std::endl;

	std::cout << " ******************************************" << std::endl;
	std::cout << " *              STACK  PART               *" << std::endl;
	std::cout << " ******************************************" << std::endl;
	std::cout << " __________________________________________" << std::endl;

	std::cout << "| constructors:                  ";
	std::vector<int> mv (2,200);

	std::stack<int> st_first;
	std::stack<int,std::vector<int> > st_second;
	std::stack<int,std::vector<int> > st_third(mv);
	std::cout << "| success |" << std::endl;

	std::cout << "| empty:                         ";
	int st_sum = 0;

	for (int i = 1; i <= 10000;i++)
		st_first.push(i);

	while (!st_first.empty()) {
		st_sum += st_first.top();
		st_first.pop();
	}
	std::cout << "| success |" << std::endl;

	std::cout << "| size:                          ";
	for (int i = 0; i < 5000; i++) st_first.push(i);
	std::cout << "| success |" << std::endl;

	std::cout << "| top:                           ";
	st_first.push(10);
	st_first.push(20);

	st_first.top() -= 5;
	if (st_first.top() == 15)
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;

	std::cout << "| push:                          ";
	st_first.push(10);
	st_first.push(20);

	std::cout << "| success |" << std::endl;

	std::cout << "| pop:                           ";
	st_first.pop();
	st_first.pop();

	std::cout << "| success |" << std::endl;

	std::cout << "| relational operators:          ";

	std::deque<int> st_foov (3000,100);
	std::deque<int> st_barv (2000,100);

	std::stack<int> st_foos(st_foov);
	std::stack<int> st_bars(st_barv);

	bool sq = st_foos == st_bars;
	bool sw = st_foos != st_bars;
	bool se = st_foos < st_bars;
	bool sr = st_foos > st_bars;
	bool st = st_foos <= st_bars;
	bool sy = st_foos >= st_bars;

	if (!sq && sw && se && !sr && st && !sy )
		std::cout << "| success |" << std::endl;
	else
		std::cout << "| failure |" << std::endl;
	std::cout << "|__________________________________________|" << std::endl;
	std::cout << std::endl;

	std::cout << " ******************************************" << std::endl;
	std::cout << " *                MAP PART                *" << std::endl;
	std::cout << " ******************************************" << std::endl;
	std::cout << " __________________________________________" << std::endl;
	std::cout << "| constructors:        ";



	std::map<int,int> map_1;
	for (int y = 0; y < 10000; y++)
		map_1[y] = y * 5;

	std::map<int,int> map_2 (map_1.begin(), map_1.end());
	std::map<int,int> map_3 (map_2);
	std::map<int,int, classcomp> map_4;

	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> map_5 (fn_pt);

	std::cout << "          | success |" << std::endl;

	std::cout << "| operator=:           ";

	std::map<int,int> map_6;
	std::map<int,int> map_7;

	for (int y = 0; y < 10000; y++)
		map_6[y] = y * 2;

	map_7 = map_6;
	map_6 = std::map<int,int>();

	if (map_6.size() == 0 && map_7.size() == 10000)
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| begin:               ";
	std::map<char,int> map_8;

	map_8['b'] = 100;
	map_8['a'] = 200;
	map_8['c'] = 300;

	std::map<char, int>::iterator map_8_i = map_8.begin();
	char map_8_a1 = map_8_i->first;
	map_8_i++;
	char map_8_a2 = map_8_i->first;
	map_8_i++;
	char map_8_a3 = map_8_i->first;

	if (map_8_a1 == 'a' && map_8_a2 == 'b' && map_8_a3 == 'c')
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| end:                 ";
	std::map<char,int> map_9;

	map_9['b'] = 100;
	map_9['a'] = 200;
	map_9['c'] = 300;

	std::map<char, int>::iterator map_9_i = map_9.end();
	map_9_i--;
	char map_9_a1 = map_9_i->first;
	map_9_i--;
	char map_9_a2 = map_9_i->first;
	map_9_i--;
	char map_9_a3 = map_9_i->first;

	if (map_9_a1 == 'c' && map_9_a2 == 'b' && map_9_a3 == 'a')
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| rbegin:              ";
	std::map<char,int> map_10;

	map_10['b'] = 100;
	map_10['a'] = 200;
	map_10['c'] = 300;

	std::map<char, int>::reverse_iterator map_10_i = map_10.rbegin();
	char map_10_a1 = map_10_i->first;
	map_10_i++;
	char map_10_a2 = map_10_i->first;
	map_10_i++;
	char map_10_a3 = map_10_i->first;

	if (map_10_a1 == 'c' && map_10_a2 == 'b' && map_10_a3 == 'a')
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| rend:                ";
	std::map<char,int> map_11;

	map_11['b'] = 100;
	map_11['a'] = 200;
	map_11['c'] = 300;

	std::map<char, int>::reverse_iterator map_11_i = map_11.rend();
	map_11_i--;
	char map_11_a1 = map_11_i->first;
	map_11_i--;
	char map_11_a2 = map_11_i->first;
	map_11_i--;
	char map_11_a3 = map_11_i->first;

	if (map_11_a1 == 'a' && map_11_a2 == 'b' && map_11_a3 == 'c')
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| empty:               ";

	bool before_1 = map_10.empty();
	map_10.clear();
	bool after_1 = map_10.empty();


	if (!before_1 && after_1)
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| size:                ";

	int before_2 = map_10.size();
	map_10['a'] = 101;
	map_10['b'] = 202;
	map_10['c'] = 302;
	int after_2 = map_10.size();

	if (before_2 == 0 && after_2 == 3)
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| max_size:            ";

	map_10.clear();
	before_2 = map_10.max_size();
	for (i = 0; i < 3000; i++)
		map_10[i] = 0;
	after_2 = map_10.max_size();

	if (before_2 == after_2)
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| operator[]:          ";

	map_10.clear();
	for (char i = 'a'; i < 'z'; i++) {
		map_10[i] = 10 + int(i);
	}
	std::map<char, int>::iterator map_it = map_10.begin();
	std::map<char, int>::iterator map_ite = map_10.end();
	for (; map_it != map_ite; map_it++) {}
		// std::cout << map_it-> first << " -> " << map_it->second << std::endl;

	if (map_10.find('a')->second == 107 && map_10.find('n')->second == 120 && map_10.find('x')->second == 130)
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| insert:              ";

	std::map<char,int> map_12;
	map_12.insert ( std::pair<char,int>('a',100) );
	map_12.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> map_12_p;
	map_12_p = map_12.insert ( std::pair<char,int>('z',500) );

	// if (map_12_p.second == false) {
	// 	std::cout << "element 'z' already existed";
	// 	std::cout << " with a value of " << map_12_p.first->second << '\n';
	// }

	std::map<char,int>::iterator map_12_it;
	map_12_it = map_12.begin();
	map_12.insert (map_12_it, std::pair<char,int>('b',300));
	map_12.insert (map_12_it, std::pair<char,int>('c',400));

	std::map<char,int> anothermap_12;
	anothermap_12.insert(map_12.begin(),map_12.find('c'));

//   // showing contents:
	for (map_12_it = map_12.begin(); map_12_it != map_12.end(); ++map_12_it) {}
    // std::cout << map_12_it->first << " => " << map_12_it->second << '\n';

	for (map_12_it = anothermap_12.begin(); map_12_it!=anothermap_12.end(); ++map_12_it) {}
    // std::cout << map_12_it->first << " => " << map_12_it->second << '\n';
	std::cout << "          | success |" << std::endl;

	std::cout << "| erase:               ";

	std::map<char,int> map_13;
	std::map<char,int>::iterator map_13_it;

	// insert some values:
	map_13['a']=10;
	map_13['b']=20;
	map_13['c']=30;
	map_13['d']=40;
	map_13['e']=50;
	map_13['f']=60;

	map_13_it = map_13.find('b');
	map_13.erase (map_13_it);

	map_13.erase ('c');

	map_13_it = map_13.find ('e');
	map_13.erase ( map_13_it, map_13.end() );
	std::cout << "          | success |" << std::endl;

	std::cout << "| swap:                ";

	std::map<char,int> map_14, map_15;

	map_14['x']=100;
	map_14['y']=200;

	map_15['a']=11;
	map_15['b']=22;
	map_15['c']=33;

	map_14.swap(map_15);

	if (map_14.begin()->first == 'a' && map_15.begin()->first == 'x')
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| key_comp:            ";

	std::map<char,int> map_16;
	std::map<char,int>::key_compare mycomp = map_16.key_comp();

	map_16['a'] = 100;
	map_16['b'] = 200;
	map_16['c'] = 300;

	char highest = map_16.rbegin()->first;
	std::map<char,int>::iterator map_16_it = map_16.begin();
	do {
		// std::cout << map_16_it->first << " => " << map_16_it->second << '\n';
	} while ( mycomp((*map_16_it++).first, highest) );
	std::cout << "          | success |" << std::endl;

	std::cout << "| value_comp:          ";

	std::map<char,int> map_17;
	map_17['x'] = 1001;
	map_17['y'] = 2002;
	map_17['z'] = 3003;

	std::pair<char,int> map_17_highest = *map_17.rbegin();
	std::map<char,int>::iterator map_17_it = map_17.begin();

	do {
		// std::cout << map_17_it->first << " => " << map_17_it->second << '\n';
	} while ( map_17.value_comp()(*map_17_it++, map_17_highest) );
	std::cout << "          | success |" << std::endl;

	std::cout << "| find:                ";

	std::map<char,int> map_18;
	std::map<char,int>::iterator map_18_it;

	map_18['a']=50;
	map_18['b']=100;
	map_18['c']=150;
	map_18['d']=200;

	map_18_it = map_18.find('b');
	if (map_18_it != map_18.end())
		map_18.erase (map_18_it);

	if (map_18.find('a')->second == 50 && map_18.find('c')->second == 150 && map_18.find('d')->second == 200)
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| count:               ";

	std::map<char,int> map_19;

	map_19 ['a'] = 101;
	map_19 ['c'] = 202;
	map_19 ['f'] = 303;

	if (map_19.count('a') && !map_19.count('b') && map_19.count('f') && map_19.count('c'))
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;

	std::map<char,int> map_20;
	std::map<char,int>::iterator map_20_itlow, map_20_itup;

	map_20['a'] = 20;
	map_20['b'] = 40;
	map_20['c'] = 60;
	map_20['d'] = 80;
	map_20['e'] = 100;

	map_20_itlow = map_20.lower_bound('b');
	map_20_itup = map_20.upper_bound('d');
	map_20.erase(map_20_itlow, map_20_itup);

	if (map_20.size() == 2) {
		std::cout << "| lower_bound:         " << "          | success |" << std::endl;
		std::cout << "| upper_bound:         " << "          | success |" << std::endl;
	}
	else
		std::cout << "          | failure |" << std::endl;

	std::cout << "| equal_range:         ";


	std::map<char,int> map_21;

	map_21['a'] = 10;
	map_21['b'] = 20;
	map_21['c'] = 30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = map_21.equal_range('b');

	if (ret.first->first == 'b' && ret.first->second == 20
		&& ret.second->first == 'c' && ret.second->second == 30)
		std::cout << "          | success |" << std::endl;
	else
		std::cout << "          | failure |" << std::endl;


	std::cout << "| equal_range:         ";

	int p22size;
	std::map<char,int> map_22;
	std::pair<const char,int>* p22;

	p22 = map_22.get_allocator().allocate(5);
	p22size = sizeof(std::map<char,int>::value_type) * 5;
	map_22.get_allocator().deallocate(p22, 5);

	std::cout << "          | success |" << std::endl;
	std::cout << "|__________________________________________|" << std::endl;
	std::cout << std::endl;
	end = get_time();
	diff = end - start;
	std::cout << " ******************************************" << std::endl;
	std::cout << " *         AVG TIME:      " << diff << "              *" << std::endl;
	std::cout << " ******************************************" << std::endl;

	return 0;
}
