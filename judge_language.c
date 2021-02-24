/*判斷語言*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char inf[15];
	int k=0;
	while(1){
		gets(inf);
		if(inf[0]=='#'){
			break;
		}
		//puts(inf);
		int check=1,i;
		char hello[5][15]={"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
		char lan[5][15]={"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};
		k++;
		printf("Case %d:",k);
		for(i=0;i<5;i++){
			if(strcmp(inf,hello[i])==0){
				puts(lan[i]);
				check=0;
				break;
			}
		}
		if(check){
			printf("UNKNOWN\n");
		}
	}
	return 0;
}
