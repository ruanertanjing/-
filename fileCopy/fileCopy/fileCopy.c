//���ã���һ���ļ����Ƶ�����һ���ļ�
// �ҵĳ����������fileCopy.c
//ʹ�÷��������ļ�������exe��β���ļ�(���ҵ�Ϊ����fileCopy.exe)�����򿪣�Ȼ������:fileCopy sourcefile destfile(sourcefile:�����Ƶ��ļ��� destfile��������sourcefile�����ݵ��ļ�)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	/*argc �� argv []
	�ڳ����У� main �������������������ͱ��� argc ���ַ�ָ������ argv []��
	argc �ĺ����ǳ���Ĳ�����������������
	argv []��ÿ��ָ��ָ�������е�һ���ַ�����
	���� argv [0]ָ���ַ���" copyFile . exe "��
	argv [1]ָ���ַ��� sourceFile ,
	argv [2]ָ���ַ��� destFile ��*/

	FILE* in, *out;//ע����ļ�����Ҫ���ļ�ָ��
	int ch;//ע����int��������char,��Ϊgetc�ķ���ֵ��int���ͣ�������char

	if (argc != 3)//ȷ��������������ȷ��
	{
		fprintf(stderr, "�밴��ȷ��ʽ���룺fileCooy.exe Դ�ļ��� Ŀ���ļ���\n");//һ������������fileCooy.exe Դ�ļ��� Ŀ���ļ���
		//srderr:��׼������
		/*int fprintf( FILE *stream, const char *format, ... );
		  fprintf()��������ָ����format(��ʽ)������Ϣ(����)����stream(��)ָ�����ļ�.
		  ���fprintf()����ʹ����Ϣ�����ָ�����ļ�*/

		exit(EXIT_FAILURE);
		//ͷ�ļ���stdlib.h
		//exit:ֱ�ӽ������򣬶�return:������һ����������
		//EXIT_FAILURE��ʵ�ʾ���#define EXIT_FAILURE 1����ʾ�쳣�˳�
		//EXIT_SUCCRSS:��ʾ��ȫ�˳�#define EXIT_SUCCESS 0
		//exit(1):������ִ���˳�����
		//exit(0):����ִ���˳�����

	}

	if (in = fopen(argv[1], "rb") == NULL)//������д��
	{
		fprintf(stderr, "�򲻿��ļ���%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (out = fopen(argv[2], "wb") == NULL)//�����ƶ�ȡ
	{
		fprintf(stderr, "�򲻿��ļ���%s\n", argv[2]);
		fclose(in);/*��ס�ر��ļ�*/
		exit(EXIT_FAILURE);
	}

	while (ch = getc(in) != EOF)
	{
		if (putc(ch, out) == EOF)
			break;
	}

	if (ferror(in))//����Ƿ�����Ϊ�������
	{
		fprintf(stderr, "��ȡ�ļ�����%s\n", argv[1]);
		fclose(in);
		exit(EXIT_FAILURE);
	}

	if (ferror(out))//����Ƿ�����Ϊ�������
	{
		fprintf(stderr, "д���ļ�����%s\n", argv[2]);
		fclose(in);
		exit(EXIT_FAILURE);
	}

	printf("�����ļ��ɹ�\n");
	fclose(in);

	return 0;
}