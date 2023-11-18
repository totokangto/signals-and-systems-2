#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"reverse.h"
using namespace std;

int main() {

	// define x,h
	int inp_x[5] = { 1,1,1,1,1 };
	int ir_h[3] = { 1,1,1 };
	int size_h = sizeof(ir_h) / sizeof(*ir_h);
	reverse(ir_h);

	ofstream n_axis_file;
	ofstream y_axis_file;
	n_axis_file.open("prob1_n_axis.txt");
	y_axis_file.open("prob1_y_axis.txt");

	// It's impossible to move array of h[n-k] from negative infinite to positive infinite 
	// so I'll use a trick, mapping
	// actual index of h : i -> h[i] 
	// index of ir_h : i - > ir_h[i-(n-size_h+1)] only if size of h <= size of x

	// w[k] = 1 (0 <= k <= n), y[n] = n+1 (0<=n<2)
	cout << "0 <= n < 2" << endl;
	for (int n = 0; n < 2; n++) {
		int y = 0;
		for (int k = 0; k <= n; k++) {
			// impulse response h[k] = array ir_h[k-n+2], size of h = 3
			// if n = 0, h[0] = ir_h[2] 
			// if n = 1, h[1] = ir_h[2], h[0] = ir_h[1]
			int map_num = k - (n - size_h + 1);
			y += inp_x[k] * ir_h[map_num];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// w[k] = 1 (n-2 <= k <= n), y[n] = 3 (2<=n<5)
	cout << "2 <= n < 5" << endl;
	for (int n = 2; n < 5; n++) {
		int y = 0;
		for (int k = n - 2; k <= n; k++) {
			// impulse response h[k] = array ir_h[k-n+2], size of h = 3
			// if n = 2, h[0] = ir_h[0], h[1] = ir_h[1], h[2] = ir_h[2]
			// if n = 3, h[1] = ir_h[0], h[2] = ir_h[1], h[3] = ir_h[2]
			// if n = 4, h[3] = ir_h[0], h[4] = ir_h[1], h[4] = ir_h[2]
			int map_num = k - (n - size_h + 1);
			y += inp_x[k] * ir_h[map_num];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}
	cout << endl;

	// w[k] = 1 (n-2 <= k <= 4), y[n] = 7-n (5<=n<7)
	cout << "5 <= n < 7" << endl;
	for (int n = 5; n < 7; n++) {
		int y = 0;
		for (int k = n - 2; k <= 4; k++) {
			// impulse response h[k] = array ir_h[k-n+2], size of h = 3
			// if n = 5, h[3] = ir_h[0], h[4] = ir_h[1]
			// if n = 6, h[4] = ir_h[0]
			int map_num = k - (n - size_h + 1);
			y += inp_x[k] * ir_h[map_num];
		}
		cout << "y[" << n << "] = " << y << endl;
		n_axis_file << n << endl;
		y_axis_file << y << endl;
	}

}