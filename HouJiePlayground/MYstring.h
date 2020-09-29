#pragma once
#include <iostream>

using namespace std;
//#ifndef __MYSTRING__
//#define __MYSTRING__
class MYString
{
public:
	MYString(const char* cstr);
	MYString(const MYString& str);//�������죬�������Լ���ͬ����
	MYString& operator=(const MYString& str);//������ֵ
	~MYString();//��������

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

//��������
inline
MYString::MYString(const MYString& str) {
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);//ֱ��ȡ��һ��object��private data���ֵ�֮�以Ϊfriend��
}

//������ֵ
inline
MYString& MYString::operator=(const MYString& str) {
	if (this == &str)
		return *this;//������Ҹ�ֵ

	delete[] m_data;//���Լ����е�����ɱ��
	m_data = new char[strlen(str.m_data) + 1];//��������������ռ�
	strcpy(m_data, str.m_data);//����
	return *this;
}

MYString::~MYString() {
	delete[] m_data;
}

MYString operator + (const MYString& s1, const MYString& s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	
	//char* concat_str = new char[len1 + len2];
	//MYString* concat_str;
	//concat_str = s1.get_c_str();
	
	strcat(s1.get_c_str(), s2.get_c_str());
	//memcpy(&concat_str, s1.get_c_str(), len1 * sizeof(char));
	//memcpy(&concat_str[len1*sizeof(char)], s2.get_c_str(), len2*sizeof(char));
	return s1;
}
//#endif
