#include <stdio.h>
#define CodeLength 5
//#define PriKey 23
//#define PubKey 47
//#define modeN 120
//unsigned long long PriKey=23;
//unsigned long long PubKey=47;
//unsigned long long modeN=120;
unsigned long long PriKey=2683;
unsigned long long PubKey=83809747;
unsigned long long modeN=201128400;


unsigned long long SquareMod(unsigned long long data,unsigned long long square, unsigned long long mod){
	//unsigned long long i,org_data;
	unsigned long long data2;
	//printf("start:%d %d\n",i,data);	
	//org_data=data;
	
	data2 = (data*data)%mod;
	
	if(square == 1){
		return data%mod;
	}
	
	if(square == 2){
		return data2;
	}
	
	if(square%2 == 1){
		return (SquareMod(data2, square/2, mod)*data)%mod;
	}
	else
	{
		return SquareMod(data2, square/2, mod);
	}
	
	/*
	for (i=1;i<square;i++){
		data=(data*data)%mod;
		square/=2;
		//printf("en: %d %d\n",i,data);		
	}
	return data;
	*/	
}

void decrypt(char *Ciphertext){
	int i;
	printf("Please wait for decryption\n");		
	for(i=0;i<CodeLength;i++){		
		Ciphertext[i]=SquareMod((unsigned long long)Ciphertext[i],PubKey, modeN);
	}
}
void encrypt(char *Plaintext){
	int i;
	printf("Please wait for encryption\n");		
	for(i=0;i<CodeLength;i++){		
		Plaintext[i]=SquareMod((unsigned long long)Plaintext[i],PriKey, modeN);
	}		
}

int main()
{
	char input[100];
	unsigned long long i=0, inputB[100];
	
	printf("please input data to incrypte\n");

	gets(input);
	puts(input);
	for(i=0;i<CodeLength;i++){
		inputB[i]=(unsigned long long) input[i];
		//printf("%d ", inputB[i]);		
	}	

	printf("\n");
	encrypt(inputB);
	printf("Ciphertext:");
	for(i=0;i<CodeLength;i++){
		printf("%x ", input[i]);
	}

	printf("\n");
	decrypt(inputB);
	printf("Plaintext:");
	for(i=0;i<CodeLength;i++){
		printf("%c", input[i]);
	}
	printf("\n");
}