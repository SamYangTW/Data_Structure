#include<stdio.h>
#include<stdlib.h>

int square[9][9];
int game(int,int,int,int);

int main(){
	int i,j;
	int size;
	while(1){
		printf("請輸入邊長(0結束): ");
		scanf("%d",&size);
		if(size==0){
			break;
		}
		else if(size%2==0 || size<0){
			printf("請重新輸入邊長(基數5~9): ");
			scanf("%d",&size);
		}
		for(i=0;i<size;i++){	//歸零
        	for(j=0;j<size;j++){
            	square[i][j]=0;
        	}
    	}
    	square[0][size/2]=1; 	//設定值1
    	game(0,size/2,size,2);	//呼叫
	}
	return 0;
}

int game(int row,int column,int s,int con){	//行列值，大小，計數器
	int row1,column1,i,j;
	if(row-1<0){	//左上移動，但超出範圍，下有值右無
		row1=s-1;
	}
	else{
		row1=row-1;
	}
	if(column-1<0){	//左上移動,但超出範圍,下無值右有
		column1=s-1;
	}
	else{
		column1=column-1;
	}
	if(square[row1][column1]!=0){	//左上移動,若左上方有值
        row1=row+1;
        column1=column;
    }
    square[row1][column1]=con;
    con++;
    if(con==s*s+1){
        for(i=0;i<s;i++){
            for(j=0;j<s;j++){
                printf("%5d",square[i][j]);
            }
            printf("\n\n");
        }
        return 0;
    }
    else{
        game(row1,column1,s,con);	//回傳給game
    }
}
