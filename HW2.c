 #include<stdio.h>
 #include<stdlib.h> 
 int main(){
 	int state=0;
	int a=0;
	int password;
	printf("��J�K�X\n");
	scanf("%d",&password);
	while(1)
	switch(state){
		case 0:
			if(password==2024){
				printf("�K�X���T\n");
				system("pause");
		   		system("CLS");
				state=1;
		   		break;
			}
			else if((password!=2024)&&(a<3)){
				a=a+1;
		    	printf("��J��%d�����~!!!\n",a);
		    	printf("�Э��s��J:");
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
