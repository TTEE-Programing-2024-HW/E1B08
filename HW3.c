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
	printf("��J�K�X\n");
	scanf("%d",&pass);
	while(1){
		switch(state){
			case 0:
				if(pass==2024){
					printf("�K�X���T�A�w��\n");
					system("pause");
					system("CLS");
					state=1;
					break;
				}
				else if(pass!=2024&&a<2){
					a=a+1;
					printf("�Э��s��J\n");
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
		   				printf("��J���~!!!\n");
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
				srand((unsigned)time(NULL));// �ϥήɶ��@���ؤl�A�H�T�O�C���B�泣�����P���H����
				int selected[9][9] = {0}; // �Ω�O���w�������m

				for (k = 0; k < 10; k++) {
    			int row, col;
    				do {
        				row = rand() % 9;
        				col = rand() % 9;
    				} while (selected[row][col]); // // �p�G�w�g����L�A�h���s���

   				selected[row][col] = 1; // �аO���w���
    			seat[row][col] = '*';
				}
				prt();
				system("pause");
				system("CLS");
				state=1;
					
				break;	
			case 3:
				printf("�ݭn�X�Ӯy��(1~4�H)\n");
				scanf("%d",&peo);
				system("CLS");
				if(peo==1){
					srand((unsigned)time(NULL));// �ϥήɶ��@���ؤl�A�H�T�O�C���B�泣�����P���H����
    					do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
    					} while (selected[row1][col1]); // // �p�G�w�g����L�A�h���s���
   					selected[row1][col1] = 1; // �аO���w���
    				seat[row1][col1] = '@';
    				prt();
					printf("�O�_���N(y/n)\n");
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
							printf("���~!!\a\n");
							seat[row1][col1] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
				}
				else if(peo==2){
					srand((unsigned)time(NULL));// �ϥήɶ��@���ؤl�A�H�T�O�C���B�泣�����P���H����
    						do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
        					row2=row1;
        					col2=col1+1;
    					} while ((selected[row1][col1])||(selected[row2][col2])||(row2>9)||(col2>9)); // // �p�G�w�g����L�A�h���s���
   					selected[row1][col1] = 1; // �аO���w���
   					selected[row2][col2] = 1;
    				seat[row1][col1] = '@';
    				seat[row2][col2] = '@';

    				prt();
					printf("�O�_���N(y/n)\n");
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
							printf("���~!!\a\n");
							seat[row1][col1] = '-';
    						seat[row2][col2] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
				}
				else if(peo==3){
					srand((unsigned)time(NULL));// �ϥήɶ��@���ؤl�A�H�T�O�C���B�泣�����P���H����
    						do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
        					row2=row3=row1;
        					col2=col1+1;
        					col3=col2+1;
    					} while ((selected[row1][col1])||(selected[row2][col2])||(selected[row3][col3])||(row2>9)||(row3>9)||(col3>9)||(col2>9)); // // �p�G�w�g����L�A�h���s���
   					selected[row1][col1] = 1; // �аO���w���
   					selected[row2][col2] = 1;
   					selected[row3][col3] = 1;
    				seat[row1][col1] = '@';
    				seat[row2][col2] = '@';
    				seat[row3][col3] = '@';

    				prt();
					printf("�O�_���N(y/n)\n");
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
							printf("���~!!\a\n");
							seat[row1][col1] = '-';
    						seat[row2][col2] = '-';
    						seat[row3][col3] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
				}
				else if(peo==4){
					int cho;
					printf("�۾F4��--1\n�ñƨ��--2\n");
					scanf("%d,&cho");
					if(cho==1){
						srand((unsigned)time(NULL));// �ϥήɶ��@���ؤl�A�H�T�O�C���B�泣�����P���H����
    						do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
        					row2=row3=row4=row1;
        					col2=col1+1;
        					col3=col2+1;
        					col4=col3+1;
    					} while ((selected[row1][col1])||(selected[row2][col2])||(selected[row3][col3])||(selected[row4][col4])||(row2>9)||(row3>9)||(row4>9)||(col4>9)||(col3>9)||(col2>9)); // // �p�G�w�g����L�A�h���s���
   					selected[row1][col1] = 1; // �аO���w���
   					selected[row2][col2] = 1;
   					selected[row3][col3] = 1;
   					selected[row4][col4] = 1;
    				seat[row1][col1] = '@';
    				seat[row2][col2] = '@';
    				seat[row3][col3] = '@';
    				seat[row4][col4] = '@';

    				prt();
					printf("�O�_���N(y/n)\n");
					fflush(stdin);
					scanf("%c",&y);
						if(y=='y'||y=='Y'){
							system("CLS");
							seat[row1][col1] = '*';
    						seat[row2][col2] = '*';
    						seat[row3][col3] = '*';
    						seat[row4][col4] = '*';
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
    						seat[row4][col4] = '-';
							system("CLS");
							state=1;
							break;
						}
						else{
							printf("���~!!\a\n");
							seat[row1][col1] = '-';
    						seat[row2][col2] = '-';
    						seat[row3][col3] = '-';
    						seat[row4][col4] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
					}
					else if(cho==2){
						srand((unsigned)time(NULL));// �ϥήɶ��@���ؤl�A�H�T�O�C���B�泣�����P���H����
    						do {
        					row1 = rand() % 9;
        					col1 = rand() % 9;
        					row2=row1;
							row4=row3=row1+1;
        					col2=col4=col1+1;
        					col3=col1;
    					} while ((selected[row1][col1])||(selected[row2][col2])||(selected[row3][col3])||(selected[row4][col4])||(row2>9)||(row3>9)||(row4>9)||(col4>9)||(col3>9)||(col2>9)); // // �p�G�w�g����L�A�h���s���
   					selected[row1][col1] = 1; // �аO���w���
   					selected[row2][col2] = 1;
   					selected[row3][col3] = 1;
   					selected[row4][col4] = 1;
    				seat[row1][col1] = '@';
    				seat[row2][col2] = '@';
    				seat[row3][col3] = '@';
    				seat[row4][col4] = '@';

    				prt();
					printf("�O�_���N(y/n)\n");
					fflush(stdin);
					scanf("%c",&y);
						if(y=='y'||y=='Y'){
							system("CLS");
							seat[row1][col1] = '*';
    						seat[row2][col2] = '*';
    						seat[row3][col3] = '*';
    						seat[row4][col4] = '*';
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
    						seat[row4][col4] = '-';
							system("CLS");
							state=1;
							break;
						}
						else{
							printf("���~!!\a\n");
							seat[row1][col1] = '-';
    						seat[row2][col2] = '-';
    						seat[row3][col3] = '-';
    						seat[row4][col4] = '-';
							system("pause");
							system("CLS");
							state=1;
							break;
						}
					}
					else{
						printf("���~!!\a\n");
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
