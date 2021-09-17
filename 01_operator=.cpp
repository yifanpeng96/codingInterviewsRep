//面试题1: 赋值运算符函数
#include <iostream>
using namespace std;

class CMyString {
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();

private:
	char* m_pData;
};

//把返回值类型声明为应用, 并return自身的引用(*this), 才可以连续赋值
//把传入的参数声明为常量引用, 若不是则从形参到实参会调用一次拷贝构造函数
CMyString& CMyString::operator=(const CMyString& str) {
	//判断传入的参数和当前实例(*this)是不是同一个实例. 如果是, 在释放自身内存时会导致严重问题
	if (this == &str)
		return *this; //this指代 CMyString 的一个对象的指针

	//先释放实例自身已有的内存, 否则会出现内存泄露
	delete[] m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

int main() {
	

	return 0;
}
