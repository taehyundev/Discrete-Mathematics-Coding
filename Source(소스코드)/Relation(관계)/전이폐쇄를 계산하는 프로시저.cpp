#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int mR[100][100];
int ob_mR[100][100];
int temp[100][100];

void transMatrix(int loop_max) {
	for (int i = 0; i < loop_max; i++) {
		for (int j = 0; j < loop_max; j++) {
			temp[i][j] = mR[j][i];
		}
	}
	for (int i = 0; i < loop_max; i++) {
		for (int j = 0; j < loop_max; j++) {
			mR[i][j] = temp[i][j];
			//temp[i][j] == 0;
		}
	}
}
void matrixMutiple(int loop_max) {
	transMatrix(loop_max);
	int cnt = 0;
	bool check = false;
	for (int a = 0; a < loop_max; a++) {
		for (int i = 0; i < loop_max; i++) {
			for (int j = 0; j < loop_max; j++) {
				for (int z = 0; z < loop_max; z++) {
					//cout << ob_mR[i][z] << ", " << mR[j][z] << endl;

					if (ob_mR[i][z] == 1 && mR[j][z] == 1) {
						temp[i][cnt] = 1;
						check = true;
						break;
					}
				}
				if (!check) { 
					temp[i][cnt] = 0; 
				}

				check = false;
				cnt++;
				if (cnt == loop_max) {
					cnt = 0;
				}
			}
		}
		for (int i = 0; i < loop_max; i++) {
			for (int j = 0; j < loop_max; j++) {
				ob_mR[i][j] = temp[i][j];
				cout << ob_mR[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
	int loop_max;
	cout << "행과 열의 크기를 지정해주세요 >> ";
	cin >>loop_max;

	cout << "Matrix 정보를 입력해주세요\n";
	for (int i = 0; i < loop_max; i++) {
		for (int j = 0; j < loop_max; j++) {
			cin >> mR[i][j];
			ob_mR[i][j] = mR[i][j];
		}
	}
	matrixMutiple(loop_max);
	cout << "전이폐쇄 결과\n\n";
	for (int i = 0; i < loop_max; i++) {
		for (int j = 0; j < loop_max; j++) {
			cout << ob_mR[i][j] << ' ';
		}
		cout << endl;
	}
	/*
	1 0 1
	0 1 0
	1 1 0

	1 0 0
	0 1 1
	1 0 1

	1 0 1
	0 1 0
	1 1 0
	*/

}