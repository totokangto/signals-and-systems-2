#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main() {

	// define x,h
	// z[n] = 1 (0<=n<4), 2 (4<=n<9)
	int inp_z[9] = { 1,1,1,1,2,2,2,2,2};
	// x[n] = 1 (-5<=n<2)
	int ir_x[7] = { 1,1,1,1,1,1,1 };

	ofstream n_axis_file;
	ofstream y_axis_file;
	n_axis_file.open("prob2_n_axis.txt");
	y_axis_file.open("prob2_y_axis.txt");


	// 1. w[k] = 1 (0 <= k <= n+5), y[n] = n+6 (-5<=n<-1)
	cout << "-5 <= n < -1" << endl;
	for (int n = 0; n < 2; n++) {
		int y = 0;
		for (int k = 0; k <= n; k++) {
			// first index of array is 0, but x[n] starts at n = -5
			// to resolve it, I add 5 at index of array 
			// so that x[-5] means ir_x[0]
			y += inp_z[k] * ir_x[n-k+5];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// 1-2. w[k] = 1 (0 <= k <= 3), w[k] = 2 (4 <= k <= n+5), y[n] = 2n+8 (-1<=n<1) 
	cout << "-1 <= n < 1" << endl;
	for (int n = -1; n < 1; n++) {
		int y = 0;
		for (int k = 0; k <= n+5; k++) {
			y += inp_z[k] * ir_x[n-k+5];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// 2. w[k] = 1 (n-1 <= k <= 3), w[k] = 2 (4 <= k <= n+5), y[n] = n+9 (1<=n<4) 
	cout << "1 <= n < 4" << endl;
	for (int n = 1; n < 4; n++) {
		int y = 0;
		for (int k = n - 1; k <= n+5; k++) {
			y += inp_z[k] * ir_x[n-k+5];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// 3. w[k] = 1 (n-1 <= k <= 3), w[k] = 2 (4 <= k <= 8), y[n] = -n+15 (4<=n<5)
	cout << "4 <= n < 5" << endl;
	for (int n = 4; n < 5; n++) {
		int y = 0;
		for (int k = n - 1; k <= 8; k++) {
			y += inp_z[k] * ir_x[n-k+5];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// 3-2. w[k] = 2 (n-1 <= k <= 8), y[n] = -2n+20 (5<=n<10)
	cout << "5 <= n < 10" << endl;
	for (int n = 5; n < 10; n++) {
		int y = 0;
		for (int k = n - 1; k <= 8; k++) {
			y += inp_z[k] * ir_x[n-k+5];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	
	return 0;
}