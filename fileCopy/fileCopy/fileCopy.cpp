#include <iostream>
#include <fstream>//文件读写的流类（注意是类）

using namespace std;

int main(int argc, char* argv[])
{
	fstream fp("test.txt"/*文件名*/, ios::in | ios::out);//|:表示两种打开方式都可，这里是读取和写入的打开方式
	/*ios::in：以输入模式打开文件，只能进行读操作。
	ios::out：以输出模式打开文件，只能进行写操作。如果文件不存在，则创建一个新文件；如果文件已存在，则覆盖原有内容。
	ios::app：以追加模式打开文件，只能进行写操作。如果文件不存在，则创建一个新文件；如果文件已存在，则在原有内容的末尾追加新内容。
	ios::ate：以定位模式打开文件，可以进行读写操作。如果文件不存在，则创建一个新文件；如果文件已存在，则将文件指针定位到文件末尾。
	ios::binary：以二进制模式打开文件，可以进行读写操作。这个模式会忽略换行符等特殊字符，按照字节流的方式处理文件。
	ios::trunc：以截断模式打开文件，只能进行写操作。如果文件不存在，则创建一个新文件；如果文件已存在，则删除原有内容。
	*/
	//这里fp没有进行.open()的操作，说明是以默认的方式打开(构造函数的方式)

	if (!fp)//打开失败：若打开失败，则fp为NULL
	{
		cerr << "打开文件失败\n" << endl;
		return 0;
	}

	fp << "hello world";//写入fp指向的文件

	static char str[100];//防止str里的内容被改变

	fp.seekg(ios::beg);//将指针定位到文件头
	fp >> str;
	cout << str << endl;

	fp.close();/**/

	return 0;
}