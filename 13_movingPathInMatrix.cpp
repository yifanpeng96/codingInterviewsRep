//面试题13: 机器人的运动范围
#include <iostream>
using namespace std;

int movingCount(int threshold, int rows, int cols) {
	if (threshold < 0 || rows <= 0 || cols <= 0) return 0;

	bool* visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; ++i)
		visited[i] = false;

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;
	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited) {
	int count = 0;
	//check()判断机器人是否能进入坐标为(row, col)的方格
	if (check(threshold, rows, cols, row, col, visited)) {
		visited[row * cols + col] = true;

		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited) {
	//getDigitSum()计算数的各位之和
	if (row >= 0 && row < rows && col >= 0 && col < cols && 
		getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
		return true;

	return false;
}

int getDigitSum(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int main() {
	

	return 0;
}
