#include <vector>
#include <fstream>

class GraphNode 
{
public:
	struct edge {
		GraphNode* from;
		GraphNode* to; //destination node
		double value; //edge weight
		//konstruktoren
		edge() {
			to = nullptr;
			value = 0.0;
		}
		edge(GraphNode* a, GraphNode* b, double weight)
		{
			from = a;
			to = b; 
			value = weight;
		}
		bool operator<(const edge& comp) const
		{
			return value > comp.value;
		}
	};
	//might be useful
	GraphNode(int key);
	bool hasNeighbor(int neighborKey);
	edge getEdgeByNeighborkey(int key);

	int _key;
	std::vector<edge> _edges;
	bool _visited;
	int _component;
	double _distance;
	GraphNode *_prev;
};