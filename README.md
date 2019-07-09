# Cryptography

## Requirement

1. 原始SPN（教材上）算法的实现。
2. 对上述算法进行线性密码分析及差分密码分析（求出所有32比特密钥）。
3. 增强以上SPN的安全性（如增加分组的长度、密钥的长度、S盒、轮数等）。
4. 对原始及增强的SPN进行随机性检测，对检测结果进行说明。
5. 生成RSA算法的参数（如p、q、N、私钥、公钥等）。
6. 快速实现RSA（对比模重复平方、蒙哥马利算法和中国剩余定理）。
7. 利用椭圆曲线密码算法、HASH函数、压缩函数、对称加密算法实现一个类似PGP的文件加解密及完整性校验功能。
8. 构造彩虹表破解HASH函数

Project Set in 2019/07/09

1. 掌握线性、差分分析的基本原理与方法。
2. 体会位运算、预计算在算法快速实现中的作用。
3. 可借助OpenSSL、GMP、BIGINT、FLINT等大数运算库的低层基本函数（加、减、乘、除、模），实现过程中必须体现模重复平方、中国剩余定理和蒙哥马利算法的过程。内容(7)的算法可以直接调用OpenSSL或者其它密码库。
4. 了解和掌握彩虹表构造的基本原理和方法，能够设计和实现约化函数（Reduction  Function），针对特定的HASH函数构造彩虹表，进行口令破解，了解彩虹表的弱点及防范方法。
5. 独立完成课程设计内容，现场演示并讲解。
6. 课程设计完成后一周内，提交课程设计报告。

## SPN

### Crude SPN Design

#### Sample

**![1562677002997](C:\Users\POTAS\AppData\Roaming\Typora\typora-user-images\1562677002997.png)**

![1562677210824](C:\Users\POTAS\AppData\Roaming\Typora\typora-user-images\1562677210824.png)

![1562677224679](C:\Users\POTAS\AppData\Roaming\Typora\typora-user-images\1562677224679.png)

![1562677234595](C:\Users\POTAS\AppData\Roaming\Typora\typora-user-images\1562677234595.png)



1. Input(Input via File)
    - Plaintext  $x$ $(Len=4\times 4)$
    - Round Key Plate And the Generation Solution for Each Round 
    - S Box(Substitution)
    - P Box(Adjust the order)
    - Number of Round
2. Output
    - Ciphertext($4\times 4$)

#### Attention:

1. The Rule of Substitution : For a 4-digits array, switch in HEX and search for the output in HEX. In short, the process of substitution is executed in HEX. Example: if a group of BIN is `1011`=`0xB`, find the output is `0xE`=`1110`, so the process of the substitution is `0xB->0xE`, is`1011->1110`.
2. The Rule of  Whitening: Whiten x in the start of each Round. And whiten x in the END of FINAL Round.
3. It's unsafe to generate Round key like this sample. But it's easy to reach.

It seems easy to implement. To train C++,write it by C++.

And the following is steps of the encryption.

```c
const int Nr=4;

int* SPN_encryption(char* x,int RoundKey[],struct SBOX,struct PBOX)
{
	Whitening(x,Roungkey[i]);
	Substitution(x,SBOX);//In each group
	Replacement(x,PBOX);
//...	
}

```

#### Some Remarks

- There are 4 files as input: plain.txt,sbox.txt,pbox.txt,roundkey.txt
- Read these files as a constant rule
- Command line:   -e:encrypt;-d:decrypt;<!--If it's necessary?-->
- Open interface for the analysis.
- Use class to contain boxes and round key.

#### Files Rule

##### Plain text

A 16-digits array of BIN

##### Round Key

A 32-digits srray of BIN

##### SBOX

A 4*16-digits array of BIN; each block represents  order's substitution.

##### PBOX

A 16-digits array of BIN

