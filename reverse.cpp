#include "reverse.h"
void reverse(int h[]) {
	
	// array size
	int size = sizeof(h) / sizeof(*h);

	// ����� ����(size/2)���� ���ʰ� ������ �� �ٲ���
	for (int i = 0; i < size / 2; i++) {
		int temp = h[i];
		h[i] = h[size - i - 1];
		h[size - i - 1] = temp;
	}
}