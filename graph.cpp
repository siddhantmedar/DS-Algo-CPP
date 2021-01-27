#include <bits/stdc++.h>
using namespace std;

/*
Works only for a single graph and not for connected graphs

void DFS(vector<vector<int>> v, int start_vertex, vector<bool> &visited) {
	cout << start_vertex << endl;
	visited[start_vertex] = true;

	for (int i = 0; i < v.size(); i++) {
		if (v[start_vertex][i] == 1 && !visited[i]) DFS(v, i, visited);
	}
}

void BFS(vector<vector<int>> v, int start_vertex, vector<bool> &visited1) {
	queue<int> q;
	q.push(start_vertex);
	visited1[start_vertex] = true;

	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		cout << vertex << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[vertex][i] == 1 && !visited1[i]) {
				q.push(i);
				visited1[i] = true;
			}
		}
	}
}

*/

void DFS_CC(vector<vector<int>> v, int start_vertex, vector<bool> &visited) {
	cout << start_vertex << endl;
	visited[start_vertex] = true;

	for (int i = 0; i < v.size(); i++) {
		if (v[start_vertex][i] == 1 && !visited[i]) DFS_CC(v, i, visited);
	}
}

void DFS(vector<vector<int>> v) {
	vector<bool> visited(v.size(), false);

	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			count++;
			DFS_CC(v, i, visited);
		}
	}
	cout << "The total number of connected components are " << count << endl;
}

void BFS_CC(vector<vector<int>> v, int start_vertex, vector<bool> &visited1) {
	queue<int> q;
	q.push(start_vertex);
	visited1[start_vertex] = true;

	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		cout << vertex << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[vertex][i] == 1 && !visited1[i]) {
				q.push(i);
				visited1[i] = true;
			}
		}
	}
}

void BFS(vector<vector<int>> v) {
	vector<bool> visited(v.size(), false);
	int count = 0;
	for (int i = 0 ; i < v.size(); i++) {
		if (!visited[i]) {
			count++;
			BFS_CC(v, i, visited);
		}
	}
	cout << "The total number of connected components are " << count << endl;
}
int main() {
	int vertices, edges; cin >> vertices >> edges;

	vector<vector<int>> matrix(vertices, vector<int> (vertices, 0));

	for (int i = 1; i <= edges; i++) {
		int u, v; cin >> u >> v;
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}

	vector<bool> visited(vertices, false);

	/*
		cout << "DFS Traversal: " << endl;
		DFS(matrix, 0, visited);

		vector<bool> visited1(vertices, false);

		cout << "BFS Traversal: " << endl;
		BFS(matrix, 0, visited1);
	*/

	cout << "DFS Traversal: " << endl;
	DFS(matrix);

	cout << endl;

	cout << "BFS Traversal: " << endl;
	BFS(matrix);

	return 0;
}