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
    printf("請輸入密碼：\n");
    scanf("%d", &pass);

    struct data input[10];

    while (1) {
        switch (state) {
            case 0:
                if (pass == 2024) {
                    printf("密碼正確，歡迎\n");
                    state = 1;
                    system("pause");
            		system("CLS");
                    break;
                } else if (a < 2) {
                    a++;
                    printf("請重新輸入密碼：\n");
                    scanf("%d", &pass);
                    break;
                } else if (a == 2) {
                    return 0;
                }
            case 1:
                printf("=============================\n");
                printf("|| a. 輸入學生成績         ||\n");
                printf("|| b. 顯示學生成績         ||\n");
                printf("|| c. 搜尋學生成績         ||\n");
                printf("|| d. 成績排名             ||\n");
                printf("|| e. 退出系統             ||\n");
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
                        printf("輸入錯誤!!!\n");
                        break;
                }
                break;
            case 2:
            	system("pause");
            	system("CLS");
                printf("請輸入學生資訊：\n");
                printf("請輸入n(5~10)筆資料：\n");
                scanf("%d", &n);
                if (n >= 5 && n <= 10) {
                    inputStudents(input, n);
                    system("pause");
					system("CLS");
                    state = 1;
                    break;
                } else {
                    printf("輸入錯誤！n必須在5到10之間。\n");
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
    			system("CLS"); // 清除螢幕
    			printf("請輸入要搜尋的姓名：\n");
    			scanf("%s", &in);
    			pickStudents(input, n, &in); // 呼叫 pickStudents 函數進行搜尋
    			printf("按下任意鍵返回主選單...\n");
    			system("pause"); // 等待用戶按下任意鍵
    			system("CLS"); // 清除螢幕
    			state = 1; // 返回主選單
    			break;

        }
    }
    system("pause");
    return 0;
}

void inputStudents(struct data *input, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("請輸入第%d位學生的資訊：\n", i + 1);
        printf("姓名：");
        scanf("%s", input[i].name);
        printf("學號：");
        scanf("%d", &input[i].ID);
        do {
            printf("數學成績：");
            scanf("%d", &input[i].ma);
            if (input[i].ma < 0 || input[i].ma > 100) {
                printf("成績輸入錯誤！請重新輸入。\n");
            }
        } while (input[i].ma < 0 || input[i].ma > 100);
        do {
            printf("物理成績：");
            scanf("%d", &input[i].ph);
            if (input[i].ph < 0 || input[i].ph > 100) {
                printf("成績輸入錯誤！請重新輸入。\n");
            }
        } while (input[i].ph < 0 || input[i].ph > 100);
        do {
            printf("英文成績：");
            scanf("%d", &input[i].en);
            if (input[i].en < 0 || input[i].en > 100) {
                printf("成績輸入錯誤！請重新輸入。\n");
            }
        } while (input[i].en < 0 || input[i].en > 100);
    }
}

void printStudents(struct data *input, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("姓名：%s 學號：%d\n數學成績：%d 物理成績：%d 英文成績：%d\n個人平均成績：%4.1f\n",
               input[i].name, input[i].ID, input[i].ma, input[i].ph, input[i].en,
               ((float)input[i].ma + (float)input[i].ph + (float)input[i].en) / 3);
    }
}

void pickStudents(struct data *input, int n, char *in) {
    int i;
    int found = 0; // 用於標記是否找到匹配姓名
    for (i = 0; i < n; i++) {
        if (strcmp(input[i].name, in) == 0) {
            printf("姓名：%s 學號：%d\n數學成績：%d 物理成績：%d 英文成績：%d\n個人平均成績：%4.1f\n",
                   input[i].name, input[i].ID, input[i].ma, input[i].ph, input[i].en,
                   ((float)input[i].ma + (float)input[i].ph + (float)input[i].en) / 3);
            found = 1;
        }
    }
    if (!found) {
        printf("找不到該學生資料。\n");
    }
}

