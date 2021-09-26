#include<stdio.h>
#include<stdlib.h>

struct data{
 int nth;	//係數
 int fac;	//次方
}A[1000],temp;

int main(){
	int i,j,cot=0,cot1=0,cot2=0;
	// , ,A的記數,B的記數,C的記數
	int startA=0,finishA,startB,finishB,startall,finishall;
	printf("輸入多項式A: \n");
	while(1){
		printf("輸入係數和次方: ");
		scanf("%d %d",&A[cot].nth,&A[cot].fac);
  		if(A[cot].nth==0&&A[cot].fac==0){
  			break;
  		}
  		else{
  			cot++;	//A的記數來記A有幾項
  		}
	}
	finishA=cot;
	startB=cot+1;
	cot1=cot+1;
	printf("輸入多項式B: \n");
	while(1){

		printf("輸入係數和次方: ");
  		scanf("%d %d",&A[cot1].nth,&A[cot1].fac);
  		if(A[cot1].nth==0&&A[cot1].fac==0){
  			break;

  		}
		else{
			cot1++;		//用B的記數來記B有幾項
		}

	}
	finishB=cot1;
	startall=cot1+1;
	cot2=cot1+1;
	for(i=0;i<finishA;i++){
		for(j=startB;j<finishB;j++){
			A[cot2].fac=A[i].fac+A[j].fac;
			A[cot2].nth=A[i].nth*A[j].nth;
			cot2++;	////用ALL的記數來記ALL有幾項
		}

	}
	finishall=cot2;
	for(i=startall;i<finishall;i++){	//判斷次方是不是一樣
		for(j=i+1;j<finishall;j++){
			if(A[i].fac==A[j].fac){		//要是一樣把下一位的數值加到上一個，在把下一個值歸零避免被記到
					A[i].nth=A[i].nth+A[j].nth;
					A[j].nth=0; 	// 係數歸零
					A[j].fac=0;		//次方歸零
			}
		}
	}
	for(i=startall;i<finishall;i++){	//排序
		for(j=startall;j<finishall-1;j++){
			if(A[j].fac<A[j+1].fac){
				temp.fac=A[j].fac;
				A[j].fac=A[j+1].fac;
				A[j+1].fac=temp.fac;

				temp.nth=A[j].nth;
				A[j].nth=A[j+1].nth;
				A[j+1].nth=temp.nth;
			}
		}
	}
	printf("相乘結果:");
	for(j=startall;j<finishall;j++){
  		if(A[j].fac!=0){
       		if(A[j].nth!=0)
        		printf("%dx^%d",A[j].nth,A[j].fac);
        	if(j+1<finishall&&A[j+1].nth>0)
   				printf("+");
    	}
    	else if(A[j].fac==0&&A[j].nth!=0)
        	printf("%d",A[j].nth);

	}
    printf("\n");
 	return 0;

}
