 #include<stdio.h>
 #include<stdlib.h> 
 int main(){
 	int state=0;
	int a=0,i,j;
	char ch,y;
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
		case 1:
			
			printf("==========================\n");
		   	printf("|| a.�e�X�����T����     ||\n");
		   	printf("|| b.��ܭ��k��         ||\n");
		   	printf("|| c.����               ||\n");
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
			printf("�п�Ja-n:");
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
