// SPN_encryption_decryption.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
# define Nr 4
using namespace std;

class TEXT {
public:
	short int digit[16];
	short int block[4];
};//To describe plaintext and Intermediate data
class SBOX {
public:
	short int block[16];
};
class PBOX {
public:
	short int order[16];
};

int main(int argc,char* argv[])
{
	if (argc != 2)
	{
		cout << "[ERROR] Usage:-e:encrypt;-d:decrypt;" << endl;
		return 0;
	}
	if (strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0)
	{
		cout << "[ERROR] Wrong Command" << "Usage:-e:encrypt;-d:decrypt;" << endl;
		return 0;
	}
	if (strcmp(argv[1], "-e") == 0)//encrypt process
	{
		cout << "[INFO] Start encrypt process" << endl;
		/*Load FIle:text*/
		ifstream  plain;
		plain.open("Source/plain.txt",  ios::in);
		if (!plain.is_open())
		{
			cout << "Error opening file:plain.txt"; 
			return 0;
		}
		char texttemp[16];
			plain.getline(texttemp, 16);//Standard File Load Process
	

	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
