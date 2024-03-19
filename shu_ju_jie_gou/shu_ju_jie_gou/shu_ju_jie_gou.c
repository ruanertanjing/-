//顺序表的基本操作

#define ok 0
#define error
#define overflow 0
#define initsize 50
#define addsize 20

typedef int status;
typedef int elemtype;
typedef struct list
{
	elemtype* l;//数组首元素递增
	int len;//数组元素个数
	int listsize;//开辟的数组长度
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
	cout << "请输入顺序表的元素个数" << endl;

}

int main()
{
	qlist L;
	initlist(L);
	input(L);
	return 0;
}