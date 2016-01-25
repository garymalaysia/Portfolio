#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <openssl/md5.h>
#include <cstring>

using namespace std;


int print_md5_sum(char *a,char *hash) 
{
	unsigned char result[MD5_DIGEST_LENGTH];
	int i;
	char buf[100],md5[100];
		
	for(i=0; i < MD5_DIGEST_LENGTH; i++)
	{
		sprintf(hash+2*i, "%02x", hash[i]);// we use a[i] instead of unsigned char result.
		
					}
		return 0;
}
void get_salt_string(string &s, int leng);

int main()
{
	
	string k,line,enc,a;
	
	cout<<"Enter your password: ";
	cin >> a;

char digest[2*MD5_DIGEST_LENGTH+1];
	
	print_md5_sum(strdup((a.c_str())),digest);// converting string to char*
	k=(digest);
	
	
	ofstream passCheck ("passwordCheck.txt");
	if (passCheck.good()){
		passCheck<<a;
		passCheck.close();
	}
	

	cout<<endl;
	get_salt_string( a, a.length());
	cout<<endl;
	cout<<"Your entry of the Salted pasword :"<<k<<endl;
	cout<<endl;
	
	ofstream saltedVer("saltNmd5Ver.txt");
	if(saltedVer.good()){
			
	saltedVer<<k; 
		}
	saltedVer.close();
	
	ifstream password ("saltNmd5.txt");
	ifstream check("saltNmd5Ver.txt");
	if (password.good()&&check.good())
	{
		getline(password,enc);
		getline(check,line);
		
					
			if(enc==line)
				cout<<"\t*** ACCESS GRANTED ***\n\n";
			else 
				cout<<"\t*** ACCESS DENIED ***\n\n";
		
	}
	password.close();
	check.close();
}


void get_salt_string( string &s, int leng)
{
	string num,line;
	char *num1;
	int devrnd;
		
	ifstream saltCheck("randomSalt.txt");
	
		if (saltCheck.good()){
			
		getline (saltCheck,num);
		num1=strdup((num.c_str()));
		cout<<"Your salt is: "<<num<<endl;
		cout<<"Your Password and Salt is :"<<num<<s<<endl;
		


		saltCheck.close();
		
}
		

}	
		

