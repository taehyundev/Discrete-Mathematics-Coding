#include <iostream>
using namespace std;

int main() {
	cout << "A 행렬 : ";
	int A_i, A_j;
	cin >> A_i >> A_j; //위~ 아래 : i 왼쪽~오른쪽 : j
	cout << "B 행렬 : ";
	int B_i, B_j;
	cin >> B_i >> B_j;
	
	if (A_j == B_i) {

		int** A;
		int** B;
		int** temp;
		temp = new int* [B_i];
		A = new int* [A_i];
		B = new int* [B_i];
		int C_i = A_i;
		int C_j = B_j;
		//A값 입력
		cout << "A 행열 : " << A_i << " X " << A_j << endl;
		for (int i = 0; i < A_i; i++) {
			A[i] = new int[A_j];
			for (int j = 0; j < A_j; j++) {
				cin >> A[i][j];
			}
		}
		cout << "B 행열 : " << B_i << " X " << B_j << endl;
		//B값 입력
		for (int i = 0; i < B_i; i++) {
			B[i] = new int[B_j];
			temp[i] = new int[B_j];
			for (int j = 0; j < B_j; j++) {
				cin >> B[i][j];
				temp[i][j] = B[i][j];
			}
		}
		delete[] B;
		B = new int* [B_j];
		for (int i = 0; i < B_j; i++) {
			B[i] = new int[B_i];
			for (int j = 0; j < B_i; j++) {
				B[i][j] = i;
			}
			cout << endl;
		}

		for (int i = 0; i < B_j; i++) {
			for (int j = 0; j < B_i; j++) {
				B[i][j] = temp[j][i];
			}
		}
		int set = 0;
		int result = 0;
		for (int i = 0; i < A_i; i++) {
			for (int j = 0; j < B_j; j++) {
				for (int k = 0; k < A_j; k++) {
				 	result+=(A[i][k] * B[j][k]);
					
				}

				cout <<result<<" ";
				result = 0;
			}
			cout << endl;
		}
		cout << "행렬 완료";
		delete[] A;
		delete[] B;
		delete[] temp;
	}
	else {
		cout << "행렬의 곱을 시작할 수가 없습니다." << endl;
		main();
	}

}