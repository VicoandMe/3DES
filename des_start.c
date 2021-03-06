// des_test.c
//

#include "stdio.h" 
#include "stdlib.h"   
#include "des.h"
#include <string.h>

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
		char output[1000];
		char key[30];
		int len = 0;
		int i;		
		printf("输入明文：");
		scanf("%s", input);
		printf("输入key：");
		scanf("%s", key);
		len = DES_Encrypt_String(input,key,ciphertext);
		for (i = 0; i < len; i++) {
		  printf("%02X ",((unsigned int) ciphertext[i])&0x00ff);
		}
		printf("\n");
		printf("密文长度:%d字\n", len);
	  printf("输入1将密文解码:");
		scanf("%d", &command);
		if (command == 1) {
			DES_Decrypt_String(ciphertext, key, output, len);   
		  printf("译文: %s\n", output);
		}
		getchar();
		getchar();
	}
}

int charToHex(char c) {
  switch(c) {
	  case 'A': return 10; break;
	  case 'B': return 11; break;
	  case 'C': return 12; break;
	  case 'D': return 13; break;
	  case 'E': return 14; break;
	  case 'F': return 15; break;
		default: return c - '0'; break;
	}
}
void cipToHex(char *input, char *cip) {
	int i = 0;
	for(i = 0; i < strlen(input)/2; i++) {
	  cip[i] = charToHex(input[i*2])*16 + charToHex(input[i*2 + 1]);
	}
	cip[i*2] = '\0';
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
		char input[1000];
		char key[30];
		int i;		
		printf("输入密文：");
		scanf("%s", input);
		cipToHex(input, ciphertext);
		printf("输入Key:");
	  scanf("%s", key);
		printf("%s\n",ciphertext);
		DES_Decrypt_String(ciphertext, key, output, 0);   
		printf("译文: %s\n", output);
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
		char output[1000];
		char key[30];
		int len;
		int i;
    printf("输入明文：");
	  scanf("%s", input);
		for (i = 0; i < 3; i++) {
			printf("输入第%d密钥：", i+1);
			scanf("%s", key+i*8);
		}
		len = D3DES_Encrypt_String(input,key,ciphertext);   
		for (i = 0; i < len; i++) {
      printf("%02X ",((unsigned int) ciphertext[i])&0x00ff);
		}
		printf("\n");
		printf("密文长度:%d字节\n", len);
	  printf("输入1将密文解码:");
		scanf("%d", &command);
		if (command == 1) {
			D3DES_Decrypt_String(ciphertext, key, output, len);   
		  printf("译文: %s\n", output);
		}
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
		char input[1000];
		char output[1000];
		char key[30];
		int i;		
		printf("输入密文：");
		scanf("%s", input);
		cipToHex(input, ciphertext);
		for (i = 0; i < 3; i++) {
			printf("输入第%d密钥：", i+1);
			scanf("%s", key+i*8);
		}
		D3DES_Decrypt_String(ciphertext, key, output, 0);   
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
	while(1) {
    show1();
    scanf("%d", &command);
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
