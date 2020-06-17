#include <iostream>
#include <vector>
using namespace std;
int W[50][50];
int n[50][50] = {0,};
void warshall(int loop_max) {
	for (int cnt = 0; cnt < loop_max; cnt++) {
		for (int i = 0; i < loop_max; i++) {
			for (int j = 0; j < loop_max; j++) {
				if (W[i][cnt] == 1 && W[cnt][j] == 1) {
					W[i][j] = 1;
					n[i][j] = 1;
				}
			}
		}

		cout << endl << "W " << cnt << "\n";
		for (int i = 0; i < loop_max; i++) {
			for (int j = 0; j < loop_max; j++) {
				cout << W[i][j] << ' ';
			}
			cout << endl;
		}
	}

}
int main() {
	int loop_max;
	cout << "vertax :";
	cin >> loop_max;

	cout << "plz write Matrix info\n";
	for (int i = 0; i < loop_max; i++)
		for (int j = 0; j < loop_max; j++)
			cin >> W[i][j];
	cout << endl;
	warshall(loop_max);

	cout << endl << endl;
	cout << "final result(Warshall Algorithm) : " << endl;

	for (int i = 0; i < loop_max; i++) {
		for (int j = 0; j < loop_max; j++) {
			cout << n[i][j] << ' ';
		}
		cout << endl;
	}

}