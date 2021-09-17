//面试题6: 从尾到头打印链表
#include <iostream>
using namespace std;

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

//递归本质上是一个栈结构
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr)
			PrintListReversingly_Recursively(pHead->m_pNext);
		cout << pHead->m_nKey << " ";
	}
}

int main() {
	

	return 0;
}
