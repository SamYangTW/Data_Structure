#include <stdlib.h>
#include <stdio.h>

// tree struct
struct tree {
    int key;
    struct tree *back;
    struct tree *left;
    struct tree *right;
};
typedef struct tree* treePtr;

// 根節點
treePtr root = NULL;

// 新增節點
treePtr newNode(int n){
	treePtr add = (treePtr)malloc(sizeof(struct tree));
	if(add){
		add->back = NULL;
		add->left = NULL;
		add->right = NULL;
		add->key = n;
		return add;
	}else{
		return NULL;
	}
}

// 插入節點到 tree 中
void add(int n){
	treePtr ptr = root;
	treePtr add = newNode(n);
	if(root == NULL){
		root = newNode(n);
	}else{
		while(1){
			if(add->key > ptr->key){
				if(ptr->right == NULL){
					ptr->right = add;
					add->back = ptr;
					break;
				}else{
					ptr = ptr->right;
				}
			}else if(add->key < ptr->key){
				if(ptr->left == NULL){
					ptr->left = add;
					add->back = ptr;
					break;
				}else{
					ptr = ptr->left;
				}
			}else if(add->key == ptr->key){
				printf("already had this number!\n");
				break;
			}
		}
	}
}

// 中序追蹤
void inorder(treePtr ptr){
	if(ptr){
		inorder(ptr->left);
		printf("%d ", ptr->key);
		inorder(ptr->right);
	}
}

// 刪除節點
void del(int n){
	treePtr del = root;
	treePtr temp = NULL;

	// 找到使用者欲刪除的節點
	while(del != NULL){
		if(n > del->key){
			del = del->right;
		}else if(n < del->key){
			del = del->left;
		}else if(n == del->key){
			break;
		}
	}

	// 若 del 為 NULL，表示節點不存在，則印出錯誤訊息。反之則執行
	if(del){
		// 若有找到節點，則判斷為何種刪除情況
		if((del->left == NULL) && (del->right == NULL)){
			// 欲刪除的節點沒有小孩
			if(del == root){
				// 若為 root，則將 root 變數直接變成 NULL。
				root = NULL;
				free(del);
			}else{
				// 判斷為父節點的左或右節點
				if(n > del->back->key){
					// right child
					del->back->right = NULL;
					free(del);
				}else if(n < del->back->key){
					// left child
					del->back->left = NULL;
					free(del);
				}
			}
		}else if((del->left) && (del->right)){
			// 若為健全，有左小孩與右小孩

			// 先在 temp 存入左小孩
			temp = del->left;

			// 判斷是否 temp 是否有右小孩
			if(temp->right == NULL){
				// 若沒有右小孩，則將 temp 的 key 給愈要刪除的節點，並移除 temp 。
				del->key = temp->key;
				del->left = temp->left;

				// 避免 del->left 因 NULL 而出錯，判斷後在進行設定。
				if(del->left){
					del->left->back = del;
				}
			}else{
				// 若有右小孩，則將 temp 往最右的小孩移動，並重複上述動作。
				while(temp->right != NULL){
					temp = temp->right;
				}
				del->key = temp->key;
				temp->back->right = temp->left;
			}

			free(temp);
		}else if((del->left == NULL) && (del->right)){
			// 只有右子樹
			if(del == root){
				root = root->right;
				free(del);
			}else{
				// 確認欲刪除節點為父節點右、左小孩
				if(n > del->back->key){
					// right child
					del->right->back = del->back;
					del->back->right = del->right;
				}else if(n < del->back->key){
					// left child
					del->right->back = del->back;
					del->back->left = del->right	;
				}
				free(del);
			}
		}else if((del->left) && (del->right == NULL)){
			// 只有左子樹
			if(del == root){
				root = root->left;
				free(del);
			}else{
				// 確認欲刪除節點為父節點右、左小孩
				if(n > del->back->key){
					//right child
					del->left->back = del->back;
					del->back->right = del->left;
				}else if(n < del->back->key){
					// left child
					del->left->back = del->back;
					del->back->left = del->left;
				}
				free(del);
			}
		}
	}else{
		// not found
		printf("No %d in tree\n", n);
	}
}

int main(void){
	int cmd, input;
	while(1){
		printf("[1] Add [2] Delete [0] Exit: ");
		scanf("%d", &cmd);

		switch(cmd){
			case 1:
				printf("add num: ");
				scanf("%d", &input);
				add(input);
				inorder(root);
				printf("\n");
				break;
			case 2:
				printf("del num: ");
				scanf("%d", &input);
				del(input);
				inorder(root);
				printf("\n");
				break;
			case 0:
				printf("Program Exit\n");
				exit(0);
				break;
			default:
				printf("Wrong CMD\n");
				break;
		}
	}
	return 0;
}
