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
	/*void print_top_info(const& int n)
	{
		if(n>=graph_size_counter)
			throw throw invalid_argument("Invalid argument");
		
	}*/
	bool is_connected(const int &n1, const int &n2)
	{
		if(n1>=graph_size_counter || n2>=graph_size_counter)
			throw invalid_argument("Invalid arguments");
		bool b = false;
		for (const auto& a = graph_map.at(n1).links)
		{
			if (a.link == &graph_map[n2])
			{
				b = true;
			}
		}
		return b;
	}
	void edit_edge_weight(const int& n1, const int& n2)
	{
		if (!is_connected(n1, n2))
		{
			throw invalid_argument("Invalid arguments");
		}
		
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