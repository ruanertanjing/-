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


////��̬��Ա����
//
//class Person
//{
//public:
//	static int m;
//};
//
//int Person::m = 1;
//
//void test()
//{
//	Person p;
//	
//	cout << p.m << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//int main()
//{
//	string s = "abcfsfaggse";
//	int pos1 = s.find("ag");
//	int pos2 = s.rfind("ag");
//
//	cout << pos1 << endl << pos2 << endl;
//	return 0;
//}


//thisָ���ʹ��
class People
{
public:
	People(int age)
	{
		this->age = age;
	}
	People& addage(People p)
	{
		age += p.age;
		return *this;
	}

	int age;
};

int main()
{
	People p1(10);

	People p2(10);

	p2.addage(p1).addage(p1).addage(p1).addage(p1);
	cout << p2.age << endl;
	return 0;
}