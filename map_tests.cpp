/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:36 by vlugand-          #+#    #+#             */
/*   Updated: 2022/05/03 00:36:59 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#ifdef STL
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
#endif

#define	MAX_SIZE 2048 // INT VALUE ONLY

template <typename T, typename U>
void	print_details(ft::map<T,U> &m)
{
	std::cout << "printing content: " << std::endl;
	for (typename ft::map<T,U>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << "[" << it->first << "] [" << it->second << "]" << std::endl;
	std::cout << "size = " << m.size() << std::endl; 
	if (m.empty())
		std::cout << "m is empty" << std::endl;
	else
		std::cout << "m is not empty" << std::endl;
}

void	testing_access()
{
	ft::map<int,int> m;
	ft::map<int, int>::iterator it;
	int key_a, key_b;

	std::cout << "\n********* testing_assign *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		m[rand() % RAND_MAX] = rand() % RAND_MAX;
	print_details(m);
	it = m.begin();
	for (int i = 0; i < rand() % MAX_SIZE && it != m.end(); i++)
		it++;
	key_a = it->first;
	for (int i = 0; i < rand() % MAX_SIZE && it != m.end(); i++)
		it++;
	key_b = it->first;
	m[key_a] = m[key_b];
	print_details(m);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_empty()
{
	ft::map<int,int> foo;
	ft::map<int,int> m;

	std::cout << "\n********* testing_empty *********\n" << std::endl;
	std::cout << "After calling map empty constructor:"<< std::endl;
	if (foo.empty())
		std::cout << "foo is empty" << std::endl;
	else
		std::cout << "foo is not empty" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		foo.insert(ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	std::cout << "After foo = m:"<< std::endl;
	if (foo.empty())
		std::cout << "foo is empty" << std::endl;
	else
		std::cout << "foo is not empty" << std::endl;
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_clear()
{
	ft::map<int,int> m;
	ft::map<int,int> mbis;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::reverse_iterator rit;

	std::cout << "\n********* testing_clear() *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		m.insert(ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	m.clear();
	m.clear();
	mbis.clear();
	mbis.clear();
	mbis.insert(m.rbegin(), m.rend());
	m.swap(mbis);
	print_details(m);
	print_details(mbis);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_swap()
{
	ft::map<int,int> m;
	ft::map<int,int> mbis;

	std::cout << "\n********* testing_swap() *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		m.insert(ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	for (int i = 0; i < MAX_SIZE; i++)
		mbis.insert(ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	m.swap(mbis);
	m.insert(ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	m.erase(rand() % MAX_SIZE);
	m.insert(ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	mbis.erase(rand() % MAX_SIZE);
	std::cout << "\nm after swap:" << std::endl;
	print_details(m);
	std::cout << "\nmbis after swap:" << std::endl;
	print_details(mbis);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_erase()
{
	ft::map<int,int> m;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::reverse_iterator rit;

	std::cout << "\n********* testing_erase() *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		m.insert(ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	std::cout << "(1) with iterator:" << std::endl;
	it = m.begin();
	for (int i = 0; i < rand() % MAX_SIZE && it != m.end(); i++)
		it++;
	m.erase(it);
	print_details(m);
	std::cout << "\n(2) with key:" << std::endl;
	rit = m.rbegin();
	for (int i = 0; i < rand() % MAX_SIZE && rit != m.rend(); i++)
		rit++;
	std::cout << "\nerasing known existing key:" << std::endl;	
	if (m.erase(rit->first))
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
	std::cout << "\nerasing random key:" << std::endl;
	if (m.erase(rand() % MAX_SIZE))
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
	print_details(m);
	std::cout << "\n(3) with iterator range:" << std::endl;
	it = m.begin();
	for (int i = 0; i < rand() % MAX_SIZE && it != m.end(); i++)
		it++;
	m.erase(m.begin(), it);
	print_details(m);
	m.erase(m.begin(), m.end());
	print_details(m);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_insert()
{
	ft::map<int,int> m1;
	ft::map<int,int> m2;
	ft::map<int,int> m3;
	ft::pair<int, int> val;
	ft::pair<ft::map<int, int>::iterator, bool> ret;
	ft::map<int,int>::iterator it;

	std::cout << "\n********* testing_insert() *********\n" << std::endl;
	std::cout << "(1) single element:" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		val = ft::make_pair(rand() % MAX_SIZE, rand() % MAX_SIZE);
		ret = m1.insert(val);
		if (ret.second == false)
			std::cout << "pair [" << val.first << "] [" << val.second << "] already exists" << std::endl;
	}
	print_details(m1);
	std::cout << "\n(2) with key:" << std::endl;
	it = m2.begin();
	for (int i = 0; i < MAX_SIZE; i++)
		it = m2.insert(it, ft::make_pair(rand() % RAND_MAX, rand() % RAND_MAX));
	print_details(m2);
	std::cout << "\n(3) range:" << std::endl;
	m3.insert(m2.begin(), it);
	print_details(m3);
	m1.insert(m3.rbegin(), m3.rend());
	print_details(m1);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_keycomp()
{
	ft::map<char,int> m;
	ft::map<char,int>::key_compare mycomp = m.key_comp();

	std::cout << "\n********* testing_keycomp() *********\n" << std::endl;
	m['a']= rand() % RAND_MAX;
	m['b']= rand() % RAND_MAX;
	m['c']= rand() % RAND_MAX;

  	std::cout << "m contains:\n";

	char highest = m.rbegin()->first;

	ft::map<char,int>::iterator it = m.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << std::endl;
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_valuecomp()
{
	ft::map<char,int> m;

	std::cout << "\n********* testing_valuecomp() *********\n" << std::endl;
	m['x']= rand() % RAND_MAX;
	m['y']= rand() % RAND_MAX;
	m['z']= rand() % RAND_MAX;

	std::cout << "m contains:\n";

	ft::pair<char,int> highest = *m.rbegin();

	ft::map<char,int>::iterator it = m.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( m.value_comp()(*it++, highest) );
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_find()
{
	ft::map<int,int> m;
	ft::map<int,int>::iterator it;

	std::cout << "\n********* testing_find() *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		m.insert(ft::make_pair(rand() % MAX_SIZE, rand() % MAX_SIZE));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if ((it = m.find(i)) != m.end())
			m.erase(it);
	}
	print_details(m);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_count()
{
	ft::map<int,int> m;

	std::cout << "\n********* testing_count() *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		m.insert(ft::make_pair(rand() % MAX_SIZE, rand() % MAX_SIZE));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		std::cout << i;
		if (m.count(i) > 0)
      		std::cout << " is an element of mymap.\n";
		else 
     		std::cout << " is not an element of mymap." << std::endl;
	}
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_bounds()
{
	ft::map<char,int> m;
	ft::map<char,int>::iterator itlow,itup;

	std::cout << "\n********* testing_bounds() *********\n" << std::endl;
	m['a']= rand() % RAND_MAX;
	m['b']= rand() % RAND_MAX;
	m['c']= rand() % RAND_MAX;
	m['d']= rand() % RAND_MAX;
	m['e']= rand() % RAND_MAX;

	itlow=m.lower_bound('b');  // itlow points to b
	itup=m.upper_bound('d');   // itup points to e (not d!)

	m.erase(itlow,itup);

	for (ft::map<char,int>::reverse_iterator it=m.rbegin(); it!=m.rend(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_range()
{
	ft::map<char,int> m;
	ft::map<char,int>::iterator itlow,itup;

	std::cout << "\n********* testing_range() *********\n" << std::endl;
	m['a']= rand() % RAND_MAX;
	m['b']= rand() % RAND_MAX;
	m['c']= rand() % RAND_MAX;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;

	ret = m.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_getalloc()
{
	int psize;
	ft::map<char,int> mymap;
	ft::pair<const char,int>* p;
	std::cout << "\n********* testing_getalloc() *********\n" << std::endl;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(ft::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_constructors()
{
	std::cout << "\n********* testing_constructors() *********\n" << std::endl;
	
	ft::map<char,int> basic;
	basic['a']=10;
	basic['b']=30;
	basic['c']=50;
	basic['d']=70;

	ft::map<char,int> range(basic.begin(),basic.end());
	basic['e']=42;

	ft::map<char,int> copy(range);
	basic['f']=420;

	print_details(basic);
	print_details(range);
	print_details(copy);
	std::cout << "\n************** END **************\n" << std::endl;
}

int main ()
{

	ft::map<int,int> m; // just testing ints here
	// first thing to test: modifiers with basic constructors // faire des try catch ?
	
	std::cout << ">>>>>>>>>>>>>>>> TESTING MAP <<<<<<<<<<<<<<<<<" << std::endl;
	// from now on size(), iterator, reverse iterator and basic constructor are required
	
	testing_insert(); // you need to use key comp and / or value comp as underlaying comparison tool
	// from now on insert() is required
	testing_erase();
	testing_swap();
	testing_clear();
	
	testing_empty();
	testing_access();

	testing_keycomp();
	testing_valuecomp();
	testing_find();
	testing_count();
	testing_bounds();
	testing_range();
	testing_getalloc();
	testing_constructors();

	std::cout << ">>>>>>>>>>>>>>>> END MAP TESTS <<<<<<<<<<<<<<<<<" << std::endl;

	return (0);
}