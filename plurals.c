/*改複數
  先輸入不規則的單複數型態，再輸入需要轉的單詞，
  a是不規則複數型態的個數，b是需要轉型型態的單詞個數*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	char table[a][2][20];
	int i,j;
	for(i=0;i<a;i++){
		scanf("%s %s%*c",&table[i][0],&table[i][1]);
	}
	char newinfo[20];
	for(i=0;i<b;i++){
		gets(newinfo);
		int len=strlen(newinfo);
		int check=1;
		for(j=0;j<a;j++){
			if(strcmp(newinfo,table[j][0])==0){
				puts(table[j][1]);
				check=0;
				break;
			}
		}
		if(check){
			if(newinfo[len-1]=='y' && !(newinfo[len-2]=='a' || newinfo[len-2]=='e' || newinfo[len-2]=='i' || newinfo[len-2]=='o' || newinfo[len-2]=='u')){
				for(j=0;j<len-1;j++){
					printf("%c",newinfo[j]);
				}
				printf("ies\n");
			}
			else if(newinfo[len-1]=='o' || newinfo[len-1]=='s' || newinfo[len-1]=='x'){
				for(j=0;j<len;j++){
					printf("%c",newinfo[j]);
				}
				printf("es\n");
			}
			else if(newinfo[len-1]=='h' && (newinfo[len-2]=='s' || newinfo[len-2]=='c')){
				for(j=0;j<len;j++){
					printf("%c",newinfo[j]);
				}
				printf("es\n");
			}
			else{
				for(j=0;j<len;j++){
					printf("%c",newinfo[j]);
				}
				printf("s\n");
			}
		}
	}
	return 0;
}
