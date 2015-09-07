//
//   Hashtable.h
//   Hash table (separate chaining)realization
//
//   Created by Baldwin Lou on 09/07/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename T>
class HashTable {
public:
	HashTable():tablesize(0) { }
	
	bool contains(const T& elem) const;
	
	void make_empty();
	void insert(const T& elem);
	void remove(const T& elem);

private:
	std::vector<std::list<T>> hashlist;
	int tablesize;
	
	void rehash();
	int dohash(const T& elem ) const;
};

template<typename T>
bool HashTable<T>::contains(const T& elem) const
{
	const std::list<T>& clist = hashlist[dohash(elem)];
	return find(clist.begin(), clist.end(), elem) != clist.end();
}

template<typename T>
void HashTable<T>::make_empty()
{
	int i = 0;
	while (i < hashlist.size())
	{
		hashlist[i].clear();
		++i;
	}
}

template<typename T>
void HashTable<T>::insert(const T& elem)
{
	std::list<T>& clist = hashlist[dohash(elem)];
	if (contains(elem))
		std::cout << "The element is already in the table."
				  << std::endl;
	else
	{
		clist.push_back(elem);
		if (++tablesize > hashlist.size())
			rehash();
	}
}

template<typename T>
void HashTable<T>::remove(const T& elem)
{
	std::list<T> &clist = hashlist[dohash(elem)];
	typename std::list<T>::iterator iter = find(clist.begin(), clist.end(), elem);
	
	if (iter == clist.end())
		std::cerr << "The element is not in the table." 
				  << std::endl;
	
	clist.erase(iter);
	--tablesize;
}

template<typename T>
void HashTable<T>::rehash()
{
	std::vector<std::list<T>> oldtable = hashlist;
	int i = 0;
	
	hashlist.resize(2*hashlist.size());
	while(i < hashlist.size())
	{
		hashlist[i].clear();
		++i;
	}
	
	tablesize = 0;
	for (i = 0; i < oldtable.size(); ++i)
	{
		typename std::list<T>::iterator iter = oldtable[i].begin();
		while (iter != oldtable[i].end())
			insert(*iter++);
	}
}

template<typename T>
int HashTable<T>::dohash(const T&elem) const
{
	int hashval = int(elem);
	hashval %= hashlist.size();
	
	if (hashval < 0)
		hashval += hashlist.size();
		
	return hashval;
}

#endif
