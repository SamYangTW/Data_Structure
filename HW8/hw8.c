
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 50

// tree struct
struct tree{
    int key;
    struct tree *left;
    struct tree *right;
};
typedef struct tree* treePtr;

// root node
treePtr root;

// stack
treePtr stack[MAX_SIZE];
int top = -1;

/*
    tree Operation [start]
*/

// 新增節點
treePtr newNode(int n){
    treePtr add = (treePtr)malloc(sizeof(struct tree));

    if(add){
        add->key = n;
        add->left = NULL;
        add->right = NULL;
        return add;
    }else{
        return NULL;
    }
}

// 插入節點至樹中
void add(int n){
    treePtr ptr = root;
    treePtr add = newNode(n);

    if(root == NULL){
        root = add;
    }else{
        while(1){
            if(add->key > ptr->key){
                // 比較大
                if(ptr->right != NULL){
                    ptr = ptr->right;
                }else{
                    ptr->right = add;
                    break;
                }
            }else if(add->key < ptr->key){
                // 比較小
                if(ptr->left != NULL){
                    ptr = ptr->left;
                }else{
                    ptr->left = add;
                    break;
                }
            }else if(add->key == ptr->key){
                printf("Same Key\n");
                break;
            }
        }
    }
}


int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

// stack 是否已滿
int isFull(){
    if(top == 50){
        return 1;
    }else{
        return 0;
    }
}

// stack pop
treePtr pop(){
    if(!isEmpty()){
        return stack[top--];
    }else{
        return NULL;
    }
}

// stack push
void push(treePtr add){
    if(!isFull()){
        stack[++top] = add;
    }
}

/*
    Stack Operation [end]
*/

// preorder print 前序追蹤
void preorder(treePtr node){
    while(1){
        for(;node;node=node->left){
            printf("%d ", node->key);
            if(node->right){
                push(node->right);
            }
        }
        node = pop();
        if(!node){
            break;
        }
    }
}

int main(void){
    int cmd, input;

    while (1){
        printf("[1]input node [2]preorder: ");
        scanf("%d", &cmd);

        switch (cmd){
        case 1:
            printf("num:");
            scanf("%d", &input);
            add(input);
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        default:
            printf("Wrong CMD\n");
            break;
        }
    }

    return 0;
}
