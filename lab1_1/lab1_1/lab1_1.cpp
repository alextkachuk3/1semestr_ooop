#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "Graph.h"

int main()
{
	Graph<string> graph;
	int op1 = 0;
	int op2 = 0;
	while (true)
	{
		cout << "1.Create new graph" << endl << "2.Edit graph" << endl << "3.Print graph" << endl << "4.Algorithms" << endl << "5.Exit" << endl;
		cin >> op1;
		switch (op1)
		{
		case 1:
		{
			system("cls");
			while (op2 != 4)
			{
				cout << "1.Empty graph" << endl << "2.Use adjacency matrix" << endl << "3.Use adjacency list" << endl << "4.Cancel" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1:
				{
					graph.clean();
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
					for (auto &a : matrix)
					{
						for (auto& b : a)
						{
							cin >> b;
						}
					}
					graph.adj_matrix(matrix);
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
					graph.adj_list(list);
					system("cls");
					cout << "New matrix created!" << endl;
					break;
				}
				case 4:
					break;
				default:
					system("cls");
					cout << "Wrong operation" << endl;
					break;
				}
				break;
			}
			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{

			break;
		}
		case 5:
		{
			return 0;
		}
		default:
		{
			system("cls");
			cout << "Wrong operation" << endl;
			break;
		}
		}
	}
	return 0;
}