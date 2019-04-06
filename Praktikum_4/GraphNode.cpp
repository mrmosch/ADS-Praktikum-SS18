#include "graphnode.h"

GraphNode::GraphNode(int key)
{
	_key = key;
	_visited = false;
	_distance = 0.;
	_prev = nullptr;
	_edges.clear();
}

bool GraphNode::hasNeighbor(int neighborKey)
{
	for (int i = 0; i < _edges.size(); i++) {
		if (_edges[i].to->_key == neighborKey) {
			return true;
		}
	}
	return false;
}