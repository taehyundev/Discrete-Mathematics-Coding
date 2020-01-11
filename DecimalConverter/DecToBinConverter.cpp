#include <iostream>
#include <string.h>
using namespace std;

int main() {
	cout << "10 -> 2진수, 2진수 입력 : ";
	int dec;
	int temp[100] = {-1,};
	int cnt= 0;
	cin >> dec;
	int before_dec = dec;
	int i = 0;
	while (1) {
		if (dec > 1) {
			temp[i] = dec % 2;
			dec = dec / 2;

			cnt++;
		}
		else {
			temp[i] = 1;
			cnt++;
			break;
		}
		i++;
	}
	cout << "dec : " << before_dec << "(10)  -> Bin : ";
	for (int i =cnt-1; i != -1; i--) {
		if (temp[i] != -1) {
			cout << temp[i] << " ";
		}
	}
	cout << "(2)";
	
	
}