#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void sortBySID(char sid[][10], double score[], int i){ 
	int j, k, l;
    double change; 
    char tmp[10]; 
    for(l=0; l<i-1; l++){ 
        for(j=0; j<i-l-1; j++){ 
        	if(strcmp(sid[j], sid[j+1])>0){  //sid[j]>sid[j+1] 
    	        //交換SID  
        	    for(k=0; k<8; k++){ 
        		   tmp[k] = sid[j][k]; 
            	} 
            	for(k=0;k<8;k++){ 
            	    sid[j][k] = sid[j+1][k]; 
            	} 
            	for(k=0;k<8;k++){ 
            	    sid[j+1][k] = tmp[k]; 
            	} 

        	    //交換成績 
            	change = score[j]; 
            	score[j] = score[j+1]; 
            	score[j+1] = change; 
        	} 
    	} 
    } 
    for(l=0;l<i;l++){
        printf("%s   %3.0f\n",sid[l],score[l]);
	}
} 

void sortByScore(char sid[][10], double score[], int i){ 
	int j, k, l;
    double change;
    char tmp[10]; 
    for(l=0; l<i-1; l++){ 
        for(j=0; j<i-l-1; j++){ 
        	if(score[j]>score[j+1]){  //score[j]>score[j+1] 
            	//交換SID  
            	for(k=0; k<8; k++){ 
                	tmp[k] = sid[j][k];
            	} 
            	for(k=0; k<8; k++){ 
                	sid[j][k] = sid[j+1][k];
            	} 
            	for(k=0; k<8; k++){ 
                	sid[j+1][k] = tmp[k]; 
            	}
            	//交換成績 
            	change = score[j]; 
            	score[j] = score[j+1]; 
            	score[j+1] = change; 
        	} 
    	} 
    } 
    for(l=0;l<i;l++){
        printf("%s   %3.0f\n",sid[l],score[l]);
	}
} 

double getAverage(double score[],int i){  
    int j;  
    double sum=0,avg;  
    for(j=0; j<i; j++){  
        sum = sum+score[j];  
    }  
    avg = sum/i*1.0;
    return avg;
}

double getQuartile(double score[],int i,int q){
	int j, k, l, check; 
    double change;
    char tmp[10];
	int Q1, Q2, Q3; 
    double quartile[3],qua; 
    
    for(l=0; l<i-1; l++){ 
        for(j=0; j<i-l-1; j++){ 
        	if(score[j]>score[j+1]){  //score[j]>score[j+1] 
            	//交換成績 
            	change = score[j]; 
            	score[j] = score[j+1]; 
            	score[j+1] = change; 
        	} 
    	} 
    }  
     
    for(j=1;j<4;j++){
    	qua = 1.0*i*25*j/100;
    	if((qua-(int)qua)==0){
    		check=(int)qua;
    		quartile[j-1] = 1.0*(score[check]+score[check-1])/2;
		}
		else{
			check=(int)qua;
			quartile[j-1] = score[check];
		}
	} 
    return quartile[q-1]; 
} 
