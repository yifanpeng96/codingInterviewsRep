//面试题3: 数组中重复的数字
#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == nullptr || length <= 0) return false;

	for (int i = 0; i != length; ++i) {
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i != length; ++i) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}

			//交换 numbers[i] 和 numbers[numbers[i]]
			int tmp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[tmp] = tmp;
		}
	}

	return false;
}

int main() {
	

	return 0;
}
