#include <iostream>
#include <cstring>

using namespace std;

//void fun(int& a)
//{
//	cout << "���ú���fun(int a)" << endl;
//}
//
//void fun(const int& a)
//{
//	cout << "���ú���fun(const int a)" << endl;
//}
//
//int main()
//{
//	const int a = 10;
//	fun(a);
//	return 0;
//}


//��Ŀ������һ��ѧ���࣬����ѧ��������ѧ�ţ����ҿ������롢���

//class STU/*��������һ����*/
//{
//	//����Ȩ��
//public:
//	//����
//	string name;
//	string num;
//
//	void print()
//	{
//		cout << name << ' ' << num << endl;
//	}
//};
//
//int main()
//{
//	//ʵ��������
//	STU s1;
//	
//	string name;
//	cin >> name;
//	s1.name = name;
//
//	string num;
//	cin >> num;
//	s1.num = num;
//
//	s1.print();
//	return 0;
//}


//��̬��Ա����

class Person
{
public:
	static int m;
};

int Person::m = 1;

void test()
{
	Person p;
	
	cout << p.m << endl;
}

int main()
{
	test();
	return 0;
}