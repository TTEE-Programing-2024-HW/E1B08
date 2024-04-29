 #include<stdio.h>
 #include<stdlib.h> 
 int main(){
 	int state=0;
	int a=0;
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
	}
 
 	
 	
 	
 	
 	system ("pause");
 	return 0;
 }
