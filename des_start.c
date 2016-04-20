// des_test.c
//

#include "stdio.h" 
#include "stdlib.h"   
#include "des.h"

void show1() //主界面
{
	system("clear");
	printf("\n\n\n\t\t*************** DES加密解密系统 ******************\n\n");
	printf("\t\t--------------------------------------------------\n");
	//printf("\t\t--------------------------------------------------\n");
	printf("\t\t**************************************************\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t\t1.加密\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t\t2.解密\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t\t3.退出\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t--------------------------------------------------\n");
}

void show2()	//加密界面
{
	system("clear");
	printf("\n\n\n\t\t****************** DES加密 **********************\n\n");
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t**************************************************\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t请选择明文和密钥的输入方式:\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t1.从文件读取\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t2.命令行输入\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t3.退出\t\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t\t选择:");
}

void show3()	//加密界面
{
	system("clear");
	printf("\n\n\n\t\t****************** DES加密 **********************\n\n");
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t**************************************************\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t算法:\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t1.DES\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t**\t\t2.3DES\t\t\t**\n");
	printf("\t\t**\t\t\t\t\t\t**\n");
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t\t选择:");
}
void DES_code() {
  show2();
  int command;
	scanf("%d", &command);
	if (command == 1) {
	  char file_in[100];
		char file_key[100];
		char file_temp[100];
		char file_out[100];
    printf("输入input文件名:");
		scanf("%s", file_in);
		printf("输入密文文件名:");
		scanf("%s", file_temp);
		printf("输入key文件名:");
		scanf("%s", file_key);
		DES_Encrypt_File(file_in, file_key, file_temp);
		getchar();
		getchar();
	} else if (command == 2) {
	  char ciphertext[1000];
		char input[1000];
		char key[30];
		int i;		
		printf("输入明文：");
		scanf("%s", input);
	  scanf("%s", key);
		DES_Encrypt_String(input,key,ciphertext);   
		printf("密文: %s\n", ciphertext);
	  getchar();
		getchar();

	}
}

void DES_decode() {
  show2();
  int command;
	scanf("%d", &command);
	if (command == 1) {
	  char file_in[100];
		char file_key[100];
		char file_temp[100];
		char file_out[100];
	  printf("输入output文件名:");
		scanf("%s", file_out);
		printf("输入密文文件名:");
		scanf("%s", file_temp);
		printf("输入key文件名:");
		scanf("%s", file_key);
    DES_Decrypt_File(file_temp, file_key, file_out);
		getchar();
		getchar();

	} else if (command == 2) {
	  char ciphertext[1000];
		char output[1000];
		char key[30];
		int i;		
		printf("输入密文：");
		scanf("%s", ciphertext);
	  scanf("%s", key);
		DES_Decrypt_String(ciphertext, key, output);   
		printf("密文: %s\n", output);
		getchar();
		getchar();
	}
}

void D3DES_code() {
  show2();
  int command;
	scanf("%d", &command);
	if (command == 1) {
		char file_in[100];
		char file_key[100];
		char file_temp[100];
		char file_out[100];
    printf("输入input文件名:");
		scanf("%s", file_in);
		printf("输入密文文件名:");
		scanf("%s", file_temp);
		printf("输入key文件名:");
		scanf("%s", file_key);
		D3DES_Encrypt_File(file_in, file_key, file_temp);
		getchar();
			getchar();
} else if (command == 2) {
		char ciphertext[1000];
		char input[1000];
		char key[30];
		int i;
    printf("输入明文：");
	  scanf("%s", input);
		for (i = 0; i < 3; i++) {
			printf("输入第%d密钥：", i+1);
			scanf("%s", key+i*8);
		}
		D3DES_Encrypt_String(input,key,ciphertext);   
		printf("密文: %s\n", ciphertext);
		getchar();
		getchar();

	}
}

void D3DES_decode() {
  show2();
  int command;
	scanf("%d", &command);
	if (command == 1) {
	  char file_in[100];
		char file_key[100];
		char file_temp[100];
		char file_out[100];
	  printf("输入output文件名:");
		scanf("%s", file_out);
		printf("输入密文文件名:");
		scanf("%s", file_temp);
		printf("输入key文件名:");
		scanf("%s", file_key);
    D3DES_Decrypt_File(file_temp, file_key, file_out);
		getchar();
		getchar();
} else if (command == 2) {
	  char ciphertext[1000];
		char output[1000];
		char key[30];
		int i;		
		printf("输入密文：");
		scanf("%s", ciphertext);
		for (i = 0; i < 3; i++) {
			printf("输入第%d密钥：", i+1);
			scanf("%s", key+i*8);
		}
		D3DES_Decrypt_String(ciphertext, key, output);   
		printf("译文: %s\n", output);
		getchar();
		getchar();

	}
}


void code() {
	show3();
  int command;
	scanf("%d", &command);
	switch(command) {
	  case 1:
      DES_code();
			break;
		case 2:
			D3DES_code();
			break;
		case 3:
			break;
		default:
			break;
	}
}

void decode() {
  show3();
  int command;
	scanf("%d", &command);
	switch(command) {
	  case 1:
      DES_decode();
			break;
		case 2:
			D3DES_decode();
			break;
		case 3:
			break;
		default:
			break;
	}
}

int main()   
{    
  int command = 0;  
	system("clear");
  show1();
  scanf("%d", &command);
	while(1) {
    switch(command) {
     case 1:
       code();
			 break;
		 case 2:
			 decode();
			 break;
		 case 3:
			 return 0;
		 default: break;
    }
	}
}
