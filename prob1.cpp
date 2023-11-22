#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main() {

	// define x,h
	// x[n] = 1 (0<=n<=4)
	int inp_x[5] = { 1,1,1,1,1 };
	// h[n] = 1 (0<=n<=2)
	int ir_h[3] = { 1,1,1 };

	ofstream n_axis_file;
	ofstream y_axis_file;
	n_axis_file.open("prob1_n_axis.txt");
	y_axis_file.open("prob1_y_axis.txt");
	
	// Let be Wn[k] = x[k]*h[n-k]
	// 1. Wn[k] = 1 (0 <= k <= n), y[n] = n + 1 (0<=n<2)
	cout << "0 <= n < 2" << endl;
	for (int n = 0; n < 2; n++) {
		int y = 0;
		for (int k = 0; k <= n; k++) {
			y += inp_x[k] * ir_h[n-k];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// 2. Wn[k] = 1 (n-2 <= k <= n), y[n] = 3 (2<=n<5)
	cout << "2 <= n < 5" << endl;
	for (int n = 2; n < 5; n++) {
		int y = 0;
		for (int k = n - 2; k <= n; k++) {
			y += inp_x[k] * ir_h[n-k];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// 3. Wn[k] = 1 (n-2 <= k <= 4), y[n] = 7-n (5<=n<7)
	cout << "5 <= n < 7" << endl;
	for (int n = 5; n < 7; n++) {
		int y = 0;
		for (int k = n - 2; k <= 4; k++) {
			y += inp_x[k] * ir_h[n-k];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	system("pause");
	return 0;
}
