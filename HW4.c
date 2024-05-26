#include<stdio.h>
#include<stdlib.h>
int main(){
	int state=0;
	int pass,a=0;
	char ch;
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
		   		printf("|| a. Enter student gra     ||\n");
		   		printf("|| b. Display student gra   ||\n");
		   		printf("|| c. Sarch for student grad||\n");
		   		printf("|| d. Grade ran             ||\n");
		   		printf("|| e. Exit system           ||\n");

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
		   			case 'e':
		   			case 'E':
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
			}
	}
system("pause");

return 0;
}
