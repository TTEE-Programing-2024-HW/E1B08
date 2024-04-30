 #include<stdio.h>
 #include<stdlib.h> 
 int main(){
 	int state=0;
	int a=0,i,j;
	char ch,y;
	int password;

	printf("輸入密碼\n");
	scanf("%d",&password);
	while(1)
	switch(state){
		case 0:
			if(password==2024){
				printf("密碼正確\n");
				system("pause");
		   		system("CLS");
				state=1;
		   		break;
			}
			else if((password!=2024)&&(a<3)){
				a=a+1;
		    	printf("輸入第%d次錯誤!!!\n",a);
		    	printf("請重新輸入:");
		    	scanf("%d",&password);
				break;	
			}
			else if(a=3){
				return 0;
			}
		case 1:
			
			printf("==========================\n");
		   	printf("|| a.畫出直角三角形     ||\n");
		   	printf("|| b.顯示乘法表         ||\n");
		   	printf("|| c.結束               ||\n");
		   	printf("==========================\n"); 
		   	scanf(" %c",&ch);
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
		   			
				   }
				system("CLS");
		   		break;
		case 2:
			printf("請輸入a-n:");
			   scanf(" %c",&ch);
		    	for(i = 0;i<=ch-'a';i++)
			   {
			   	for(j = 0;j<=ch-'a';j++)
			   	    {
			   	   	
					}
					for(j = 0;j<=i;j++){
						printf("%c",ch-j);
					}
					printf("\n");
				   }
				   system("PAUSE");
		        system("CLS");
		        state=1;
		    	break;
			
	}
 
 	
 	
 	
 	
 	system ("pause");
 	return 0;
 }
