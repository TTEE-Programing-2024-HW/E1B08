#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data {
    char name[10];
    int ID;
    int ma;
    int ph;
    int en;
};

void inputStudents(struct data *input, int n);
void printStudents(struct data *input,int n);
void pickStudents(struct data *input,int n,char *in);

int main() {
    int state = 0;
    int pass, a = 0, n;
    char ch, in;
    
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
    printf("�п�J�K�X�G\n");
    scanf("%d", &pass);

    struct data input[10];

    while (1) {
        switch (state) {
            case 0:
                if (pass == 2024) {
                    printf("�K�X���T�A�w��\n");
                    state = 1;
                    system("pause");
            		system("CLS");
                    break;
                } else if (a < 2) {
                    a++;
                    printf("�Э��s��J�K�X�G\n");
                    scanf("%d", &pass);
                    break;
                } else if (a == 2) {
                    return 0;
                }
            case 1:
                printf("=============================\n");
                printf("|| a. ��J�ǥͦ��Z         ||\n");
                printf("|| b. ��ܾǥͦ��Z         ||\n");
                printf("|| c. �j�M�ǥͦ��Z         ||\n");
                printf("|| d. ���Z�ƦW             ||\n");
                printf("|| e. �h�X�t��             ||\n");
                printf("=============================\n");
                scanf(" %c", &ch);
                switch (ch) {
                    case 'a':
                    case 'A':
                        state = 2;
                        break;
                    case 'b':
                    case 'B':
                        state = 3;
                        break;
                    case 'c':
                    case 'C':
                        state = 4;
                        break;
                    case 'd':
                    case 'D':
                        state = 5;
                        break;
                    case 'e':
                    case 'E':
                        state = 6;
                        break;
                    default:
                        printf("��J���~!!!\n");
                        break;
                }
                break;
            case 2:
            	system("pause");
            	system("CLS");
                printf("�п�J�ǥ͸�T�G\n");
                printf("�п�Jn(5~10)����ơG\n");
                scanf("%d", &n);
                if (n >= 5 && n <= 10) {
                    inputStudents(input, n);
                    system("pause");
					system("CLS");
                    state = 1;
                    break;
                } else {
                    printf("��J���~�In�����b5��10�����C\n");
                    break;
                }
            case 3:
            	system("CLS");
            	printStudents(input, n);
				system("pause");
				system("CLS");
				state = 1;
                break;
            case 4:
    			system("CLS"); // �M���ù�
    			printf("�п�J�n�j�M���m�W�G\n");
    			scanf("%s", &in);
    			pickStudents(input, n, &in); // �I�s pickStudents ��ƶi��j�M
    			printf("���U���N���^�D���...\n");
    			system("pause"); // ���ݥΤ���U���N��
    			system("CLS"); // �M���ù�
    			state = 1; // ��^�D���
    			break;

        }
    }
    system("pause");
    return 0;
}

void inputStudents(struct data *input, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("�п�J��%d��ǥͪ���T�G\n", i + 1);
        printf("�m�W�G");
        scanf("%s", input[i].name);
        printf("�Ǹ��G");
        scanf("%d", &input[i].ID);
        do {
            printf("�ƾǦ��Z�G");
            scanf("%d", &input[i].ma);
            if (input[i].ma < 0 || input[i].ma > 100) {
                printf("���Z��J���~�I�Э��s��J�C\n");
            }
        } while (input[i].ma < 0 || input[i].ma > 100);
        do {
            printf("���z���Z�G");
            scanf("%d", &input[i].ph);
            if (input[i].ph < 0 || input[i].ph > 100) {
                printf("���Z��J���~�I�Э��s��J�C\n");
            }
        } while (input[i].ph < 0 || input[i].ph > 100);
        do {
            printf("�^�妨�Z�G");
            scanf("%d", &input[i].en);
            if (input[i].en < 0 || input[i].en > 100) {
                printf("���Z��J���~�I�Э��s��J�C\n");
            }
        } while (input[i].en < 0 || input[i].en > 100);
    }
}

void printStudents(struct data *input, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("�m�W�G%s �Ǹ��G%d\n�ƾǦ��Z�G%d ���z���Z�G%d �^�妨�Z�G%d\n�ӤH�������Z�G%4.1f\n",
               input[i].name, input[i].ID, input[i].ma, input[i].ph, input[i].en,
               ((float)input[i].ma + (float)input[i].ph + (float)input[i].en) / 3);
    }
}

void pickStudents(struct data *input, int n, char *in) {
    int i;
    int found = 0; // �Ω�аO�O�_���ǰt�m�W
    for (i = 0; i < n; i++) {
        if (strcmp(input[i].name, in) == 0) {
            printf("�m�W�G%s �Ǹ��G%d\n�ƾǦ��Z�G%d ���z���Z�G%d �^�妨�Z�G%d\n�ӤH�������Z�G%4.1f\n",
                   input[i].name, input[i].ID, input[i].ma, input[i].ph, input[i].en,
                   ((float)input[i].ma + (float)input[i].ph + (float)input[i].en) / 3);
            found = 1;
        }
    }
    if (!found) {
        printf("�䤣��Ӿǥ͸�ơC\n");
    }
}

