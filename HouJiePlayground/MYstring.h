#pragma once
#include <iostream>

using namespace std;
//#ifndef __MYSTRING__
//#define __MYSTRING__
class MYString
{
public:
	MYString(const char* cstr);
	MYString(const MYString& str);//拷贝构造，接收与自己相同类型
	MYString& operator=(const MYString& str);//拷贝赋值
	~MYString();//析构函数

	int size() const { return strlen(m_data); }
	char* get_c_str() const { return m_data; }
private:
	char* m_data;
};

inline
MYString::MYString(const char* cstr = 0) {
	if (cstr) {
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

//拷贝构造
inline
MYString::MYString(const MYString& str) {
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);//直接取另一个object的private data（兄弟之间互为friend）
}

//拷贝赋值
inline
MYString& MYString::operator=(const MYString& str) {
	if (this == &str)
		return *this;//检测自我赋值

	delete[] m_data;//把自己已有的内容杀掉
	m_data = new char[strlen(str.m_data) + 1];//开辟新内容所需空间
	strcpy(m_data, str.m_data);//拷贝
	return *this;
}

MYString::~MYString() {
	delete[] m_data;
}

MYString operator + (const MYString& s1, const MYString& s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	
	char* concat_str = new char[len1 + len2 + 2];
	//MYString* concat_str;
	//concat_str = s1.get_c_str();
	
	//strcat(s1.get_c_str(), s2.get_c_str());
	memcpy(&concat_str, s1.get_c_str(), len1 * sizeof(char)+1);
	memcpy(&concat_str[len1*sizeof(char)+2], s2.get_c_str(), len2*sizeof(char)+1);
	return s1;
}
//#endif
