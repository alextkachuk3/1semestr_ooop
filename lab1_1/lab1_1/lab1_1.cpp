﻿#include <iostream>
#include "Graph.h"

int main()
{
	Graph<int> my_graph;
	my_graph.add_top();
	my_graph.add_top();
	my_graph.add_top(3);
	auto b = my_graph[2];
	return 0;
}