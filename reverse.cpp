#include "reverse.h"
void reverse(int h[]) {
	
	// array size
	int size = sizeof(h) / sizeof(*h);

	// 가운데를 기준(size/2)으로 왼쪽과 오른쪽 값 바꿔줌
	for (int i = 0; i < size / 2; i++) {
		int temp = h[i];
		h[i] = h[size - i - 1];
		h[size - i - 1] = temp;
	}
}