#include<iostream>
#include<unordered_map>
#include<list>
#include<map>
#include<queue>
using namespace std;
template <typename T>
class graph {
	unordered_map<T, list<T>> g;
public:
	void addedge(T x, T y) {

		g[x].push_back(y);
	}
	//Using BFS
	void Topological_Sort() {
		// first we have compute indegree of every node
		unordered_map<T, int>indegree;

		//I will iterate over the whole graph and
		// i will increase the count of indegree of  all nodes that come in list of any node

		for (pair<T, list<T>> p : g) {
			for (T nbrs : g[p.first]) {
				indegree[nbrs]++;
			}
			if (indegree.count(p.first) == 0)
				indegree[p.first] = 0;
		}

		queue<T> q;
		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}


		unordered_map<int, bool> visited;

		while (!q.empty()) {
			T node = q.front();
			cout << node << endl;
			q.pop();
			//iterate over nbrs of node and decreament their indegree as one dependency is over from them after printing node
			for (T nbr : g[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0)
					q.push(nbr);
			}
		}
	}

	//Using DFS

	void dfs_one_component(T src, unordered_map<T, bool> &visited, list<T>& order) {
		visited[src] = true;

		for (T nbr : g[src]) {
			if (visited[nbr] == false) {
				dfs_one_component(nbr, visited, order);
			}

		}

		order.push_front(src);
		return;

	}
	void Topological_Sort(T src) {
		unordered_map<T, bool> visited;
		list<T> order;
		for (pair<T, list<T>> x : g) {
			//now x is pair of map
			// x.first will be key (Data type--T)
			// x.second will be value(Data type--List<T>)
			visited[x.first] = false;
		}

		for (pair<T, list<T>> x : g) {
			if (visited[x.first] == false) {
				dfs_one_component(x.first, visited, order);
			}
		}
		for (auto node : order )
			cout << node << endl;
	}



};

int main() {
	graph<string> G;
	G.addedge("Python", "DataProcessing");
	G.addedge("Python", "PyTorch");
	G.addedge("Python", "ML Basics");
	G.addedge("DataProcessing", "ML Basics");
	G.addedge("ML Basics", "Deep Learning");
	G.addedge("PyTorch", "Deep Learning");
	G.addedge("Deep Learning", "Face Recognition");
	G.addedge("Data Set", "Face Recognition");

	//Topological sort is only for directed Acyclic Graph(DAG)
	G.Topological_Sort(); //using BFS

	cout << endl;

	G.Topological_Sort("Python"); // using DFS

	return 0;
}