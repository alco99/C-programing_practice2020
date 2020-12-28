#include <stdio.h> 

void move(char soure,char dest,char aux,int n);

void move(char soure,char dest,char aux,int n){
	if(n==1){
		printf("%c --> %c\n",soure,dest);
	}
	else{
		move(soure,aux,dest,n-1);
		move(soure,dest,aux,1);
		move(aux,dest,soure,n-1);
	}
}

int main(){
	move('A','C','B',3);
	return 0;
}
