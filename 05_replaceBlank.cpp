//面试题5: 替换空格
#include <iostream>
using namespace std;

void replaceBlank(char str[], int length) {
	if (str == nullptr || length <= 0) return;

	int originalLength = 0; //str的实际长度
	int numberOfBlank = 0;
	int i = 0;
	while (str[i] != '0') {
		++originalLength;
		if (str[i] == ' ')
			++numberOfBlank;
		++i;
	}

	int newLength = originalLength + numberOfBlank * 2; //把' '替换成'%20'的长度
	if (newLength > length) return; //防止内存溢出

	int indexOfOriginal = originalLength; //从右往左替换
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (str[indexOfOriginal] == ' ') {
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
			str[indexOfNew--] = str[indexOfOriginal];
		--indexOfOriginal;
	}
}

int main() {
	

	return 0;
}
