#pragma once
#include <map>
#include <set>

using namespace std;

template <typename T>
class Graph
{
private:
	class Edge;
	class Top
	{
	public:
		Top() {};
		Top(T data)
		{
			this->data = data;
		}
		T data;
		set <Edge*> links;
	};
	class Edge
	{
	public:
		/*Edge() {};
		Edge(T data) */
		int weight;
		set <Top*> links;
	};
	map<int, Top> graph_map;
	int counter = 0;
	
public:

	T& operator[](const int& index)
	{
		return graph_map.at(index).data;
	}
	void add_top()
	{
		graph_map[counter];
		counter++;
	}
	void add_top(T data)
	{
		graph_map[counter] = Top(data);
		counter++;
	}
};
