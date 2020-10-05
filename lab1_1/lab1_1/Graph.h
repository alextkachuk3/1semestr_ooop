#pragma once
#include <map>
#include <vector>
#include <set>


using namespace std;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& vec)
{
	string result;
	result += "{ ";
	for (const auto& a : vec)
	{
		result += (a) + ", ";
	}
	result.resize(result.size() - 2);
	out << result;
	return out;
}

template <typename T>
class graph
{
private:
	class Edge;
	class Top
	{
	public:
		Top() :data() { };
		Top(const T& data)
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
	size_t graph_size_counter = 0;

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
	int size() const
	{
		return graph_size_counter;
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
	void del_top(const int& index)
	{
		T data = graph_map.at(index).data;
		if (!graph_map.count(index))
		{
			cout << "There is no such top!" << endl;
			return;
		}
		for (auto& a : graph_map)
		{
			for (auto& b : a.second.links)
			{
				if (b.link->data == data)
				{
					a.second.links.erase(b);
					break;
				}
			}
		}
		graph_map.erase(index);
		graph_size_counter--;
	}
	void print_top_info(const int& n)
	{
		cout << graph_map.at(n).data;
	}
	void print_graph()
	{
		for (const auto& a : graph_map)
		{
			cout << "#" << a.first << "-" << a.second.data << " connected to:";
			for (const auto& b : a.second.links)
			{
				cout << b.link->data << "(" << b.weight << ")";
			}
			cout << endl;
		}
	}
	void change_data(const int& index, const T& data)
	{
		graph_map[index].data = data;
	}
	void connect(const int& from, const int& to)
	{
		graph_map[from].links.insert({ &graph_map[to], 1 });
	}
	void adj_matrix(const vector<vector<int>>& adjacency_matrix)
	{
		graph_map.clear();
		size_t count = adjacency_matrix.size();
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
		size_t count = adjacency_list.size();
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
	int distance(const int& ind1, const int& ind2)
	{
		vector<int> dist(graph_size_counter - 1);
		return 0;
	}
	bool chech_connectivity()
	{
		return true;
	}
	friend class dice;
};