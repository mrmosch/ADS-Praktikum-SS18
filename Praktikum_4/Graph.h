#include "GraphNode.h"
#include <deque>
#include <map>
#include <queue>
#include <iostream>
#include <string>
#include <vector>


class Graph
{
public:
	std::vector <GraphNode*> _nodes;
	Graph();
	~Graph();
	GraphNode* GetNodeByKey(int key);
	void setAllUnvisited();
	bool checkVisited();
	bool init(std::string path);

	//implement
	bool depthSearchRek(int startKey);
	bool depthSearchRek_intern(int startKey);
	bool breadthSearchIter(int startKey);
	bool print();
	//must be done
	double prim(int startKey);
	double kruskal();

	int _anzKnoten;
	bool _ger;
	bool _gew;

	struct disJointSets {
		int * parent;
		int * rank;
		int n;
		//konstruktor
		disJointSets() {
			n = 0;
			parent = nullptr;
			rank = nullptr;
		};
		disJointSets(int n)
		{
			this->n = n; 
			parent = new int[n + 1];
			rank = new int[n + 1];

			for (int i = 0; i <= n; i++)
			{
				rank[i] = 0;
				parent[i] = i; //every element is parent of itself
			}
		}

		int find(int u)
		{
			if (u != parent[u])
				parent[u] = find(parent[u]);
			return parent[u];
		}
		void merge(int x, int y)
		{
			//std::cout << "X Wert: " << x << " Y Wert: " << y << std::endl;
			x = find(x); y = find(y);

			if (rank[x] > rank[y]){
				parent[y] = x;
				//std::cout << "X Siegt: " << x << std::endl;
			}
			else {
				//if rank[x] <= rank[y]
				parent[x] = y;
				//std::cout << "Y siegt " << y << std::endl;
			}

			if (rank[x] == rank[y])
				rank[y]++;
		}
	};
};