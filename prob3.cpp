#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main() {

	// define x,h
	// y[n] = 1 (-3<=n<1), -1 (1<=n<5)
	int inp_y[8] = { 1,1,1,1,-1,-1,-1,-1 };
	// x[n] = -1 (n=-4,4), 1 (n=-2,2), 2 (n=-1,1), 3 (n=1)
	int ir_w[9] = { -1,0,1,2,3,2,1,0,-1 };

	ofstream n_axis_file;
	ofstream a_axis_file;
	n_axis_file.open("prob3_n_axis.txt");
	a_axis_file.open("prob3_a_axis.txt");

	// let be Wn[k] = y[k]*w[n-k]
	// 1. Wn[k] = w[n-k] (-3 <= k <= 4)
	cout << "-7 <= n < -3" << endl;
	for (int n = -7; n < -3; n++) {
		int y = 0;
		for (int k = -3; k <= n + 4; k++) {
			// first index of array is 0, but y[n] starts at n = -3, w[n] starts at -4
			// to resolve it, I add 3 and 4 at index of each array 
			// so that y[-3] means inp_y[0], w[-4] means ir_w[0]
			y += inp_y[k+3] * ir_w[n - k + 4];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		a_axis_file << y << endl;
	}
	cout << endl;

	// 1-2. Wn[k] = -w[n-k] (1 <= k <= n+4), Wn[k] = w[n-k] (-3 <= k <= 0)
	cout << "-3 <= n < 1" << endl;
	for (int n = -3; n < 1; n++) {
		int y = 0;
		for (int k = -3; k <= n + 4; k++) {
			y += inp_y[k+3] * ir_w[n - k + 4];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		a_axis_file << y << endl;
	}
	cout << endl;

	// 1.3. Wn[k] = -w[n-k] (1 <= k <= 4), Wn[k] = w[n-k] (n-4 <= k <= 0)
	cout << "1 <= n < 5" << endl;
	for (int n = 1; n < 5; n++) {
		int y = 0;
		for (int k = n - 4; k <= 4; k++) {
			y += inp_y[k+3] * ir_w[n - k + 4];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		a_axis_file << y << endl;
	}
	cout << endl;

	// 1-4. Wn[k] = -w[n-k] (n-4 <= k <= 4)
	cout << "5 <= n < 9" << endl;
	for (int n = 5; n < 9; n++) {
		int y = 0;
		for (int k = n - 4; k <= 4; k++) {
			y += inp_y[k+3] * ir_w[n - k + 4];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		a_axis_file << y << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
