#pragma once
#include <map>
#include <vector>
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
		set <Edge> links;
	};
	class Edge
	{
	public:
		Edge() {};
		Edge(Top* link, int weight)
		{
			this->link = link;
			this->weight = weight;
		}
		Top* link;
		int weight;
	};
	map<int, Top> graph_map;
	int graph_size_counter = 0;
	
public:
	friend bool operator<(const Top& lft, const Top& rth)
	{
		return lft.data < rth.data;
	}
	friend bool operator<(const Edge& lft, const Edge& rth)
	{
		return lft.link < rth.link;
	}
	T& operator[](const int& index)
	{
		return graph_map.at(index).data;
	}
	void clean()
	{
		graph_map.clear();
		graph_size_counter = 0;
	}
	void add_top()
	{
		graph_map[graph_size_counter];
		graph_size_counter++;
	}
	void add_top(T data)
	{
		graph_map[graph_size_counter] = Top(data);
		graph_size_counter++;
	}
	void adj_matrix(const vector<vector<int>>& adjacency_matrix)
	{
		graph_map.clear();
		int count = adjacency_matrix.size();
		graph_size_counter = count;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (adjacency_matrix[i][j])
				{
					graph_map[i].links.insert(Edge{ &graph_map[j], 1 });
				}
			}
		}
	}
	void adj_list(const vector<vector<int>>& adjacency_list)
	{
		graph_map.clear();
		int count = adjacency_list.size();
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < adjacency_list[i].size(); j++)
			{
				if (adjacency_list[i][j] >= count)
					throw invalid_argument("Invalid list");
				graph_map[i].links.insert(Edge{ &graph_map[adjacency_list[i][j]], 1 });
			}
		}
	}
};