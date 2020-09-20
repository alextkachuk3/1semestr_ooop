#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
	Graph<string> graph;
	int op1 = 0;
	int op2 = 0;
	while (op1 != 6)
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
					break;
				}
				case 2:
				{
					int count_tops;
					cout << "Enter count of tops" << endl;
					cin >> count_tops;
					vector<vector<int>> matrix(count_tops, vector<int>(count_tops));
					for (auto &a : matrix)
					{
						for (auto& b : a)
						{
							cin >> b;
						}
					}
					graph.adj_matrix(matrix);
					break;
				}
				case 3:
				{
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

			break;
		}
		default:
			system("cls");
			cout << "Wrong operation" << endl;
			break;
		}
	}
	return 0;
}