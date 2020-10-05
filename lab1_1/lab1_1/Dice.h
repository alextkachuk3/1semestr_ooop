#pragma once
#include "Graph.h"
class dice
{

public:
	void add_dice(const vector<pair<int, double>>& info)
	{
		vector<side> new_dice;
		for (const auto& a : info)
		{
			new_dice.push_back({ a.first, a.second });
		}
		dice_graph.add_top(new_dice);
		for (int i = 0; i < dice_graph.size() - 1; i++)
		{
			dice_graph.connect(dice_graph.size() - 1, i);
		}
	}
	void print_all_dice()
	{
		for (int i = 0; i < dice_graph.size(); i++)
		{

			cout << "#" << i << ": ";
			

			for (const auto& a : dice_graph.graph_map[i].links)
			{
				for (auto& b : a.link->data)
				{
					cout << b.number << "(" << (b.chance / (dice_graph.graph_map[i].data.size() + dice_graph.graph_map[i].links.size())) << ") ";
				}
			}

			for (const auto& a : dice_graph[i])
			{
				cout << a.number << "(" << (a.chance / (dice_graph.graph_map[i].data.size() + dice_graph.graph_map[i].links.size())) << ") ";
			}

			cout << endl;
		}
	}
	void print_dice(const int& index)
	{
		for (const auto& a : dice_graph.graph_map[index].links)
		{
			for (auto& b : a.link->data)
			{
				cout << b.number << "(" << (b.chance / (dice_graph.graph_map[index].data.size() + dice_graph.graph_map[index].links.size())) << ") ";
			}
		}

		for (const auto& a : dice_graph[index])
		{
			cout << a.number << "(" << (a.chance / (dice_graph.graph_map[index].data.size() + dice_graph.graph_map[index].links.size())) << ") ";
		}

		cout << endl;
	}
	void change_chance(const int& number, const double& chance)
	{
		for (int i = 0; i < dice_graph.graph_map.size(); i++)
		{
			for (auto& a : dice_graph[i])
			{
				if (a.number == number)
				{
					a.chance = chance;
				}
			}
		}
	}
	void sums()
	{
		for (int i = 0; i < dice_graph.graph_map.size(); i++)
		{
			for (int j = 0; j < dice_graph.graph_map[i].data.size(); j++)
			{
				//if (dice_graph.graph_map[i].data.
			}
		}
	}
private:
	class side
	{
	public:
		friend bool operator<(const side& lft, const side& rth)
		{
			return lft.number < rth.number;
		}
		side(const int& number, const double& chance)
		{
			this->number = number;
			this->chance = chance;
		};
		int number;
		double chance;
	};
	graph<vector<side>> dice_graph;
};