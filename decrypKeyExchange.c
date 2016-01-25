#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void handleErrors(char * msg)
{
	puts("Oooh no!");
	puts(msg);
	exit(0);
}

///*
int encryptccm(unsigned char *message, unsigned char *key, unsigned char *IV,
	unsigned char *C, unsigned char *tag)
{
	int outlen;
	int ciphertext_len = 0;
	EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_EncryptInit_ex(&ctx, EVP_aes_256_ccm(), NULL, key, IV);
    if(1 != EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_CCM_SET_IVLEN, 7, NULL))
		handleErrors("set IV len to 7");

	// Set tag length 
	EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_CCM_SET_TAG, 14, NULL);
	if(1 != EVP_EncryptInit_ex(&ctx, NULL, NULL, key, IV))
		handleErrors("initialize key and IV");

	if(1 != EVP_EncryptUpdate(&ctx, NULL, &outlen, NULL, strlen(message)))
		handleErrors("provide total plaintext length");

	if(!EVP_EncryptUpdate(&ctx, C, &outlen, message, strlen(message)))
	{
               // Error
		puts("data encrypting..");
		return 0;
	}
	ciphertext_len += outlen;
	if(1 != EVP_EncryptFinal_ex(&ctx, C + outlen, &outlen))
		handleErrors("finalize encryption");
	ciphertext_len += outlen;
    if(1 != EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_CCM_GET_TAG, 14, tag))
		handleErrors("get the tag");

	return ciphertext_len;
}
int decryptccm(unsigned char *ciphertext, int ciphertext_len, unsigned char *tag, unsigned char *key, unsigned char *iv,
	unsigned char *plaintext)
{
	EVP_CIPHER_CTX *ctx;
	int len;
	int plaintext_len;
	int ret;

	/* Create and initialise the context */
	if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors("Create and initialise the context");

	/* Initialise the decryption operation. */
	if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_ccm(), NULL, NULL, NULL))
		handleErrors("Initialise the decryption operation.");

	/* Setting IV len to 7. Not strictly necessary as this is the default
	 * but shown here for the purposes of this example */
	if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_CCM_SET_IVLEN, 7, NULL))
		handleErrors("Setting IV len to 7. ");

	/* Set expected tag value. */
	if(1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_CCM_SET_TAG, 14, tag))
		handleErrors("Set expected tag value.");

	/* Initialise key and IV */
	if(1 != EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv))
		handleErrors("Initialise key and IV");


	/* Provide the total ciphertext length
	 */
	if(1 != EVP_DecryptUpdate(ctx, NULL, &len, NULL, ciphertext_len))
		handleErrors("rovide the total ciphertext length");



	/* Provide the message to be decrypted, and obtain the plaintext output.
	 * EVP_DecryptUpdate can be called multiple times if necessary
	 */
	ret = EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);

	plaintext_len = len;

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);

	if(ret > 0)
	{
		/* Success */
		return plaintext_len;
	}
	else
	{
		/* Verify failed */
		return -1;
	}
}
int main()
    
{
  // message goes in this variable:
	//unsigned char message[] = "This is not an easy project";
    struct stat st;
    unsigned char *C=malloc(1000);
    FILE *ff = fopen("cipher","rb");
     stat("cipher", &st);
 // printf("File size: %d bytes\n", st.st_size);
	int len= fread(C , 1, st.st_size, ff);
    unsigned char *ciphertext=malloc(strlen(C)+1);
   // int len= strlen(ciphertext);
	//unsigned char *C=malloc(strlen(ciphertext)+1);
	// ciphertext goes in this variable:
  
	//unsigned char *ciphertext=malloc(strlen(message)+1;
    puts(C);
	// key goes in this variable:
	unsigned char key[] = "25a1cf28a91ce985a683a34c03f824d31838bbe361953c3de5b78a3763b5efa8";
	// IV goes in this variable:
	unsigned char IV[] = "0102030405060708";
	// Tag will be written to this variable:
	unsigned char *tag = malloc(16);
	//Encryption:
	//encryptccm(message, key,IV,ciphertext, tag);
	/*Save the results in some files:*/
	//printf("ciphertext length = %d\n",len);
	//FILE* out = fopen("cipher", "wb");
	//fwrite(ciphertext, 1, len, out);
	//fclose(out);
	//out = fopen("tag1", "wb");
	//fwrite(tag, 1, 14, out); //tag is 14 bytes
	//fclose(out);
    
    FILE *fp = fopen("tag1","rb");
	int ReadTag= fread(tag , 1, len, fp);
    
        
   //  FILE *ff = fopen("cipher","rb");
	//int length= fread(cipertext , 1, len, ff);
    // printf("%d",length) ;
    
     /*End File IO stuff*/
    //Decryption:
    char plaintext[strlen(ciphertext)+1];
    plaintext[0] = 0;
    //Uncomment the following line to see program fail due to auth failure
    //tag[0] = 0;
    
	int result = decryptccm(C,len,tag,key,IV,plaintext);
   //// printf("%d",result);
	if (result>0) //success
		puts("successsss");
	else
		puts("faiiiilurrre!");
	puts(plaintext);
    
    
}