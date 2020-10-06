#pragma once
#include "Graph.h"
#include <iomanip>
class dice
{
public:
	void create_dice(const vector<pair<int, double>>& info)
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
	void add_dice(const int& index)
	{
		if (index > dice_graph.size())
		{
			throw invalid_argument("Wrong argument!");
		}
		else
		{
			my_dices.push_back(index);
		}
	}
	int dice_size(const int& index)
	{
		int size = dice_graph.graph_map[index].data.size();
		for (const auto& a : dice_graph.graph_map[index].links)
		{
			size += a.link->data.size();
		}
		return size;
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
					cout << b.number << "(" << (b.chance / (dice_graph.graph_map[i].data.size() * 1.0 + dice_graph.graph_map[i].links.size())) << ") ";
				}
			}

			for (const auto& a : dice_graph[i])
			{
				cout << a.number << "(" << (a.chance / (dice_graph.graph_map[i].data.size() * 1.0 + dice_graph.graph_map[i].links.size())) << ") ";
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
				cout << b.number << "(" << (b.chance / dice_size(index)) << ") ";
			}
		}

		for (const auto& a : dice_graph[index])
		{
			cout << a.number << "(" << (a.chance / dice_size(index)) << ") ";
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
	void print_my_dice()
	{
		for (const auto& a : my_dices)
		{
			print_dice(a);
		}
	}
	void get_comb(int pos, vector<int> cur, vector<vector<int>>& res)
	{
		for (auto& a : dice_num(my_dices[pos]))
		{
			if (pos == my_dices.size()-1)
			{
				cur.push_back(a);
				res.push_back(cur);
				cur.pop_back();
			}
			else
			{
				cur.push_back(a);
				get_comb(pos + 1, cur, res);
				cur.pop_back();
			}
		}
	}
	map<int, double> combination_sums()
	{
		int count_combination = 1;
		for (const auto& a: my_dices)
		{
			count_combination *= dice_size(a);
		}

		vector<vector<int>> comb;

		get_comb(0, {}, comb);

		for (int i = 0; i < count_combination; i++)
		{
			for (int j = 0; j < my_dices.size(); j++)
			{
				cout << setw(3) << comb[i][j];
			}
			cout << endl;
		}

		map<int, double> result;

		for (int i = 0; i < count_combination; i++)
		{
			int cur_sum = 0;
			double cur_chance = 1.0;
			for (int j = 0; j < my_dices.size(); j++)
			{
				for (const auto& a : dice_graph[my_dices[j]])
				{
					if (a.number == comb[i][j])
					{
						cur_sum += comb[i][j];
						cur_chance *= (a.chance * 1.0 / dice_size(my_dices[j]));
					}
				}
				for (const auto& a : dice_graph.graph_map[my_dices[j]].links)
				{
					for (const auto& b : a.link->data)
					{
						if (b.number == comb[i][j])
						{
							cur_sum += comb[i][j];
							cur_chance *= (b.chance * 1.0 / dice_size(my_dices[j]));
						}
					}
				}
			}
			result[cur_sum] += cur_chance;
		}
		return result;
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
	vector<int> dice_num(const int& index)
	{
		vector<int>result;
		for (const auto& a : dice_graph.graph_map[index].links)
		{
			for (const auto& b : a.link->data)
			{
				result.push_back(b.number);
			}
		}
		for (const auto& a : dice_graph.graph_map[index].data)
		{
			result.push_back(a.number);
		}
		return result;
	}
	graph<vector<side>> dice_graph;
	vector<int> my_dices;
};