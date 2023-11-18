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
	ofstream a_axis_file;
	n_axis_file.open("prob2_n_axis.txt");
	a_axis_file.open("prob2_a_axis.txt");


	// 1. w[k] = 1 (0 <= k <= n+5), a[n] = n+6 (-5<=n<-1)
	cout << "-5 <= n < -1" << endl;
	for (int n = -5; n < -1; n++) {
		int a = 0;
		for (int k = 0; k <= n+5; k++) {
			// first index of array is 0, but x[n] starts at n = -5
			// to resolve it, I add 5 at index of array 
			// so that x[-5] means ir_x[0]
			a += inp_z[k] * ir_x[n-k+5];
		}
		cout << "a[" << n << "] = " << a << endl;
		n_axis_file << n << endl;
		a_axis_file << a << endl;
	}
	cout << endl;

	// 1-2. w[k] = 1 (0 <= k <= 3), w[k] = 2 (4 <= k <= n+5), a[n] = 2n+8 (-1<=n<1) 
	cout << "-1 <= n < 1" << endl;
	for (int n = -1; n < 1; n++) {
		int a = 0;
		for (int k = 0; k <= n+5; k++) {
			a += inp_z[k] * ir_x[n-k+5];
		}
		cout << "a[" << n << "] = " << a << endl;
		n_axis_file << n << endl;
		a_axis_file << a << endl;
	}
	cout << endl;

	// 2. w[k] = 1 (n-1 <= k <= 3), w[k] = 2 (4 <= k <= n+5), a[n] = n+9 (1<=n<4) 
	cout << "1 <= n < 4" << endl;
	for (int n = 1; n < 4; n++) {
		int a = 0;
		for (int k = n - 1; k <= n+5; k++) {
			a += inp_z[k] * ir_x[n-k+5];
		}
		cout << "a[" << n << "] = " << a << endl;
		n_axis_file << n << endl;
		a_axis_file << a << endl;
	}
	cout << endl;

	// 3. w[k] = 1 (n-1 <= k <= 3), w[k] = 2 (4 <= k <= 8), a[n] = -n+15 (4<=n<5)
	cout << "4 <= n < 5" << endl;
	for (int n = 4; n < 5; n++) {
		int a = 0;
		for (int k = n - 1; k <= 8; k++) {
			a += inp_z[k] * ir_x[n-k+5];
		}
		cout << "a[" << n << "] = " << a << endl;
		n_axis_file << n << endl;
		a_axis_file << a << endl;
	}
	cout << endl;

	// 3-2. w[k] = 2 (n-1 <= k <= 8), a[n] = -2n+20 (5<=n<10)
	cout << "5 <= n < 10" << endl;
	for (int n = 5; n < 10; n++) {
		int a = 0;
		for (int k = n - 1; k <= 8; k++) {
			a += inp_z[k] * ir_x[n-k+5];
		}
		cout << "a[" << n << "] = " << a << endl;
		n_axis_file << n << endl;
		a_axis_file << a << endl;
	}
	
	return 0;
}
