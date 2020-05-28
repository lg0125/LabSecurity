#define word unsigned int 
#define byte unsigned char
 
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

class AES
{
	vector<word> ExpandedKey;
	int Nk; //width of key block
	int Nr; //number of round
	int Nb; //block size
	static const byte S_Box[256];
	static const byte Si_Box[256];
	static const byte Rcon[30];
	static const byte ColMixMatrix[4][4];
	static const byte InvColMixMatrix[4][4];
	static const byte AlogTable[256];
	static const byte LogTable[256];
	string cipherText;
	byte state[4][4];
	
	byte Mul(byte a,byte b);
	void MixColumns();
	void ShiftRows();
	void SubBytes();
	byte SubByte(byte oneByte);
	word SubWord(word val);
	word RotWord(word val);
	
	void InvMixColumns();
	void InvShiftRows();
	byte InvSubByte(byte oneByte);
	void InvSubBytes();

	void AddRoundKey(int roundNo);
	void KeyExpansion(string key);
	

   public:
	enum KeySize {AES128 = 128,AES192 = 192,AES256 = 256};

	AES(string key,int bitSize);
	~AES();
	void Encrypt(string plainText);
	string GetCipherText();
	void Decrypt(string cipherText);
	string ToString();
};

