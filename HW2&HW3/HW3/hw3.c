#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
	srand(time(NULL));
	int a,b,c,d,e,i,j;
	//n,m,row,column,


	printf("m,n,row,column: ");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int A[a][b];

	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			A[i][j]=0;
		}
	}
	A[c][d]=1;


	if(a<=2||a>40||b<2||b>20){
		printf("ERROR\n");
	}
	else{

		int con=0,temp=0;
		while(1){




			e=rand()%8;

			if(e==0&&(c-1>=0&&d-1>=0)){	//左上
				c--;
				d--;
				A[c][d]++;
				temp++;

			}
			else if(e==1&&d-1>=0){	//左
				d--;
				A[c][d]++;
				temp++;

			}
			else if(e==2&&(c+1<b&&d-1>=0)){	//左下
				c++;
				d--;
				A[c][d]++;
				temp++;

			}
			else if(e==3&&c+1<b){	//下
				c++;
				A[c][d]++;
				temp++;

			}
			else if(e==4&&(c+1<b&&d+1<a)){	//右下
				c++;
				d++;
				A[c][d]++;
				temp++;

			}
			else if(e==5&&d+1<a){	//右
				d++;
				A[c][d]++;
				temp++;

			}
			else if(e==6&&(c-1>=0&&d+1<a)){	//右上
				c--;
				d++;
				A[c][d]++;
				temp++;

			}
			else if(e==7&&c-1>=0){	//上
				c--;
				A[c][d]++;
				temp++;

			}


			for(i=0;i<a;i++){	//記總數
				for(j=0;j<b;j++){
					if(A[i][j]!=0){
						con++;
					}
				}
			}
			//printf("%d %d\n",con,a*b);

			if(con==a*b){
				printf("總步數: %d\n",temp);
				for(i=0;i<a;i++){
					for(j=0;j<b;j++){
						printf("%5d ",A[i][j]);
					}
					printf("\n");
				}
				break;
			}
			con=0;
			if(temp>50000){
				printf("超過上限\n");
				break;
			}
		}

	}

	return 0;
}
