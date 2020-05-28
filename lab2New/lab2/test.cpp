#include "AES.cpp"

int main(){
	unsigned char a[] = 
	{
		0x1a,0x91,0xf7,0x20,
		0x5e,0x45,0x67,0x06,
		0xa2,0x5b,0x66,0xde,
		0x5f,0x14,0x59,0x88,
		'\0'
	};
	
	char b[] = 
	{
		0x73,0x74,0x72,0x69,
		0x6e,0x67,0x20,0x32,
		0x20,0x65,0x6e,0x63,
		0x72,0x79,0x70,0x74,
		'\0'
	};
	
	string key;
	string text;
	
	for(int i = 0;i < 16;i++){
		key.push_back(a[i]);
		
		text.push_back(b[i]);
	}
	
	cout << "input text : " << endl<< text << endl;
	
	AES obj (key,AES::KeySize::AES128);	
	
	obj.Encrypt(text);
	string cipherText = obj.GetCipherText();
	cout << "Encrypt=>cipherText: "<< endl << cipherText << endl;
	
	obj.Decrypt(cipherText);
	string plainText = obj.ToString();
	cout << "Decrypt=>plainText: "<< plainText << endl;
	
	return 0;
}
