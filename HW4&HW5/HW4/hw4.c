#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int *stack;

int create(int* top){//創造陣列
	int i,n;

	stack = (int* )malloc(sizeof(int )*MAX);

	for (i = 0 ; i < MAX ; i++){
		stack[i]=0;
	}
	*top = -1;
}
int isFull(int* top){//判斷陣列是否為滿

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
int priority(char op) {//比較各運算子的優先順序
    switch(op) {
        case '+': case '-'  : return 12 ;
        case '*': case '/'  : case '%'  : return 13;
        case '^': return 14 ;
        default : return 0  ;
    }
}


void push(int* top,int item)//將運算子存入stack
{
    if (isFull(&(*top)))
        printf("堆疊已滿!\n");
    else
        stack[++(*top)] = item;
}


char pop(int* top)//將運算子從stack取出
{
    if(isEmpty(top))
        printf("堆疊已空!\n");
    else
        return stack[(*top)--];
}

void InToPostfix(char infix[], char postfix[])
{
    int i, j, top = -1;
    create(&top);
    for(i = strlen(infix) - 1 , j = 0 ; i >= 0 ; i--)
        switch(infix[i])
        {
            case ')':  // 運算子堆疊
                /*  1. push infix[i] 至 stack 中 */
                push(&top , infix[i]);
                break;
            case '+': case '-': case '*': case '/': case '^': case '%':
                while(priority(stack[top]) > priority(infix[i])) {  // 比較優先權
                    /*  2. 將 stack 中值 pop 出 存入 postfix[j++] 中*/
                    postfix[j++] = pop(&top);
                }
                /*  2. push infix[i] 至 stack 中 */  //將該運算子加入堆疊
                push(&top,infix[i]);

                break;
            case '(':
                while(stack[top] != ')') { // 遇 ) 輸出至 (
                    /*  3. 將 stack 中值 pop 出 存入 postfix[j++] 中 */
                    postfix[j++] = pop(&top);
                }
                /* 將 stack 中值 pop 出 */  // 不輸出 (
                pop(&top);
                break;
            default:  // 運算元直接輸出
                postfix[j++] = infix[i];
	    }
    while(top > -1) {
		postfix[j++] = pop(&top);
	} //將堆疊內所有運算元輸出
        /*  5. 將 stack 中值 pop 出 存入 postfix[j++] 中 */

}
int main(void){
	int n;
	char infix[MAX],postfix[MAX];

	while(1){
		for(n = 0; n < MAX; n++){//陣列初始化
			infix[n]    = '\0';
			postfix[n]  = '\0';
		}

		printf("請輸入中置式資料 :");
		scanf("%s",infix);
		if(strlen(infix) < 3){//當輸入資料無法計算時跳出迴圈
			printf("Error");
			break;
			}

		InToPostfix(infix , postfix);//轉前置的副函式
		printf("轉置結果 :");
			for(n = strlen(postfix) - 1 ; n >= 0;n--)//顯示資料
				printf("%c",postfix[n]);
			printf("\n");
	}
}
