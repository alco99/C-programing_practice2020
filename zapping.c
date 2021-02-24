/*從頻道0~99台，在只能往上和往下的限制中，求最少要移動多少*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	while(1){
		int start,end;
		int forward=0,backward=0;
		scanf("%d %d",&start,&end);
		if(start==-1 && end==-1){
			break;
		}
		if(start<end){
			forward=end-start;
			backward=(100-end)+start;
			if(forward>backward){
				printf("%d\n",backward);
			}
			else{
				printf("%d\n",forward);
			}
		}
		else if(start>end){
			forward=(100-start)+end;
			backward=start-end;
			if(forward>backward){
				printf("%d\n",backward);
			}
			else{
				printf("%d\n",forward);
			}
		}
	}
	return 0;
}
