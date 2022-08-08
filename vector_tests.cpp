/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:19:36 by vlugand-          #+#    #+#             */
/*   Updated: 2022/08/08 16:43:16 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

#ifdef STL
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#define	MAX_SIZE 10000 // INT VALUE ONLY
#define SEED 42


std::string		itoa_cpp(int nb)
{
	std::stringstream	out;

	out << nb;
	return (out.str());
}

template <typename T>
void	print_details(ft::vector<T> &v) // uses size, max_size, capacity, empty and []
{
	std::cout << "printing details: " << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	if (v.empty())
		std::cout << "v is empty" << std::endl;
	else
		std::cout << "v is not empty" << std::endl;
	std::cout << "max size = " << v.max_size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;	
	std::cout << "content: " << std::endl;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "v[" << i << "] = "<< v[i] << std::endl;
	std::cout << "--------- details printed" << std::endl;
}

void	testing_back()
{
	ft::vector<int> v;
	ft::vector<std::string> vs;

	std::cout << "\n********* testing_back *********\n" << std::endl;
	v.push_back(10);
	while (v.back() != 0)
		v.push_back ( v.back() -1 );
	std::cout << "v contains:";
	for (unsigned i = 0; i < v.size() ; i++)
		std::cout << ' ' << v[i] << std::endl;
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_front()
{
	ft::vector<int> v;

	std::cout << "\n********* testing_front *********\n" << std::endl;
	v.push_back(10);
	while (v.front() != 0)
		v.push_back ( v.front() -1 );
	std::cout << "v contains:";
	for (unsigned i = 0; i < v.size() ; i++)
		std::cout << ' ' << v[i] << std::endl;
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_at()
{
	ft::vector<int> v(MAX_SIZE);

	std::cout << "\n********* testing_at *********\n" << std::endl;
	for (unsigned i = 0; i < v.size(); i++)
		v.at(i)=i;
	std::cout << "v contains:";
	for (unsigned i = 0; i < v.size(); i++)
		std::cout << ' ' << v.at(i) << std::endl;
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_reserve()
{
	ft::vector<int> v;
	ft::vector<int>::size_type sz;

	std::cout << "\n********* testing_reserve *********\n" << std::endl;
	sz = v.capacity();
	v.reserve(MAX_SIZE / 2);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		v.push_back(rand() % RAND_MAX);
		if (sz != v.capacity()) 
		{
			sz = v.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
    }
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_clear()
{
	ft::vector<int> v;

	std::cout << "\n********* testing_clear *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(rand() % RAND_MAX);
	v.clear();
	print_details(v);
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(rand() % RAND_MAX);
	print_details(v);
	v.clear();
	print_details(v);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_swap()
{
	ft::vector<int> v1;
	ft::vector<int> v2;

	std::cout << "\n********* testing_swap *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v1.push_back(rand() % RAND_MAX);
	for (int i = 0; i < MAX_SIZE; i++)
		v2.push_back(rand() % RAND_MAX);
	v1.swap(v2);
	v1.erase(v1.begin());
	v2.assign(rand() % MAX_SIZE, rand() % RAND_MAX);
	print_details(v1);
	print_details(v2);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_erase()
{
	ft::vector<int> v;
	ft::vector<int>::iterator it;

	std::cout << "\n********* testing_erase *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(rand() % RAND_MAX);
	it = v.begin() + v.size() / 2;
	it = v.erase(it);
	std::cout << "*it = " << *it << std::endl;
	print_details(v);
	v.erase(v.begin(), v.end());
	v.erase(v.begin(), v.end());
	print_details(v);
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(rand() % RAND_MAX);
	print_details(v);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_insert()
{
	ft::vector<std::string> vs1;
	ft::vector<std::string> vs2;
	ft::vector<std::string>::iterator it;

	std::cout << "\n********* testing_insert *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		vs1.push_back(itoa_cpp(rand() % RAND_MAX));
	std::cout << "(1) single element:" << std::endl;
	it = vs1.begin() + vs1.size() / 2;
  	it = vs1.insert(it, itoa_cpp(rand() % RAND_MAX));
	std::cout << "*it = " << *it << std::endl;
	it = vs1.end();
  	it = vs1.insert(it , itoa_cpp(rand() % RAND_MAX));
	std::cout << "*it = " << *it << std::endl;
	print_details(vs1);
	std::cout << "(2) fill:" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		vs2.push_back(itoa_cpp(rand() % RAND_MAX));
	it = vs2.begin() + vs2.size() / 2;
	vs2.insert(it, rand() % MAX_SIZE, itoa_cpp(rand() % RAND_MAX));
	print_details(vs2);
	std::cout << "(3) range:" << std::endl;
	it = vs2.begin() + vs2.size() / 2;
	vs2.insert(it, vs1.rbegin(), vs1.rend());
	print_details(vs2);
	std::string myarray [] = {"501","502","503"};
  	vs1.insert (vs1.begin() + vs1.size() / 2, myarray, myarray + 3);
	print_details(vs1);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_push_pop_back()
{
	ft::vector<int> v;

	std::cout << "\n********* testing_push_pop_back *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(rand() % RAND_MAX);
	if (!v.empty())
		v.pop_back();
	print_details(v);
	while (!v.empty())
		v.pop_back();
	print_details(v);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_assign()
{
	ft::vector<int> v1;
	ft::vector<int> v2;
	ft::vector<int> v3;

	std::cout << "\n********* testing_assign *********\n" << std::endl;
	v1.assign(0, 0);
	v2.assign(v1.begin(), v1.end());
	print_details(v1);
	print_details(v2);
	v1.assign(rand() % MAX_SIZE, rand() % RAND_MAX);
	v2.assign(v1.begin(), v1.end());
	print_details(v1);
	print_details(v2);
	int myints[] = {1776,7,4};
  	v3.assign(myints,myints+3);
	v2.assign(v3.rbegin(), v3.rend());
	print_details(v1);
	print_details(v2);
	print_details(v3);
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_constructors()
{
	ft::vector<std::string> basic;
	basic.push_back("foo");
	basic.push_back("bar");
	basic.push_back("baz");
	ft::vector<std::string> fill (42, "lol");
	ft::vector<std::string> range (fill.begin(), fill.end());
	range.push_back("mdr");
	ft::vector<std::string> copy (basic);
	copy.pop_back();
	print_details(basic);
	print_details(fill);
	print_details(range);
	print_details(copy);
}

void	testing_relational_op()
{
	ft::vector<std::string> v;
	ft::vector<std::string> vbis;

	std::cout << "\n********* testing_relational_op() *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(itoa_cpp(rand() % RAND_MAX));
	vbis = v;
	if (v == vbis)
		std::cout << "v == vbis" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(itoa_cpp(rand() % RAND_MAX));
	if (v != vbis)
		std::cout << "v != vbis" << std::endl;
	if (v <= vbis)
		std::cout << "v <= vbis" << std::endl;
	if (v >= vbis)
		std::cout << "v >= vbis" << std::endl;
	std::cout << "\n************** END **************\n" << std::endl;
}

void	testing_iterators()
{
	ft::vector<int> v;
	ft::vector<int>::iterator it;
	ft::vector<int>::const_iterator cit;
	ft::vector<int>::reverse_iterator rit;
	ft::vector<int>::const_reverse_iterator crit;

	std::cout << "\n********* testing_iterators() *********\n" << std::endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(rand() % RAND_MAX);
	it = v.begin();
	cit = v.begin();
	if (it == cit)
		std::cout << "it == cit" << std::endl;
	it = v.end();
	cit = v.end();
	if (it == cit)
		std::cout << "it == cit" << std::endl;
	rit = v.rbegin();
	crit = v.rbegin();
	if (rit == crit)
		std::cout << "rit == crit" << std::endl;
	rit = v.rend();
	crit = v.rend();
	if (rit == crit)
		std::cout << "rit == crit" << std::endl;
	std::cout << "\n************** END **************\n" << std::endl;
}

int main ()
{
	srand(SEED);

	std::cout << ">>>>>>>>>>>>>>>> TESTING vector <<<<<<<<<<<<<<<<<" << std::endl;
	// from now on size(), iterator, reverse iterator and basic constructor are required
	// size, max_size, capacity, empty and []
	testing_assign();
	testing_push_pop_back();
	testing_insert();
	testing_erase();
	testing_swap();
	testing_clear();
	testing_reserve();
	testing_at();
	testing_constructors();
	testing_relational_op();
	testing_iterators();
	std::cout << ">>>>>>>>>>>>>>>> END vector TESTS <<<<<<<<<<<<<<<<<" << std::endl;

	return (0);
}
