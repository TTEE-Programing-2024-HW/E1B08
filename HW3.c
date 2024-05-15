#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void prt();
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
int main(){
	int state=0;
	int a=0,i,j,k,peo;
	char ch,y;
	int pass;
	int row1, col1,row2,col2,row3,col3,row4,col4;
	
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
		   			default:
		   				printf("輸入錯誤!!!\n");
		   				system("pause");
		   				state=1;
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
				prt();
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
    					do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
    					} while (selected[row1][col1]); // // 如果已經選取過，則重新選取
   					one[row1][col1] = 1; // 標記為已選取
    				seat[row1][col1] = '@';
    				prt();
					printf("是否滿意(y/n)\n");
					fflush(stdin);
					scanf("%c",&y);
						if(y=='y'||y=='Y'){
							system("CLS");
							seat[row1][col1] = '*';
							prt();
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
						else{
							printf("錯誤!!\a\n");
							seat[row1][col1] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
				}
				if(peo==2){
					srand((unsigned)time(NULL));// 使用時間作為種子，以確保每次運行都有不同的隨機數
					int two[9][9] = {0}; // 用於記錄已選取的位置
    						do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
        					row2=row1;
        					col2=col1+1;
    					} while ((selected[row1][col1])||(selected[row2][col2])); // // 如果已經選取過，則重新選取
   					two[row1][col1] = 1; // 標記為已選取
   					two[row2][col2] = 1;
    				seat[row1][col1] = '@';
    				seat[row2][col2] = '@';

    				prt();
					printf("是否滿意(y/n)\n");
					fflush(stdin);
					scanf("%c",&y);
						if(y=='y'||y=='Y'){
							system("CLS");
							seat[row1][col1] = '*';
    						seat[row2][col2] = '*';
							prt();
							state=1;
							system("pause");
							system("CLS");
							
							break;
						}
						else if(y=='n'||y=='N'){
							seat[row1][col1] = '-';
    						seat[row2][col2] = '-';
							system("CLS");
							state=1;
							break;
						}
						else{
							printf("錯誤!!\a\n");
							seat[row1][col1] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
				}
				if(peo==3){
					srand((unsigned)time(NULL));// 使用時間作為種子，以確保每次運行都有不同的隨機數
					int two[9][9] = {0}; // 用於記錄已選取的位置
    						do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
        					row2=row3=row1;
        					col2=col1+1;
        					col3=col2+1;
    					} while ((selected[row1][col1])||(selected[row2][col2])||(selected[row3][col3])); // // 如果已經選取過，則重新選取
   					two[row1][col1] = 1; // 標記為已選取
   					two[row2][col2] = 1;
   					two[row3][col3] = 1;
    				seat[row1][col1] = '@';
    				seat[row2][col2] = '@';
    				seat[row3][col3] = '@';

    				prt();
					printf("是否滿意(y/n)\n");
					fflush(stdin);
					scanf("%c",&y);
						if(y=='y'||y=='Y'){
							system("CLS");
							seat[row1][col1] = '*';
    						seat[row2][col2] = '*';
    						seat[row3][col3] = '*';
							prt();
							state=1;
							system("pause");
							system("CLS");
							
							break;
						}
						else if(y=='n'||y=='N'){
							seat[row1][col1] = '-';
    						seat[row2][col2] = '-';
    						seat[row3][col3] = '-';
							system("CLS");
							state=1;
							break;
						}
						else{
							printf("錯誤!!\a\n");
							seat[row1][col1] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
				}
			
					break;
				
				
				
		}
	}
	
	system("pause");
	return 0;
}
void prt(){
	int i,j;
	printf(" 123456789\n");
	for (i = 0; i < 9; i++) {
    printf("%d", i+1);
    for (j = 0; j < 9; j++) {
    printf("%c", seat[i][j]);
    }
    printf("\n");
	}
}
