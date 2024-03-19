								/*数据结构练习*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//动态申请，sizeof

//顺序表的基本操作

#define ok 1
#define error 0
#define overflow -2//溢出
#define initsize 50//初始数组长度
#define addsize 20//每次追加的长度

typedef int status;//返回状态
typedef int elemtype;//数据类型

typedef struct list
{
	elemtype* elem;//数组首元素递增
	int len;//数组元素个数
	int listsize;//开辟的数组长度
}qlist;

status initlist(qlist& L)
{
	elemtype* p = (elemtype*)malloc(sizeof(elemtype) * initsize);
	if (p == NULL)
	{
		printf("空间申请失败!\n");
		exit(overflow);
	}

	L.elem = p;
	L.listsize = initsize;
	L.len = 0;
	return ok;
}

status input(qlist& L)
{
	printf("请输入顺序表的元素个数\n");
	int n;
	scanf("%d", &n);

	L.len = n;
	int i;

	printf("请输入顺序表中%d个元素：\n", n);
	//法一：普通写法
	//for (i = 0; i < L.len/**/; i++)
	//	scanf("%d", L.elem + i);/*把平时的数组名更改为L.elem*/

	//法二：指针写法
	int* p = L.elem;
	for (p; p < L.elem + L.len/**/; p++)
		scanf("%d", p);/**/

	return ok;
}

status output(qlist L)//不改变L,不传引用
{
	printf("打印顺序表元素:\n");
	int i;

	//法一：普通写法
	//for (i = 0; i < L.len; i++)
	//	printf("%d ", L.elem[i]);
	//printf("\n");

	//法二：指针写法
	int* p = L.elem;
	for (p; p < L.elem + L.len/**/; p++)
		printf("%d ", *p);/**/
	printf("\n");

	return ok;
}

status insert(qlist& L)
{
	printf("请输入你要插入的位置：\n");

	int n;
	scanf("%d", &n);

	if (n < 1 || n > L.len)
	{
		printf("插入位置错误!\n");
		return error;
	}

	int i;
	for (i = L.len - 1; i >= n - 1; i--)//插入：从后向前
		L.elem[i + 1] = L.elem[i];

	printf("请输入你要插入的数据！\n");
	int m;
	scanf("%d", &m);
	L.len++;/**/
	L.elem[n - 1] = m;
	printf("插入成功!\n");

	return ok;
}

status dele(qlist& L)
{
	printf("请输入要删除的位置！\n");
	int n;
	scanf("%d", &n);

	if (n < 1 || n > L.len)
	{
		printf("位置错误，删除失败!\n");
		exit(overflow);
	}

	int i;
	for (i = n - 1; i < L.len - 1; i++)
		L.elem[i] = L.elem[i + 1];

	L.len--;/**/
	printf("删除成功！\n");
	return ok;
}

int main()
{
	qlist L;
	initlist(L);
	input(L);
	output(L);
	insert(L);//插入元素
	output(L);

	dele(L);//删除元素
	output(L);

	return 0;
}