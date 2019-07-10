// SPN_encryption_decryption.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include <string>
# define Nr 4
using namespace std;

class TEXT {
public:
	short int digit[16];
	short int block[4];
};//To describe plaintext and Intermediate data

class BOX {
public:
	short int block[16];
};
int bin2oct(int* bin)
{
	return bin[0] * pow(2, 3) +bin[1]* pow(2, 2) + bin[2] * pow(2, 1) + bin[3] * pow(2, 0);
}

int XOR (int a, int b)
{
	if ((a && b) || (a == 0 && b == 0))
		return 0;
	else
		return 1;
}

int main(int argc,char* argv[])
{
	int i, j, k;
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
			plain.close();
			/*Dealing plaintext*/
			TEXT plaintext;
			for (i = 0; i < 16; i++)
			{
				plaintext.digit[i] =atoi( texttemp + i * sizeof(char));
			}
			for (j = 0; j < 4; j++)
			{
				plaintext.block[j] = bin2oct((int*)plaintext.digit);
				//plaintext.block[j] = plaintext.digit[j * 4] * pow(2, 3) + plaintext.digit[j * 4 + 1] * pow(2, 2) + plaintext.digit[j * 4 + 2] * pow(2, 1) + plaintext.digit[j * 4 + 3] * pow(2, 0);
			}
			cout << "[INFO] plain.txt read successfully\n digits:";
			for (j = 0; j < 16; j++)
			{
				cout << plaintext.digit[j];
			}
			cout << "\n Blocks:";
			for (j = 0; j < 4; j++)
			{
				cout << plaintext.block[j] << " ";
			}

		/*Load File:pbox*/
			ifstream pbox;
			pbox.open("Source / pbox.txt",  ios::in);
			if (!pbox.is_open())
			{
				cout << "Error opening file:pbox.txt";
				return 0;
			}
			BOX p;
			char pbtemp[64];
			pbox.getline(pbtemp, 64);
			pbox.close();
			int blockstr[16][4];
			for (i = 0; i < 16; i++)
			{
				blockstr[i][0] = atoi(&pbtemp[i * 4]);
				blockstr[i][1] = atoi(&pbtemp[i * 4+1]);
				blockstr[i][2] = atoi(&pbtemp[i * 4 +2]);
				blockstr[i][3] = atoi(&pbtemp[i * 4 + 3]);
			}
			for (j = 0; j < 4; j++)
			{
				p.block[j] = bin2oct((int*)blockstr[i]);
			}
			cout << "[SUCCESS] Pbox read successfully.digits:" << endl;

			for (i = 0; i < 16; i++)
			{
				cout << hex << p.block[i];
			}
			/*Load File:sbox*/
			ifstream sbox;
			sbox.open("Source/sbox.txt", ios::in);
			if (!sbox.is_open())
			{
				cout << "Error opening file:sbox.txt";
				return 0;
			}
			BOX s;
			char sbtemp[64];
			sbox.getline(sbtemp, 64);
			sbox.close();
			int blockstr0[16][4];
			for (i = 0; i < 16; i++)
			{
				blockstr0[i][0] = atoi(&sbtemp[i * 4]);
				blockstr0[i][1] = atoi(&sbtemp[i * 4 + 1]);
				blockstr0[i][2] = atoi(&sbtemp[i * 4 + 2]);
				blockstr0[i][3] = atoi(&sbtemp[i * 4 + 3]);
			}
			for (j = 0; j < 4; j++)
			{
				p.block[j] = bin2oct((int*)blockstr[i]);
			}//Switch Format
			cout << "[SUCCESS] Sbox read successfully.digits:" << endl;

			for (i = 0; i < 16; i++)
			{
				cout << hex << s.block[i];
			}
			/*Read roundkey*/
			ifstream round;
			round.open("Source /roundkey.txt", ios::in);
			if (!round.is_open())
			{
				cout << "Error opening file:roundkey.txt";
				return 0;
			}
			char roundtemp[32];
			round.getline(roundtemp, 32);
			int rk[32];
			for (i = 0; i < 32; i++)
			{
				rk[i] = atoi(&roundtemp[i]);
			}
			/*Error: atoi function's usage is wrong*/
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
