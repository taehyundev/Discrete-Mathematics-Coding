#include <iostream>
#include <queue>
using namespace std;
int vertax, edge;
int map[50][50];
bool visit[50];

void DFS(int beginVertax) {
	cout << beginVertax<< " ";
	visit[beginVertax] = true;
		for (int i = 1; i <= vertax; i++) {
			if (map[beginVertax][i] == 1 && visit[i] == false) {
				visit[i] = true;
				DFS(i);
			}
		}
	
}
int main() {
	cin >> vertax >> edge;
	// 0 ~ Vertax
	
	//방향성 Graph
	for (int i = 0; i < edge; i++) {
		int x, y; 
		cin >> x >> y;
		map[x][y] = 1;
	}

	DFS(1);
}
