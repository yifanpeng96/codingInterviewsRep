//面试题7: 重建二叉树
#include <iostream>
using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//int* preorder 即 int preorder[] , 传入的是数组首元素的地址
BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
	//前序遍历的第一个值是根结点
	int rootValue = startPreorder[0];
	//新建一个二叉树结点
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreorder == endPreorder) {
		if (startInorder == endInorder && *startPreorder == *endPreorder)
			return root;
		else
			throw exception("Invalid input.");
	}

	//在中序遍历中找到根结点的值
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw exception("Invalid input.");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	
	//构建左子树
	if (leftLength > 0)
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	//构建右子树
	if (leftLength < endPreorder - startPreorder)
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);

	return root;
}

int main() {
	

	return 0;
}
