//作用：将一个文件复制到另外一个文件
// 我的程序代码名：fileCopy.c
//使用方法：在文件中找以exe结尾的文件(以我的为例：fileCopy.exe)，并打开，然后输入:fileCopy sourcefile destfile(sourcefile:被复制的文件名 destfile：复制了sourcefile的内容的文件)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	/*argc 与 argv []
	在程序中， main 函数有两个参数，整型变量 argc 和字符指针数组 argv []。
	argc 的含义是程序的参数数量，包含本身。
	argv []的每个指针指向命令行的一个字符串，
	所以 argv [0]指向字符串" copyFile . exe "。
	argv [1]指向字符串 sourceFile ,
	argv [2]指向字符串 destFile 。*/

	FILE* in, *out;//注意对文件操作要用文件指针
	int ch;//注意是int，而不是char,因为getc的返回值是int类型，而不是char

	if (argc != 3)//确保参数个数的正确性
	{
		fprintf(stderr, "请按正确格式输入：fileCooy.exe 源文件名 目标文件名\n");//一共三个参数：fileCooy.exe 源文件名 目标文件名
		//srderr:标准错误流
		/*int fprintf( FILE *stream, const char *format, ... );
		  fprintf()函数根据指定的format(格式)发送信息(参数)到由stream(流)指定的文件.
		  因此fprintf()可以使得信息输出到指定的文件*/

		exit(EXIT_FAILURE);
		//头文件：stdlib.h
		//exit:直接结束程序，而return:返回上一层主调函数
		//EXIT_FAILURE：实际就是#define EXIT_FAILURE 1：表示异常退出
		//EXIT_SUCCRSS:表示安全退出#define EXIT_SUCCESS 0
		//exit(1):非正常执行退出程序
		//exit(0):正常执行退出程序

	}

	if (in = fopen(argv[1], "rb") == NULL)//二进制写入
	{
		fprintf(stderr, "打不开文件：%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (out = fopen(argv[2], "wb") == NULL)//二进制读取
	{
		fprintf(stderr, "打不开文件：%s\n", argv[2]);
		fclose(in);/*记住关闭文件*/
		exit(EXIT_FAILURE);
	}

	while (ch = getc(in) != EOF)
	{
		if (putc(ch, out) == EOF)
			break;
	}

	if (ferror(in))//检查是否是因为错误结束
	{
		fprintf(stderr, "读取文件错误：%s\n", argv[1]);
		fclose(in);
		exit(EXIT_FAILURE);
	}

	if (ferror(out))//检查是否是因为错误结束
	{
		fprintf(stderr, "写入文件错误：%s\n", argv[2]);
		fclose(in);
		exit(EXIT_FAILURE);
	}

	printf("复制文件成功\n");
	fclose(in);

	return 0;
}