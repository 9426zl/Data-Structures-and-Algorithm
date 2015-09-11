//
//   graph_test.cpp
//   Graph algoithm test
//
//   Created by Baldwin Lou on 09/09/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "Graph.h"

int main()
{
	graph_list<int> ingraph;
	ingraph.adlist = {{1, 2, 3}, {3, 4}, {5}, {2, 4, 5, 6}, {6}, {}, {5}};
	ingraph.indglist = {0, 1, 2, 3, 1, 3, 2};
	
	topology_sort(ingraph);
	
	
	graph_list<int> ingraph2;
	ingraph2.adlist = {{1, 3}, {3, 4}, {0, 5}, {2, 4, 5, 6}, {6}, {}, {5}};
	ingraph2.known = {0, 0, 0, 0, 0, 0, 0};
	ingraph2.weighlist = {{2, 1}, {3, 10}, {4, 5}, {2, 2, 8, 4}, {6}, {}, {1}};
	
	dijkstra(ingraph2, 0);
	
	graph_list<int> ingraph3;
	ingraph3.adlist = {{1, 2, 3}, {0, 3, 4}, {0, 3, 5}, {0, 1, 2, 4, 5, 6}, {1, 3, 6}, {2, 3, 6}, {3, 4, 5}};
	ingraph3.known = {0, 0, 0, 0, 0, 0, 0};
	ingraph3.weighlist = {{2, 4, 1}, {2, 3, 10}, {4, 2, 5}, {1, 3, 2, 7, 8, 4}, {10, 7, 6}, {5, 8, 1}, {4, 6, 1}};
	
	prim(ingraph3);
		
	return 0;
}
