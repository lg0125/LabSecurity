#include "NewPolyalphabeticCipher.h"
#include "EndPolyalphabeticCipher.h"
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

int main(){
	string input,output,key;
	int choice = 0;

	while(true){
		cout << "----------------" << endl;
		cout << "1:Encrypt "<<endl
		     	<<"2:Decrypt "<<endl
			<<"3:EndDecrypt "<<endl
			<<"4:quit"<<endl;
		cout << "----------------" << endl;
		
		try{
			cin >> choice;
			cin.ignore();

			if(choice != 1 && choice != 2 && choice != 3 && choice != 4){
				throw "Incorrect Choice";
			}
		}catch(const char* chc){
			cerr << "Incorrecr Choice "<< endl;
			return 1;
		}
		
		if(choice == 4) break;
		
		try{
			cout << endl << "Enter cipher text:";
			getline(cin,input);
				
			for(int i = 0;i < input.size();i++){
				if( (!(input[i] >= 'a'&& input[i] <= 'z')) && (!(input[i] >= 'A' && input[i] <= 'Z')) && (!(input[i] == ' ')) ){
					throw "Incorrect string ";
				}
			}
		}catch(const char* str){
			cerr <<"input string have some digits or special sysbol"
				 <<endl;
			cerr << "please enter only alphabets" << endl;
			return 1;
		}
	
		if(choice == 1 || choice == 2){
			
			cout << "Enter Key(alphabets/words):";
			getline(cin,key);

			if(choice == 1){
				Encrypt(input,output,key);
				cout<<endl<<"Cipher text:"<<output<<endl;
			}else{
				Decrypt(input,output,key);
				cout<<endl<<"Plain text:"<<output<<endl; 
			}
			
		}else if(choice == 3){
			
			transform(input.begin(),input.end(),input.begin(),::tolower);
			
			getKey(input);
			
			print();
			
			getAns(input);
			
			cout << endl;
		}
		
		input.clear();
		output.clear();
		key.clear();
	}
	return 0;
}
