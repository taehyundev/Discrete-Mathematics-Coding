#include <iostream>
using namespace std;
int arr[5] = { 3,2,4,1,5 };
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

		for (int x = 0; x < 5; x++) {
			cout << arr[x] << ' ';
		}
		cout << endl<<endl;

	}
	cout << "ÃÖÁ¾°ª";
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}

}