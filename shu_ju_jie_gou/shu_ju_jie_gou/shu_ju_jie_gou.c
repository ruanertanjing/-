//˳���Ļ�������

#define ok 0
#define error
#define overflow 0
#define initsize 50
#define addsize 20

typedef int status;
typedef int elemtype;
typedef struct list
{
	elemtype* l;//������Ԫ�ص���
	int len;//����Ԫ�ظ���
	int listsize;//���ٵ����鳤��
}*qlist;

status initlist(qlist& L)
{
	elemtype* p = (elemtype*)malloc(sizeof(elemtype) * initsize);
	if (p == NULL)
		exit(overflow);

	L.l = p;
	L.listsize = initsize;
	L.len = 0;
}

status input(qlist& L)
{
	cout << "������˳����Ԫ�ظ���" << endl;

}

int main()
{
	qlist L;
	initlist(L);
	input(L);
	return 0;
}