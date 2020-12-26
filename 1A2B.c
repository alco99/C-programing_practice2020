#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//1A2B
int main(){
	//出題 
	int ans[4];
	int i,j,k;
	srand(time(NULL));
	for(i=0;i<4;i++){
		int check;
		do{
			check=0;
			ans[i] = rand()%10;
			//檢查有沒有一樣的值 
			for(j=0;j<i;j++){
				if (ans[i]==ans[j]){
					check=1;
					break;
				}
			}
		}while(check);
	}
	
	/*
	for(i=0;i<4;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	*/
	
	//猜數字
	int A,B;
	int confirm;
	do{
		confirm=0;
		printf("Please enter your number: ");
		char num[10];
		int guess[4];
		scanf("%s",num);
		
		//判斷有沒有超出範圍 
		if (strlen(num)>4 || strlen(num)<4){
			printf("Illegal answer\n");
			confirm=1;
		}
		
		//判斷有沒有一樣的數 
		for(i=0;i<4;i++){
			for(j=0;j<i;j++){
				if (num[i]==num[j]){
					printf("Illegal answer\n");
					confirm=1;
					break;	
				}
			}
			if(confirm)
				break;
		}
		if(confirm)
			continue;
		
		//轉換型態
		for(i=0;i<4;i++){
			guess[i]=num[i]-48;
		}
		
		//判斷幾A幾B 
		A=0,B=0;
		for(i=0;i<4;i++){
			if(guess[i]==ans[i]){
				A++;
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(guess[j]==ans[i]){
					B++;
				}
			}
		}
		B=B-A;
		printf("%dA%dB\n",A,B);
	}while(A!=4);
	
	//結束 
	printf("You Win");
	return 0;
}
