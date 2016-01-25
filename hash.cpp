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
		sprintf(hash+2*i, "%02x", hash[i]);// we use a[i] instead of unsigned char result inorder to get the same hash output.

		//printf("%02x",buf[i]);
		//printf("%02x",a[i]);
					}
		
	//printf("%02x",buffer,k);
	
		//printf("md5 digest: %s\n", mdString);
		return 0;
}
void get_salt_string(string &s, int leng);

int main()
{
	string a;
	string k;
	
	cout<<"Enter your password: ";
	cin >> a;

char digest[2*MD5_DIGEST_LENGTH+1];
	//char example[] = a;//a sample word or phrase to hash
	print_md5_sum(strdup((a.c_str())),digest);// converting string to char*
	k=(digest);
	
	
	ofstream pass ("password.txt");
	if (pass.good()){
		pass<<a;
		pass.close();
	}
	

	cout<<endl;
	get_salt_string( a, a.length());
	cout<<endl;
	cout<<"Salted pasword is :"<<k<<endl;
	ofstream salted("saltNmd5.txt");
	if(salted.good()){
			
	salted<<k; 
		}
	salted.close();
}

void get_salt_string( string &s, int leng)
{
	string num,line;
	char *num1;
	int devrnd;
	ofstream ran ("randomSalt.txt");
	if (ran.good())
	{
		ran<<arc4random();  // im not using -> open("/dev/ramdom","r");
		
		
		line=devrnd;
		//cout<<"Your salt is: "<<devrnd<<endl;
		//cout<<"The Password and Salt is :"<<s<<devrnd;
		ran.close();		
	
	}
	
	ifstream salt("randomSalt.txt");
	
		if (salt.good()){
			
		getline (salt,num);
		num1=strdup((num.c_str()));
		cout<<"Your salt is: "<<num<<endl;
		cout<<"The Password and Salt is :"<<num<<s<<endl;
		//cout<<print_md5_sum(s, num1);



		salt.close();
		
}
		
//int devrnd = open("/dev/random");
	//assert(num != -1);
	/*
	int numbytesread = 0;
	char buf[100];
	while(numbytesread < leng)
	{
		numbytesread = numbytesread+ (num,buf+numbytesread,leng);
	}	
	//cout<<numbytesread;
int i; 
	for(i=0; i < numbytesread; i++)
	{
	sprintf(num1+2*i,"%02x", buf[i]);
}
	}
	
	int i;
	for(i = 0; i < leng; i++){
		(s+2*i,"%02x", buf[i]);
	}
	s[2*leng] = '\0';
*/	//close(devrnd);

}	
		
