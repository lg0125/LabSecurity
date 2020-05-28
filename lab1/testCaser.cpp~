#include"caesarCipher.h"
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

int main(){
	string input,output;
	int choice = 0;

	while(choice != 2){
		cout << endl << "Press 1:Encrypt/Decrypt" << endl << "Press 2:quit "<< endl;
		
		try{
			cin >> choice;

			if(choice != 1 && choice != 2){
				throw "Incorrect Choice";
			}
		}catch(const char* chc){
			cerr << "Incorrect Choice "<<endl;
			return 1;
		}

		if(choice == 1){
			int key;

			try{
				cout << "Chose key value(a number between 1 - 26):";

				cin >> key;

				cin.ignore();

				if(key < 1 || key > 26){
					throw "Incorrect key";
				}
			}catch(const char* K){
				cerr << "Incorrect key value chosen "<<endl;
				return 1;
			}
			

			try{
				cout << endl << "lowerCase letter for encrypt"<<endl <<"upperCase letter for decrypt" << endl;
				
				cout << "Enter cipherTest: ";
				getline(cin,input);

				for(int i = 0;i < input.size(); i++){
				
					//if(!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z')) throw "Incorrecr String";
				
				}
			}catch(const char* str){
				cerr << "may have some digit or special symbols "<<endl;
				cerr << "put only alphabets "<<endl;
				return 1;
			}

			for(unsigned int x = 0;x < input.length();x++){
				output += caesar(input[x],key);
			}

			cout << output << endl;
			output.clear();

		}
	
	}

}
