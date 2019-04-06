#include "graph.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

Graph::Graph()
{
	_anzKnoten = 0;
	_nodes.clear();
}

Graph::~Graph()
{
	for (int i = 0; i < _nodes.size(); i++) {
		delete _nodes[i];
	}
	_nodes.clear();
}

GraphNode* Graph::GetNodeByKey(int key)
{
	for (int i = 0; i < _anzKnoten; i++)
	{
		GraphNode* currentNode = _nodes[i];
		if (currentNode->_key == key)
		{
			return currentNode;
		}
	}
	return nullptr;
}

// iterate all nodes and set _visited to false
void Graph::setAllUnvisited()
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		GraphNode* currentNode = _nodes[i];
		currentNode->_visited = false;
	}
}

//Check if all nodes are set to visited
bool Graph::checkVisited()
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		GraphNode* currentNode = _nodes[i];
		if (currentNode->_visited == false)
			return false;
	}
	return true;
}

bool Graph::init(std::string filename)
{
	Graph::~Graph();
	std::ifstream file;
	file.open(filename, std::ios_base::in);

	if (!file)
	{
		std::cout << "! Textdatei konnte nicht geoeffnet werden." << std::endl;
		return false;
	}
	else
	{
		std::string line;
		std::getline(file, line);
		std::istringstream iss(line);

		iss >> _anzKnoten;

		for (int i = 0; i < _anzKnoten; i++)
		{
			GraphNode* currentNode = new GraphNode(i);
			_nodes.push_back(currentNode);
		}

		while (std::getline(file, line))
		{
			std::istringstream edges(line);
			int from, value, to;
			if (!(edges >> from >> to >> value)) break; // error

			std::cout << "From: " << from << " To: " << to << " Value: " << value << std::endl;
			GraphNode* currentNode = GetNodeByKey(from);
			GraphNode* currentNeighbour = GetNodeByKey(to);

			//Hinrichrung:
			GraphNode::edge edge(currentNode, currentNeighbour, value);
			currentNode->_edges.push_back(edge);

			//Rückrichtung:
			GraphNode::edge backEdge(currentNeighbour, currentNode, value);
			currentNeighbour->_edges.push_back(backEdge);
		}
		return true;
	}
}

bool Graph::print()
{
	if (_nodes.empty()) return false;
	// Print with Node ID: 1st neighbour, 2nd neighbour ...
	for (int i = 0; i < _anzKnoten; i++)
	{
		GraphNode* currentNode = _nodes[i];
		std::cout << currentNode->_key << std::endl;
		for (int k = 0; k < currentNode->_edges.size(); k++)
		{
			if (!currentNode->_edges.empty()) {
				GraphNode::edge currentEdge = currentNode->_edges[k];
				std::cout << " -> " << currentEdge.to->_key << " [" << currentEdge.value << "] " << std::endl;
			}
		}
		std::cout << std::endl;

	}

	return true;
}

bool Graph::breadthSearchIter(int s)
{
	std::vector<GraphNode*> edgeTo(_anzKnoten, 0);
	std::queue<GraphNode*> q;

	GraphNode * start = GetNodeByKey(s);
	start->_visited = true; // Markiert den Startknoten ...
	q.push(start); // ... und legt ihn in die Wartschlange ab. (enqueue)

	while (!q.empty())
	{
		GraphNode * v = q.front(); // Speichert den nächsten Knoten ...
		std::vector<GraphNode::edge> v_edges = v->_edges; // ... und seine Kanten ... 
		q.pop(); // ... und entfernt ihn aus der Warteschlange. (dequeue)

		for (int i = 0; i < v_edges.size(); i++)
		{
			GraphNode * w = v_edges[i].to; // Läuft alle verbundenen Knoten von w ab.

			if (!w->_visited) // Speichert für jeden unmarkierten Nachbarknoten ...
			{
				edgeTo[w->_key] = v; // ... die letzte Kante auf einem kürzesten Pfad, ...
				w->_visited = true; // ... markiert sie, da der Pfad bekannt ist, ...
				q.push(w); // und fügt sie der Warteschlange hinzu. (enqueue)
			}
		}
	}

	bool allvisited = checkVisited();
	setAllUnvisited();

	return allvisited;
}

double Graph::prim(int startKey)
{
	double summe = 0.0; // Summiert die Kosten auf.
	std::queue<GraphNode::edge> mst; // MST-Kanten
	std::priority_queue<GraphNode::edge> pq; // Menge der Randkanten in PQ

	GraphNode * start = GetNodeByKey(startKey);
	if (start == nullptr)
	{
		std::cout << "! Startknoten exisitiert nicht" << std::endl; // Falls Startknoten nicht existiert, gebe Fehlermeldung ...
		return INFINITY; // ... und unendlich zurück.
	}
	start->_visited = true; // Markiere den Startknoten als besucht ...
	std::vector<GraphNode::edge> start_edges = start->_edges; // und speichere die Kanten vom Startknoten.

	for (int i = 0; i < start_edges.size(); i++) {
		if (!(start_edges[i].to->_visited)) pq.push(start_edges[i]); // Speichere die noch nicht besuchten Nachbarknoten in der PQ.
	}

	while (!pq.empty())
	{
		GraphNode::edge e = pq.top(); // Hole Kante mit geringstem Gewicht ...
		pq.pop(); // ... und lösche die Kante aus der PQ.

		GraphNode * v = e.to;
		GraphNode * w = e.from;

		if (v->_visited && w->_visited) continue; // Falls beide besucht wurden, überspringen.

		mst.push(e); // Füge die Kante zum MST ...
		summe += e.value; // ... und das Gewicht der Kante zu den Gesamtkosten hinzu.

		if (!v->_visited)
		{
			v->_visited = true;
			std::vector<GraphNode::edge> edges = v->_edges;

			for (int i = 0; i < edges.size(); i++) {
				if (!(edges[i].to->_visited)) pq.push(edges[i]);
			}
		}

		if (!w->_visited)
		{
			w->_visited = true;
			std::vector<GraphNode::edge> edges = w->_edges;

			for (int i = 0; i < edges.size(); i++) {
				if (!(edges[i].to->_visited)) pq.push(edges[i]);
			}
		}
	}
	setAllUnvisited();
	return summe;
}

double Graph::kruskal()
{
	double summe = 0.0; // Summiert die Kosten auf.
	std::priority_queue<GraphNode::edge> pq;
	std::queue<GraphNode::edge> mst;
	Graph::disJointSets ds(_anzKnoten);
	
	for (int i = 0; i < _anzKnoten; i++)
	{
		for (int j = 0; j < _nodes[i]->_edges.size(); j++)
		{
			pq.push(_nodes[i]->_edges[j]);
		}
	}

	while (!pq.empty())
	{
		GraphNode::edge e = pq.top();
		pq.pop();

		int v = e.from->_key;
		int w = e.to->_key;
		int set_v = ds.find(v);
		int set_w = ds.find(w);

		if (set_v != set_w)
		{
			mst.push(e);
			//std::cout << "Kante von " << &e.from << " nach " << &e.to << " mit dem Gewicht von " << e.value << " wurde hinzugefuegt" << std::endl;
			summe += e.value;
			//std::cout << "Aktuelle Summe: " << summe << std::endl << std::endl;
			ds.merge(set_v, set_w);
		}
	}

	return summe;
}

bool Graph::depthSearchRek(int startKey)
{
	depthSearchRek_intern(startKey);

	bool allvisited = checkVisited();
	setAllUnvisited();

	return allvisited;
}

bool Graph::depthSearchRek_intern(int startKey)
{
	GraphNode * start = GetNodeByKey(startKey);

	if (start == nullptr)
	{
		std::cout << "! Startknoten exisitiert nicht" << std::endl; // Falls Startknoten nicht existiert, gebe Fehlermeldung ...
		return false; // ... und false zurück.
	}

	start->_visited = true;
	GraphNode * w;

	for (int i = 0; i < start->_edges.size(); i++)
	{
		w = start->_edges[i].to;
		if (w->_visited == false)
		{
			std::cout << "starte mit w.key : " << w->_key << std::endl;
			depthSearchRek_intern(w->_key);
		}
	}

	for (int i = 0; i < _anzKnoten; i++)
	{
		if (_nodes[i]->_visited == false)
		{
			return false;
		}
	}
	return true;
}