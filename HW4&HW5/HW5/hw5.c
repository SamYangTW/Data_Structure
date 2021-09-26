#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int *stack;

void create(){//創造陣列
	int i,n;

	stack = (int* )malloc(sizeof(int )*MAX);

	for (i = 0 ; i < MAX ; i++){//建立初始值
		stack[i] = 0;
	}
}
int isFull(int* top){// 判斷陣列是否已滿

	if (*top >= MAX)
		return 1;
	else
		return 0;
}
int isEmpty(int* top){//判斷陣列是否為空

	if (*top == -1)
		return 1;
	else
		return 0;

}
void push(int* top,int item)//將資料存入陣列
{
    if (isFull(top))
        printf("堆疊已滿!\n");
    else
        stack[++(*top)] = item;
}


int pop(int* top)//將資料提出
{
    if(isEmpty(top))
        printf("堆疊已空!\n");
    else{
    	return stack[(*top)--];
	}

}

void InToPostfix(char infix[] , int *top)
{
    int i, j , k , nth;
    create();
    int op1,op2;
    for(i = strlen(infix) - 1, j = 0; i >= 0; i--) {//從陣列最右邊開始做判斷
        switch(infix[i])
        {
            case '+': case '-': case '*': case '/':case '^': //決定做何種運算
                op1 = pop(top);//pop(top)-'0'??
                op2 = pop(top);

                if(infix[i] == '+')	    //---'A+B'
                	push(top,op1 + op2);
                else if(infix[i] == '-')//---'A-B'
                	push(top,op1 - op2);
                else if(infix[i] == '*')//---'A*B'
                	push(top,op1 * op2);
                else if(infix[i] == '/')//---'A/B'
                	push(top,op1 / op2);
                else if(infix[i] == '%')//---'A%B'
                	push(top,op1 % op2);
                else if(infix[i] == '^'){//---'A^B'
					nth=op1;
					for(j=0;j<op2-1;j++)
					{

						op1=op1*nth;
						printf("%d  ",op1);
					}
					push(top,op1);
				}
                break;

            default:  // 運算元直接輸出
                push(top,infix[i] - '0');//infix[i]//infix[i]為0~9字元時，
										 //將其轉乘數字0~9 存入整數陣列
                break;
	    }
	    //int stack[]={76 35 2}
		//infix +-1/*2*+34567
		//
	}
}


int main(void){
	int n;
	int top = -1;
	char prefix[MAX];
	while(1){
		printf("輸入前置式資料 :");
		scanf("%s",prefix);//輸入前置式資料
		if(strlen(prefix) < 3){//當輸入資料無法計算時跳出迴圈
			printf("Error");
			break;
			}

		InToPostfix(prefix,&top);//運算

		printf("運算結果: %d\n",stack[0]);//顯示資料
		while(top!=-1){
			pop(&top);//顯示資料後將資料刪除以利下一次運算
		}


	}
}
