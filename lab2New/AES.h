#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cmath>

class AES{
public:
    AES(unsigned char* key);
    virtual ~AES();
    unsigned char* Cipher(unsigned char* input);//16字节为一组
    unsigned char* InvCipher(unsigned char* input);
    void* Cipher(void* input, int length=0);//初始化过了
    void* InvCipher(void* input, int length);

private:
    unsigned char Sbox[256];
    unsigned char InvSbox[256];//1字节=8位
    unsigned char w[11][4][4];

    void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);
    unsigned char FFmul(unsigned char a, unsigned char b);

    void SubBytes(unsigned char state[][4]);
    void ShiftRows(unsigned char state[][4]);
    void MixColumns(unsigned char state[][4]);
    void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);

    void InvSubBytes(unsigned char state[][4]);
    void InvShiftRows(unsigned char state[][4]);
    void InvMixColumns(unsigned char state[][4]);
};