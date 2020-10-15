#include <bits/stdc++.h>

using namespace std;

class Graph
{
	int V;
	vector<int> *adj; // It is an array of Vectors And vector<vector<int>> adj(v) is a vector of vectors

public:
	
	Graph(int V)
	{
		this->V = V;
		adj = new vector<int>[V];
	}
	void addEdge(int u, int v);

	void printArray(int v);

	void dfs(int s);

	void DFSUtil(int v, bool visited[]);
};
int main()
{
	cout << "Enter the number of Vertices : " << endl;
	int v;
	cin >> v;

	Graph G(v);
	G.addEdge(0, 1); //Since it is an Undirected graph, it enough to mention one edge//
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);

	G.printArray(v);

	cout << "DFS Traversal of the Graph is " << endl;

	G.dfs(2);
	
	return 0;
}

//FUNCTION DEFINITIOINS

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	//adj[v].push_back(u);
}

void Graph::printArray(int v)
{
	for(int i = 0; i < v; i++)
	{
		cout << "\n Adjacency List of vertex " << i 
			 << "\n head ";
		for(auto x : adj[i])
		{
			cout << "-> " << x;
		}
		printf("\n");
	}
}

void Graph::dfs(int s)
{
	//Creating an arn array of boolean type to store the vertices which are visited
	bool *visited = new bool[V];
	//We are making all the vertices to false i.e., we are not visited any vertices till now
	for(int i = 0; i < V; ++i)
		visited[i] = false;
	DFSUtil(s, visited);
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	vector<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if(!visited[*i])//i is an iterator which points to the particular element and *i gives us that element
			DFSUtil(*i, visited);
	}
}