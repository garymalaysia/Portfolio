#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void handleErrors(char * msg)
{
	puts("Oooh no!");
	puts(msg);
	exit(0);
}

int encryptccm(unsigned char *message, unsigned char *key, unsigned char *IV,
	unsigned char *ciphertext, unsigned char *tag)
{
	int outlen;
	int ciphertext_len = 0;
	EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_EncryptInit_ex(&ctx, EVP_aes_256_ccm(), NULL, key, IV);
    if(1 != EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_CCM_SET_IVLEN, 7, NULL))
		handleErrors("set IV len to 7");

	/* Set tag length */
	EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_CCM_SET_TAG, 14, NULL);
	if(1 != EVP_EncryptInit_ex(&ctx, NULL, NULL, key, IV))
		handleErrors("initialize key and IV");

	if(1 != EVP_EncryptUpdate(&ctx, NULL, &outlen, NULL, strlen(message)))
		handleErrors("provide total plaintext length");

	if(!EVP_EncryptUpdate(&ctx, ciphertext, &outlen, message, strlen(message)))
	{
               /* Error */
		puts("data encrypting..");
		return 0;
	}
	ciphertext_len += outlen;
	if(1 != EVP_EncryptFinal_ex(&ctx, ciphertext + outlen, &outlen))
		handleErrors("finalize encryption");
	ciphertext_len += outlen;
    if(1 != EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_CCM_GET_TAG, 14, tag))
		handleErrors("get the tag");

	return ciphertext_len;
}

int main()
{
	// message goes in this variable:
	
    unsigned char message[] = "This is gary. Expecte us. ";
	// ciphertext goes in this variable:
  
	unsigned char *ciphertext=malloc(1000);
    //puts(ciphertext)
	// key goes in this variable:
	unsigned char key[] = "25a1cf28a91ce985a683a34c03f824d31838bbe361953c3de5b78a3763b5efa8";

	// IV goes in this variable:
	unsigned char IV[] = "0102030405060708";
	// Tag will be written to this variable:
	unsigned char *tag = malloc(16);
	//Encryption:
	int len = encryptccm(message, key,IV,ciphertext, tag);
    
	/*Save the results in some files:*/
	printf("ciphertext length = %d\n",len);
	FILE* out = fopen("cipher", "wb");
	fwrite(ciphertext, 1, len, out);
	fclose(out);
	out = fopen("tag1", "wb");
	fwrite(tag, 1, 14, out); //tag is 14 bytes
    puts(ciphertext);
	fclose(out);
}