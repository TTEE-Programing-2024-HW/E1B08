#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int state=0;
	int a=0,i,j,k,peo;
	char ch,y;
	int pass;
	char seat[9][9]={
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'},
	{'-','-','-','-','-','-','-','-','-'}};
	puts("      *            *            *");
    puts("     ***          ***          ***");
    puts("    *****        *****        *****");
    puts("   *******      *******      *******");
    puts("  *********    *********    *********");
    puts("     |||          |||          |||");

    puts("      *            *            *");
    puts("     ***          ***          ***");
    puts("    *****        *****        *****");
    puts("   *******      *******      *******");
    puts("  *********    *********    *********");
    puts("     |||          |||          |||");

    puts("      *            *            *");
    puts("     ***          ***          ***");
    puts("    *****        *****        *****");
    puts("   *******      *******      *******");
    puts("  *********    *********    *********");
    puts(" ***********  ***********  ***********");
    puts("     |||          |||          |||");
	printf("輸入密碼\n");
	scanf("%d",&pass);
	while(1){
		switch(state){
			case 0:
				if(pass==2024){
					printf("密碼正確，歡迎\n");
					system("pause");
					system("CLS");
					state=1;
					break;
				}
				else if(pass!=2024&&a<2){
					a=a+1;
					printf("請重新輸入\n");
					scanf("%d",&pass);
					break;
				}
				else if(a==2){
					return 0;
				}
			case 1:
				printf("==========================\n");
		   		printf("|| a. Available seats   ||\n");
		   		printf("|| b. Arrange for you   ||\n");
		   		printf("|| c. Choose by yourself||\n");
		   		printf("|| d. Exit              ||\n");
		   		printf("==========================\n");
		   		scanf("%s",&ch);
		   		switch(ch){
		   			case 'a':
		   			case 'A':
		   				state=2;
		   				break;
		   			case 'b':
		   			case 'B':
		   				state=3;
		   				break;
		   			case 'c':
		   			case 'C':
		   				state=4;
		   				break;
		   			case 'd':
		   			case 'D':
		   				state=5;
		   				break;
				   }
				   system("CLS");
				   break;
			case 2:
				for (i = 0; i < 9; i++) {
    					for (j = 0; j < 9; j++) {
        					seat[i][j]='-';
    					}
					}
				srand((unsigned)time(NULL));// 使用時間作為種子，以確保每次運行都有不同的隨機數
				int selected[9][9] = {0}; // 用於記錄已選取的位置

				for (k = 0; k < 10; k++) {
    			int row, col;
    				do {
        				row = rand() % 9;
        				col = rand() % 9;
    				} while (selected[row][col]); // // 如果已經選取過，則重新選取

   				selected[row][col] = 1; // 標記為已選取
    			seat[row][col] = '*';
				}
				printf(" 123456789\n");
					for (i = 0; i < 9; i++) {
    					printf("%d", i+1);
    					for (j = 0; j < 9; j++) {
        					printf("%c", seat[i][j]);
    					}
    					printf("\n");
					}
				system("pause");
				system("CLS");
				state=1;
					
				break;	
			case 3:
				printf("需要幾個座位(1~4人)\n");
				scanf("%d",&peo);
				system("CLS");
				if(peo==1){
					srand((unsigned)time(NULL));// 使用時間作為種子，以確保每次運行都有不同的隨機數
					int one[9][9] = {0}; // 用於記錄已選取的位置
    				int row1, col1;
    					do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
    					} while (selected[row1][col1]); // // 如果已經選取過，則重新選取
   					one[row1][col1] = 1; // 標記為已選取
    				seat[row1][col1] = '@';
    				printf(" 123456789\n");
					for (i = 0; i < 9; i++) {
    					printf("%d", i+1);
    					for (j = 0; j < 9; j++) {
        					printf("%c", seat[i][j]);
    					}
    					printf("\n");
					}
					printf("是否滿意(y/n)\n");
					fflush(stdin);
					scanf("%c",&y);
						if(y=='y'||y=='Y'){
							system("CLS");
							seat[row1][col1] = '*';
							printf(" 123456789\n");
							for (i = 0; i < 9; i++) {
    							printf("%d", i+1);
    						for (j = 0; j < 9; j++) {
        						printf("%c", seat[i][j]);
    					}
    					printf("\n");
						}
							state=1;
							system("pause");
							system("CLS");
							
							break;
						}
						else if(y=='n'||y=='N'){
							seat[row1][col1] = '-';
							system("CLS");
							state=1;
							break;
						}	
					break;
				}
				
				
		}
	}
	
	system("pause");
	return 0;
}
