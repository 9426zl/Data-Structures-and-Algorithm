//
//   Graph.h
//   Topology sort,  Dijkstra and Prim realization
//
//   Created by Baldwin Lou on 09/09/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <vector>

const int maxV = 100;
const int Inf = 1000000;

template <typename T>
struct graph_list {
	int vertex;
	int edge;
	std::vector<std::vector<int>> adlist;     // adjacency list
	std::vector<std::vector<T>> weighlist;    // weight list
	std::vector<int> indglist;                // indegree list
	std::vector<int> known; 
	
	~graph_list(){
		adlist.clear();
		weighlist.clear();
		indglist.clear();
	}
};

// Topology Sort
template <typename T>
void topology_sort(graph_list<T> ingraph)
{
	std::vector<int> qu;
	auto count = ingraph.indglist.size();
	int i,flag = 0;
	
	std::vector<int>::iterator iter = ingraph.indglist.begin();
	for ( i = 0; iter != ingraph.indglist.end(); ++iter, ++i)
		if(*iter == 0)
			flag = 1;
	
	if (flag == 0)
	{
		std::cerr << "The graph is of circle." << std::endl;
		return;
	}
	
	while (count != 0)
	{
		int i = 0;
		int j = 0;
		std::vector<int>::iterator iter = ingraph.indglist.begin();
		for ( ; iter != ingraph.indglist.end(); ++iter, ++i)
			if(*iter == 0)
			{
				qu.push_back(i);
				--count;	
					
				for(auto it : ingraph.adlist[i])
					--ingraph.indglist[it];
				
					
				*iter = Inf;
			}
	}
	
	for(auto &i : qu)
		std::cout << i << " ";
	std::cout << std::endl;
}

//Dijkstra
template <typename T>
void dijkstra(graph_list<T> ingraph, int S)
{
	std::vector<int> qu;
	int stat = S;
	int count = ingraph.known.size() - 1;
	int i = 0; int j = 0;
		
	ingraph.known[stat] = 1;
	qu.push_back(stat);
	
	while(count != 0)
	{
		int i = 0;int m = 0;
		int n = 0;int tmp = 0;int nn = 0;
		T min = Inf;
		
		for (auto &j : ingraph.known)
		{	
			std::cout << j << " ";
			if (j == 1)
			{
				auto k = ingraph.weighlist[i].begin();
				for (int p = 0;k != ingraph.weighlist[i].end(); ++k, ++p)
				{	nn = ingraph.adlist[i][p];
					if (ingraph.known[nn] != 1 && *k < min)
					{
						min = *k;
						m = i;
						n = p;
					}
				}
			}		
			++i;
		}

		tmp = ingraph.adlist[m][n];
		std::cout << " " << tmp << "\n";
		qu.push_back(tmp);
		ingraph.known[tmp] = 1;
		--count;	
	} 
	
	for(auto &i : qu)
		std::cout << i << " ";
	std::cout << std::endl;
	
}

// MST_Prim
template <typename T>
void prim(graph_list<T> ingraph)
{
	std::vector<int> qu;
	int min = Inf;
	int i = 0; int j = 0;
	int m = 0; int n = 0;
	int count = ingraph.known.size();
	
	for (auto &r : ingraph.weighlist)
	{
		for(auto &co : r)
		{
			if (co < min)
			{
				min = co;
				m = i;
				n = j;
			}
			++j;
		}
		++i;	
	}
	ingraph.known[m] = 1;
	qu.push_back(m);
	n = ingraph.adlist[m][n];
	ingraph.known[n] = 1;
	qu.push_back(n);
	count -= 2;
		
	while(count != 0)
	{
		int i = 0;int m = 0;
		int n = 0;int tmp = 0; int nn = 0;
		T min = Inf;
		
		for (auto &j : ingraph.known)
		{	
			std::cout << j << " ";
			if (j == 1)
			{
				auto k = ingraph.weighlist[i].begin();
				for (int p = 0;k != ingraph.weighlist[i].end(); ++k, ++p)
				{
					nn = ingraph.adlist[i][p];
					if (ingraph.known[nn] != 1 && *k < min)
					{
						min = *k;
						m = i;
						n = p;
					}	
				}		
			}		
			++i;
		}

		tmp = ingraph.adlist[m][n];
		std::cout << " " << tmp << "\n";
		qu.push_back(tmp);
		ingraph.known[tmp] = 1;
		--count;
		
		ingraph.weighlist[m][n] = Inf;
	}
	
	for(auto &i : qu)
		std::cout << i << " ";
	std::cout << std::endl;	
}

#endif
