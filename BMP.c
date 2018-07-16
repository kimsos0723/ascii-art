#include<stdio.h>
#include<Windows.h>
#include<string.h> 
#include<direct.h>

#define WIDTH 1024
#define HEIGHT 1024
#define HEADER 58

unsigned char B[HEIGHT][WIDTH],G[HEIGHT][WIDTH],R[HEIGHT][WIDTH];
unsigned char ascii[] = {'#','&','@','%','=','+','*',':','-','.',' '};

int main() {
	char addr[128];
	int chose = 0;
	int i,j,mode,re;
	int ctr=0;
	int gry,txt;
	char bmp[] = ".bmp";

	do{
		fflush(stdin);
		printf("1.Set the font of the Notepad to 1.\n");
		printf("2.Turn off the magnetic cord switch setting.");
		Sleep(1000);
		
		printf("\n\n\nFormat: [name] or [address]\n");
		printf("BMP File to Convert : ");
		
		fgets(addr,sizeof(addr), stdin);
		addr[strlen(addr)-1] = '\0';
		strcat(addr,bmp);
		printf("%s\n",addr);
	
											
		FILE *fp1 = fopen(addr, "rb");
		FILE *fp2 = fopen("c:\\Users\\DSM2018\\Desktop\\BMP\\Gray_mode.bmp", "w+b");
		FILE *fp3 = fopen("c:\\Users\\DSM2018\\Desktop\\BMP\\Ascii_art.txt","w");
	
		if(fp1 == NULL){
			perror("fopen ERROR1");
			system("pause");
			return 0;
		}
		if(fp2 == NULL){
			perror("fopen ERROR2");
			system("pause");
			return 0;
		}
		if(fp3 == NULL){
			perror("fopen ERROR3");
			system("pause");
			return 0;
		}
		printf("Trun to black and white picture....\n");
		for (i = 0; i <HEADER; i++) {
			putc(getc(fp1), fp2);
		}
		for (i = 0; i < HEIGHT; i++) {
			for(j = 0; j < WIDTH; j++) {
				B[i][j] = getc(fp1); 
				G[i][j] = getc(fp1); 
				R[i][j] = getc(fp1);
			}
		}
		for(i = 0; i < HEIGHT; i++) {
			for(j = 0; j < WIDTH; j++) {
				putc((B[i][j]+G[i][j]+R[i][j])/3,fp2);
				putc((B[i][j]+G[i][j]+R[i][j])/3,fp2);		
				putc((B[i][j]+G[i][j]+R[i][j])/3,fp2);		
			}
		}
		
		printf("done");
		Sleep(500);
		system("cls");
		printf("press key 1 or 2  ");
		printf("(mode1: colum mode2: row)\nmode input : ");
		scanf("%d",&mode);	
		printf("Converting to TEXT...\n");
		if(mode == 1){
			for(i = HEIGHT; i > 0; i--) {
				for(j = WIDTH; j > 0 ; j--) {
					char c = ascii[((B[i][j]+G[i][j]+R[i][j])/3)*sizeof(ascii)/256];
					putc(c,fp3);
				//	putc(c,fp3);
				//	putc(c,fp3);
				}
			}
		}
		else if(mode == 2){
			for(i = HEIGHT; i > 0; i--) {
				for(j = WIDTH; j > 0 ; j--) {
					 char c = ascii[((B[j][i]+G[j][i]+R[j][i])/3)*sizeof(ascii)/256];
						putc(c,fp3);

				}
			}
		}
		else
		{
			printf("Wrong MODE!!\n");
		}
		printf("done\n");
		printf("If you want reset press key 'r' ");
		fflush(stdin);
		re = getc(stdin);
		
		fclose(fp3);	
		fclose(fp1);
		fclose(fp2);
		system("cls");
		ctr++;
	}while(re == 'r' || re == 'R');
	return 0;
}
