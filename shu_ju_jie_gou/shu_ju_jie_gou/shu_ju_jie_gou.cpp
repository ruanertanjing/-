								/*���ݽṹ��ϰ*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//��̬���룬sizeof

//˳���Ļ�������
					/*���룬ɾ��*/
#define ok 1
#define error 0
#define overflow -2//���
#define initsize 50//��ʼ���鳤��
#define addsize 20//ÿ��׷�ӵĳ���

typedef int status;//����״̬
typedef int elemtype;//��������

typedef struct list
{
	elemtype* elem;//������Ԫ�ص���
	int len;//����Ԫ�ظ���
	int listsize;//���ٵ����鳤��
}qlist;

status initlist(qlist& L)
{
	elemtype* p = (elemtype*)malloc(sizeof(elemtype) * initsize);
	if (p == NULL)
	{
		printf("�ռ�����ʧ��!\n");
		exit(overflow);
	}

	L.elem = p;
	L.listsize = initsize;
	L.len = 0;
	return ok;
}

status input(qlist& L)
{
	printf("������˳����Ԫ�ظ���\n");
	int n;
	scanf("%d", &n);

	L.len = n;
	int i;

	printf("������˳�����%d��Ԫ�أ�\n", n);
	//��һ����ͨд��
	//for (i = 0; i < L.len/**/; i++)
	//	scanf("%d", L.elem + i);/*��ƽʱ������������ΪL.elem*/

	//������ָ��д��
	int* p = L.elem;
	for (p; p < L.elem + L.len/**/; p++)
		scanf("%d", p);/**/

	return ok;
}

status output(qlist L)//���ı�L,��������
{
	printf("��ӡ˳���Ԫ��:\n");
	int i;

	//��һ����ͨд��
	//for (i = 0; i < L.len; i++)
	//	printf("%d ", L.elem[i]);
	//printf("\n");

	//������ָ��д��
	int* p = L.elem;
	for (p; p < L.elem + L.len/**/; p++)
		printf("%d ", *p);/**/
	printf("\n");

	return ok;
}

status insert(qlist& L)
{
	printf("��������Ҫ�����λ�ã�\n");

	int n;
	scanf("%d", &n);

	if (n < 1 || n > L.len)
	{
		printf("����λ�ô���!\n");
		return error;
	}

	int i;
	for (i = L.len - 1; i >= n - 1; i--)//���룺�Ӻ���ǰ
		L.elem[i + 1] = L.elem[i];

	printf("��������Ҫ��������ݣ�\n");
	int m;
	scanf("%d", &m);
	L.len++;/**/
	L.elem[n - 1] = m;
	printf("����ɹ�!\n");

	return ok;
}

status dele(qlist& L)
{
	printf("������Ҫɾ����λ�ã�\n");
	int n;
	scanf("%d", &n);

	if (n < 1 || n > L.len)
	{
		printf("λ�ô���ɾ��ʧ��!\n");
		exit(overflow);
	}

	int i;
	for (i = n - 1; i < L.len - 1; i++)
		L.elem[i] = L.elem[i + 1];

	L.len--;/**/
	printf("ɾ���ɹ���\n");
	return ok;
}

void mysort(qlist& L)
{
	//�±�д��
	//int i, j, temp;
	//for (i = 0; i < L.len - 1; i++)
	//{
	//	for (j = i + 1; j < L.len; j++)
	//	{
	//		if (L.elem[i] > L.elem[j])
	//		{
	//			temp = L.elem[i];
	//			L.elem[i] = L.elem[j];
	//			L.elem[j] = temp;
	//		}
	//	}
	//}

	//ָ��д��
	int* p, *q, temp;
	for (p = L.elem;  p < L.elem + L.len - 1;  p++)
	{
		for (q = p + 1; q < L.elem + L.len; q++)
		{
			if (*p > *q)
			{
				temp = *p;
				*p = *q;
				*q = temp;
			}
		}
	}

	printf("����õ�˳���Ϊ��\n");
}

void mycombine(qlist L, qlist L1, qlist& L2)
{
	//ָ��д��
	//int* p, * q;
	//p = L.elem;
	//q = L1.elem;
	//int* k = p;

	//int len = 0;
	//while (p < L.elem + L.len && q < L1.elem + L1.len)
	//{
	//	while (*p < *q && p < L.elem + L.len)
	//	{
	//		L2.elem[len++] = *p;
	//		p++;
	//	}
	//	if (p < L.elem + L.len)
	//	{
	//		while (*q >= *p && q < L1.elem + L1.len)
	//		{
	//			L2.elem[len++] = *q;
	//			q++;
	//		}
	//	}

	//}

	////while ()

	//�±�д��
	int len = 0;
	int i = 0, j = 0, k;
	while (i < L.len && j < L1.len)
	{

		while (i < L.len && L.elem[i] <= L1.elem[j])
		{
			L2.elem[len++] = L.elem[i];
			if (L.elem[i] == L1.elem[j])
				j++;
			i++;
		}

		if (i < L.len)
		{
			while (j < L1.len && L1.elem[j] <= L.elem[i])
			{
				L2.elem[len++] = L1.elem[j];
				if (L.elem[i] == L1.elem[j])
					i++;

				j++;
			}
		}

	}

	if (i < L.len)
	{
		for (i; i < L.len; i++)
			L2.elem[len++] = L.elem[i];
	}
	else
	{
		for (j; j < L1.len; j++)
			L2.elem[len++] = L1.elem[j];
	}
	L2.len = len;
	//printf("%d\n", len);
}

int main()
{
	qlist L;
	initlist(L);
	input(L);
	//output(L);
	//insert(L);//����Ԫ��
	//output(L);

	//dele(L);//ɾ��Ԫ��
	//output(L);

	/*���򣬺ϲ�*/
	mysort(L);
	output(L);

	qlist L1;
	initlist(L1);
	input(L1);
	mysort(L1);
	output(L1);
	qlist L2;
	initlist(L2);
	mycombine(L, L1, L2);
	output(L2);
	return 0;
}