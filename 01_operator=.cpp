#include <iostream>
using namespace std;

class CMyString {
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

private:
	char* m_pData;
};

//赋值运算符函数
//把返回值类型声明为该类型的引用 CMyString& , 因为这样才可以连续赋值
//传入参数应声明为常量引用 const CMyString& , 若不是则从形参到实参会调用一次拷贝构造函数
CMyString& CMyString::operator=(const CMyString& str) {
	//若不判断传入参数和当前实例是否为同一实例, 在释放实例自身内存时会出现严重问题
	if(this == &str)
		return *this;//this指代 CMyString 的一个对象的指针

	//先释放实例自身已有的内存, 不然会出现内存泄漏
	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

int main() {
	

	return 0;
}
