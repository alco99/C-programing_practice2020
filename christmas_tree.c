#include <stdio.h> 

void printChar (char c, int n, int newLine) {
    int i;
    for (i = 0; i < n; i++)
        printf("%c", c);
    if (newLine)
        printf("\n");
    return;
}

int main(){
	int num, hgh, grw, tkw, tkh;
	int check;
	//層數 
	do{
		check=0;
		printf("Enter the number of tree layers (2 to 5):");
		scanf("%d",&num);
		if(num<2 || num>5){
			check=1;
			printf("*ERROR*\n");
		}
	}while(check);
	//頂層高度 
	do{
		check=0;
		printf("Enter the height of top layer (3 to 6):");
		scanf("%d",&hgh);
		if(hgh<3 || hgh>6){
			check=1;
			printf("*ERROR*\n");
		}
	}while(check);
	//寬度變化 
	do{
		check=0;
		printf("Enter the growth of each tree layer (1 to 5):");
		scanf("%d",&grw);
		if(grw<1 || grw>5){
			check=1;
			printf("*ERROR*\n");
		}
	}while(check);
	//樹幹寬 
	do{
		check=0;
		printf("Enter the trunk width (odd number, 3 to 9):");
		scanf("%d",&tkw);
		if(tkw<3 || tkw>9){
			check=1;
			printf("*ERROR*\n");
		}
		else if(tkw%2==0){
			check=1;
			printf("*ERROR*\n");
		}
	}while(check);
	//樹幹高 
	do{
		check=0;
		printf("Enter the trunk height (4 to 10):");
		scanf("%d",&tkh);
		if(tkh<4 || tkh>10){
			check=1;
			printf("*ERROR*\n");
		}
	}while(check);
	//印聖誕樹
	int hgh_max=hgh, wgh_max=1, i, j;
	int hgh_new=hgh-2;
	
	for(i=1; i<num; i+=1){
		hgh_max = hgh_max+grw;
	}
	for(i=1; i<hgh_max; i+=1){
		wgh_max = wgh_max+2;
	}
	printf("\n");
	int k, l;
	printChar(' ', (wgh_max)/2, 0);
	printf("#\n");
	for(j=0; j<num; j++){
		l=1;
		for(k=0; k<hgh_new; k++){
			printChar(' ', (wgh_max-2-l)/2, 0);
			printf("#");
			printChar('@', l, 0);
			printf("#\n");
			l+=2;
		}
		printChar(' ', (wgh_max-2-l)/2, 0);
		printChar('#', l+2, 1);
		hgh_new = hgh_new+grw;
	}
	//印聖誕樹幹 
	int m, tkw_new;
	tkw_new=(wgh_max)/2-(tkw/2);
	for(m=0;m<tkh;m++){
		printChar(' ',tkw_new,0);
		printChar('|',tkw,1);
	}
	
	return 0;
}
