//面试题4: 二维数组中的查找
#include <iostream>
using namespace std;

bool Find(int* matrix, int rows, int columns, int number) {
	bool found = false;

	if (matrix != nullptr && rows > 0 && columns > 0) {
		//从二维数组的右上角开始查找
		int row = 0, column = columns - 1;
		while (row < rows && column >= 0) {
			if (matrix[row * columns + column] == number) {
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
				--column;
			else
				++row;
		}
	}

	return found;
}

int main() {
	

	return 0;
}
