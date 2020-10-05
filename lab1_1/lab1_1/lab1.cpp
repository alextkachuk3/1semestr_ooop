#include <iostream>
#include <string>
#include <sstream>
#include "Graph.h"
#include "Dice.h"

using namespace std;

void dice_menu()
{
	vector<int> my_dices;
	dice Dice;
	Dice.add_dice({ {1, 1}, {2,1} });
	Dice.add_dice({ {3, 1}, {4,1} });
	Dice.add_dice({ {5, 1}, {6,1} });
	Dice.add_dice({ {7, 1}, {8,1} });
	Dice.add_dice({ {9, 1}, {10,1} });
	Dice.add_dice({ {11, 1}, {12,1} });
	Dice.add_dice({ {13, 1}, {14, 1}, {15, 1}, {16, 1}, {17, 1}, {18, 1}, {19, 1}, {20, 1} });
	while (true)
	{
		int op;
		cout << "1.Add dice" << endl << "2.Print my dice" << endl << "3.Edit chance" << endl << "4.Print all chance" << endl << "5.Back" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			system("cls");
			Dice.print_all_dice();
			cout << "Select dice" << endl;
			int index;
			cin >> index;
			if (index > 6)
			{
				cout << "Wrong index!" << endl;
				break;
			}
			my_dices.push_back(index);
			break;
		}
		case 2:
		{
			system("cls");
			for (const auto& a : my_dices)
			{
				Dice.print_dice(a);
			}
			break;
		}
		case 3:
		{
			system("cls");
			int index;
				double new_chance;
			cout << "Enter index";
			cin >> index;
			cout << "Enter chance";
			cin >> new_chance;
			if (new_chance > 1 || new_chance < 0)
			{
				cout << "Wrong index" << endl;
				break;
			}
			Dice.change_chance(index, new_chance);
			break;
		}
		case 4:
		{

			system("cls");
			break;
		}
		case 5: 
		{
			system("cls");
			return;
		}
		default:
		{
			system("cls");
			cout << "Wrong operation!" << endl;
		}
		}
	}
}

void graph_int_menu()
{
	graph<int> Graph;
	while (true)
	{
		int op1 = 0, op2 = 0;
		cout << "1.Create new graph" << endl << "2.Edit graph" << endl << "3.Print graph" << endl << "4.Algorithms" << endl << "5.Back" << endl;
		cin >> op1;
		switch (op1)
		{
		case 1:
		{
			system("cls");
			while (op2 != 4)
			{
				cout << "1.Empty graph" << endl << "2.Use adjacency matrix" << endl << "3.Use adjacency list" << endl << "4.Back" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1:
				{
					Graph.clean();
					system("cls");
					cout << "New matrix created!" << endl;
					break;
				}
				case 2:
				{
					int count_tops;
					cout << "Enter count of tops" << endl;
					cin >> count_tops;
					cout << "Enter matrix" << endl;
					vector<vector<int>> matrix(count_tops, vector<int>(count_tops));
					for (auto& a : matrix)
					{
						for (auto& b : a)
						{
							cin >> b;
						}
					}
					Graph.adj_matrix(matrix);
					system("cls");
					cout << "New matrix created!" << endl;
					break;
				}
				case 3:
				{
					int count_tops;
					cout << "Enter count of tops" << endl;
					cin >> count_tops;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					system("cls");
					cout << "Enter list" << endl;
					vector<vector<int>> list(count_tops);
					for (int i = 0; i < count_tops; i++)
					{
						cout << "#" << i << ":";
						stringstream sn;
						string s;
						getline(cin, s);
						sn << s;
						while (sn && s.size())
						{
							int n;
							sn >> n;
							sn.ignore(1);
							list[i].push_back(n);
						}
					}
					Graph.adj_list(list);
					system("cls");
					cout << "New matrix created!" << endl;
					break;
				}
				case 4:
				{
					system("cls");
					op2 = 0;
					break;
				}
				default:
					system("cls");
					cout << "Wrong operation" << endl;
					break;
				}
				break;
			}
		}
		case 2:
		{
			system("cls");
			while (op2 != 4)
			{
				cout << "1.Add top" << endl << "2.Change top data" << endl << "3.Connect top" << endl << "4.Delete top" << endl << "5.Back" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1:
				{
					Graph.add_top();
					break;
				}
				case 2:
				{
					int num_t, new_data;
					cout << "Enter number of top:";
					cin >> num_t;
					cout << "Enter data:";
					cin >> new_data;
					Graph.change_data(num_t, new_data);
					break;
				}
				case 3:
				{
					int num_from, num_to;
					cout << "Enter number of top(from):";
					cin >> num_from;
					cout << "Enter number of top(to)";
					cin >> num_to;
					Graph.connect(num_from, num_to);
					break;
				}
				case 4:
				{

					break;
				}
				case 5:
				{
					system("cls");
					break;
				}
				default:
				{
					system("cls");
					cout << "Wrong operation" << endl;
					break;
				}
				}
				break;
			}
		}
		case 3:
		{
			Graph.print_graph();
			break;
		}
		case 4:
		{

			break;
		}
		case 5:
		{
			system("cls");
			return;
		}
		default:
		{
			system("cls");
			cout << "Wrong operation" << endl;
			break;
		}
		}
	}
}

void graph_vector_string_menu()
{

}

int main()
{
	while (true)
	{
		cout << "1.Dice" << endl << "2.Graph(int)" << endl << "3.Graph(vector<string>)" << endl << "4.Exit" << endl;
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			system("cls");
			dice_menu();
			break;
		}
		case 2:
		{
			system("cls");
			graph_int_menu();
			break;
		}
		case 3:
		{
			system("cls");
			graph_vector_string_menu();
			break;
		}
		case 4:	return 0;
		default:
		{
			system("cls");
			cout << "Wrong operation" << endl;
			break;
		}
		}
	}
}