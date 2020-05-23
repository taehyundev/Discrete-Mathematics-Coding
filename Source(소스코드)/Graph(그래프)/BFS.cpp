#include <iostream>
#include <queue>
using namespace std;
int vertax, edge;
int map[50][50];
bool visit[50];

void BFS(int beginVertax) {
	queue<int> qStruct;
	qStruct.push(beginVertax);
	cout << qStruct.front()<< " ";
	visit[beginVertax] = true;
	while (!qStruct.empty()) {
		int pointS = qStruct.front();
		qStruct.pop();
		for (int i = 1; i <= vertax; i++) {
			if (map[pointS][i] == 1 && visit[i] == false) {
				cout << i << " ";
				qStruct.push(i);
				visit[i] = true;
			}
		}
	}
}
int main() {
	cin >> vertax >> edge;
	// 0 ~ Vertax
	
	//비방향성 Graph
	for (int i = 0; i < edge; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	BFS(1);
}
