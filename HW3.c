#include<stdio.h>
#include<stdlib.h>
int main(){
	int state=0;
	int a=0,i,j,y;
	char ch;
	int pass;
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
		}
	}
	
	system("pause");
	return 0;
}
