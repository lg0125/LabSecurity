#include<cstdio>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;

char vigenere_table[26][26] = {
	'A','B','C','D','E','F','G','H','I','J','K',
	'L','M','N','O','P','Q','R','S','T','U','V',
	'W','X','Y','Z',
	'B','C','D','E','F','G','H','I','J','K','L',
	'M','N','O','P','Q','R','S','T','U','V','W',
	'X','Y','Z','A',
	'C','D','E','F','G','H','I','J','K','L','M',
	'N','O','P','Q','R','S','T','U','V','W','X',
	'Y','Z','A','B',
	'D','E','F','G','H','I','J','K','L','M','N',
	'O','P','Q','R','S','T','U','V','W','X','Y',
	'Z','A','B','C',
	'E','F','G','H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W','X','Y','Z',
	'A','B','C','D',
	'F','G','H','I','J','K','L','M','N','O','P',
	'Q','R','S','T','U','V','W','X','Y','Z','A',
	'B','C','D','E',
	'G','H','I','J','K','L','M','N','O','P','Q',
	'R','S','T','U','V','W','X','Y','Z','A','B',
	'C','D','E','F',
	'H','I','J','K','L','M','N','O','P','Q','R',
	'S','T','U','V','W','X','Y','Z','A','B','C',
	'D','E','F','G',
	'I','J','K','L','M','N','O','P','Q','R','S',
	'T','U','V','W','X','Y','Z','A','B','C','D',
	'E','F','G','H',
	'J','K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z','A','B','C','D','E',
	'F','G','H','I',
	'K','L','M','N','O','P','Q','R','S','T','U',
	'V','W','X','Y','Z','A','B','C','D','E','F',
	'G','H','I','J',
	'L','M','N','O','P','Q','R','S','T','U','V',
	'W','X','Y','Z','A','B','C','D','E','F','G',
	'H','I','J','K',
	'M','N','O','P','Q','R','S','T','U','V','W',
	'X','Y','Z','A','B','C','D','E','F','G','H',
	'I','J','K','L',
	'N','O','P','Q','R','S','T','U','V','W','X',
	'Y','Z','A','B','C','D','E','F','G','H','I',
	'J','K','L','M',
	'O','P','Q','R','S','T','U','V','W','X','Y',
	'Z','A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N',
	'P','Q','R','S','T','U','V','W','X','Y','Z',
	'A','B','C','D','E','F','G','H','I','J','K',
	'L','M','N','O',
	'Q','R','S','T','U','V','W','X','Y','Z','A',
	'B','C','D','E','F','G','H','I','J','K','L',
	'M','N','O','P',
	'R','S','T','U','V','W','X','Y','Z','A','B',
	'C','D','E','F','G','H','I','J','K','L','M',
	'N','O','P','Q',
	'S','T','U','V','W','X','Y','Z','A','B','C',
	'D','E','F','G','H','I','J','K','L','M','N',
	'O','P','Q','R',
	'T','U','V','W','X','Y','Z','A','B','C','D',
	'E','F','G','H','I','J','K','L','M','N','O',
	'P','Q','R','S',
	'U','V','W','X','Y','Z','A','B','C','D','E',
	'F','G','H','I','J','K','L','M','N','O','P',
	'Q','R','S','T',
	'V','W','X','Y','Z','A','B','C','D','E','F',
	'G','H','I','J','K','L','M','N','O','P','Q',
	'R','S','T','U',
	'W','X','Y','Z','A','B','C','D','E','F','G',
	'H','I','J','K','L','M','N','O','P','Q','R',
	'S','T','U','V',
	'X','Y','Z','A','B','C','D','E','F','G','H',
	'I','J','K','L','M','N','O','P','Q','R','S',
	'T','U','V','W',
	'Y','Z','A','B','C','D','E','F','G','H','I',
	'J','K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X',
	'Z','A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T','U',
	'V','W','X','Y'
};

void Decrypt(string in,string &out,string k){
	int i = 0;

	for(string::iterator it = in.begin(); it != in.end();it++){
		if((*it) != ' '){
			int column = toupper(k[i % k.length()]) - 'A';
			int row;
			for(row = 0;row < 26;row++){
				if(vigenere_table[row][column] == *it) break;
			}
			out += 'A' + row;
			i++;
		}else{
			out += ' ';
		}
		
	}
}

void Encrypt(string in,string &out,string k){
	int i = 0;
	for(string::iterator it = in.begin(); it != in.end();it++){
		if((*it) != ' '){
			int row = toupper(*it) - 'A';
			int column = toupper(k[i % k.length()])	- 'A';		
			out += vigenere_table[row][column];
			i++;
		}else{
			out += ' ';
		}
		
	}
}


