#include <iostream>
#include <cstring>

using namespace std;

//void fun(int& a)
//{
//	cout << "调用函数fun(int a)" << endl;
//}
//
//void fun(const int& a)
//{
//	cout << "调用函数fun(const int a)" << endl;
//}
//
//int main()
//{
//	const int a = 10;
//	fun(a);
//	return 0;
//}


//题目：创建一个学生类，包含学生姓名和学号，并且可以输入、输出

//class STU/*表明创建一个类*/
//{
//	//访问权限
//public:
//	//属性
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
//	//实例化对象
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


////静态成员变量
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


//this指针的使用
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