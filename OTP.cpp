#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <stdlib.h>


//int transfer (int,int);

using namespace std;
int main(int argc, char *argv[]) {
	string line, keyLine;
	string cipher, plain,message;
	int p=0, k=0;

	
	ifstream plaintext ("plaintext.txt");// read a file
	ofstream keyline ("keyfile.txt");// write a file
		if (keyline.good())
			{
			keyline<<arc4random();// im using the random number generator to store as a key
				keyline.close()	;		
				}
	ifstream key("keyfile.txt");
		if (plaintext.good()&&key.good())
	{
		getline(plaintext,line);
		getline(key,keyLine);
		
			cout<<line<<endl;
			plaintext.close();
			cout<<"This is the OTP "<< keyLine<<endl;
			keyline.close();
			
	}
	
		
		for (p=0;p<line.length();p++)
		{
			cipher.push_back(line[p]^keyLine[k]);
		
			
				
		
			ofstream ciphertext;
			ciphertext.open("ciphertext.txt");
			if (ciphertext.good())
			{
				ciphertext<< cipher; 
				ciphertext.close();
			}

		
	}
	cout<<"Here is the encryption : " <<cipher<<endl;

	

ifstream ciphertext ("ciphertext.txt");
if (ciphertext.good()){
		getline(ciphertext,cipher);
		ciphertext.close();
	}
	
for (int c=0; c<cipher.length();c++){
	plain.push_back(cipher[c]^keyLine[k]);
		
}

ofstream outfile ("message.txt");
if (outfile.good()){
	outfile<<plain;
	outfile.close();
	
}
	
cout<<"Output the decryption : "<< plain<<endl;		

}

