//面试题8: 二叉树的下一个节点
#include <iostream>
using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
    if (pNode == nullptr)
        return nullptr;

    BinaryTreeNode* pNext = nullptr;
    //若一个节点有右子树, 那么它的下一个节点就是它右子树中的最左子节点
    if (pNode->m_pRight != nullptr) {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    }
    //若节点没有右子树且有父节点
    else if (pNode->m_pParent != nullptr) {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        //若节点是父节点的右子节点, 那么要一直向上遍历, 直到找到其下一个节点
        while (pParent != nullptr && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        //若节点是父节点的左子节点, 那么它的下一个节点就是父节点
        pNext = pParent;
    }
    //若节点没有右子树且没有父节点, 那么它没有下一个节点, 为nullptr
    return pNext;
}

int main() {
	

	return 0;
}
