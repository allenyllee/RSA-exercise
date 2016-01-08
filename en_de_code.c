#include <stdio.h>
#define CodeLength 1
//#define PriKey 23
//#define PubKey 47
//#define modeN 120
//unsigned long long PriKey=23;
//unsigned long long PubKey=47;
//unsigned long long modeN=143;
unsigned long long PriKey=13049;
unsigned long long PubKey=163821337;
unsigned long long modeN=286512727;


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

void decrypt(unsigned long long *Ciphertext){
	int i;
	printf("Please wait for decryption\n");		
	for(i=0;i<CodeLength;i++){		
		Ciphertext[i]=SquareMod(Ciphertext[i],PubKey, modeN);
	}
}
void encrypt(unsigned long long *Plaintext){
	int i;
	printf("Please wait for encryption\n");		
	for(i=0;i<CodeLength;i++){	
		//printf("before:%llu\n",Plaintext[i]);		
		Plaintext[i]=SquareMod( Plaintext[i],PriKey, modeN);
		//printf("after:%llu\n",Plaintext[i]);		
	}		
}

int main()
{
	char input[100];
	unsigned long long i=0, inputB[100];
	
	printf("please input data to incrypte\n");
	for(i=0;i<CodeLength;i++){
		scanf("%llu", &inputB[i]);
		printf("%llu\n",inputB[i]);
	}	
	//gets(input);
	//puts(input);
	//for(i=0;i<CodeLength;i++){
	//	inputB[i]=(unsigned long long) input[i];
	//	printf("%llu ", inputB[i]);		
	//}	

	printf("\n");
	encrypt(inputB);
	printf("Ciphertext:");
	for(i=0;i<CodeLength;i++){
		printf("%llu ", inputB[i]);
	}

	printf("\n");
	decrypt(inputB);
	printf("Plaintext:");
	for(i=0;i<CodeLength;i++){
		printf("%llu ", inputB[i]);
	}
	printf("\n");
}