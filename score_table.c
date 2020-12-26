#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "floatlib.h"

int main() { 
    char sub_name[10], pro_name[5]; 
    char sid[100][10]; 
    double score[100]; 
    int i=0,check; 
    printf("Please input subject name: "); 
    scanf("%s",sub_name); 
    printf("Please input professor's name: "); 
    scanf("%s",pro_name); 
    printf("Please input SID and Score (0 0 to stop input): \n"); 
    while(1){ 
        check=0; 
        printf(">> "); 
        scanf("%s %lf",&sid[i],&score[i]); 
        //如果輸入0 0就離開  
        if(sid[i][0]=='0' && score[i]==0 && strlen(sid[i])==1){ 
            break; 
        } 
        while(1){ 
            //檢查學號首字母是不是大寫 成績範圍 
            if(isupper(sid[i][0])==1 && score[i]>=0 && score[i]<=100){ 
                check=1; 
            } 
            else{ 
            	check=0;
                break; 
            } 
            //檢查 
            if(strlen(sid[i])==8){ 
                check=1; 
            } 
            else{ 
            	check=0;
                break;
            } 
            //依次檢查學號是不是數字  
            int j; 
            for(j=1;j<8;j++){ 
                if(isdigit(sid[i][j])){ 
                    check=1; 
                } 
                else{
                    check=0; 
                    break;
                }
            }
            break;
        }
        //學號、成績不合  
        if(check){ 
            i++; 
        } 
        else{ 
            printf("Illegal input\n"); 
            continue; 
        } 
    } 
	
    int choose,k,l;
    char sid_new[100][10]; 
    double score_new[100]; 
    printf("\nSort By (1.SID 2.Score 0.exit):"); 
    scanf("%d",&choose);
    while(choose!=0){
    	/*for(l=0;l<i;l++){
			strcpy(sid_new[l],sid[l]);
			score_new[l] = score[l];
		} */
		switch(choose){
            case 1:
                printf("\n%s\nProfessor: %s\n",sub_name, pro_name); 
                printf("---------------------\n"); 
                printf("SID      Score\n"); 
                sortBySID(sid,score,i);
                printf("---------------------\n"); 
                printf("Average: %.4f\n",getAverage(score_new,i));
                printf("Q1: %.1f Q2: %.1f Q3: %.1f\n",getQuartile(score_new,i,1),getQuartile(score_new,i,2),getQuartile(score_new,i,3));
                break; 
            case 2: 
                printf("\n%s\nProfessor: %s\n",sub_name, pro_name); 
                printf("---------------------\n"); 
                printf("SID      Score\n"); 
                sortByScore(sid,score,i);
                printf("---------------------\n"); 
                printf("Average: %.4f\n",getAverage(score_new,i));
                printf("Q1: %.1f Q2: %.1f Q3: %.1f\n",getQuartile(score_new,i,1),getQuartile(score_new,i,2),getQuartile(score_new,i,3));
                break; 
            default: 
                break; 
        } 
        /*switch(choose){
            case 1:
                printf("\n%s\nProfessor: %s\n",sub_name, pro_name); 
                printf("---------------------\n"); 
                printf("SID      Score\n"); 
                sortBySID(sid_new,score_new,i);
                printf("---------------------\n"); 
                printf("Average: %.4f\n",getAverage(score_new,i));
                printf("Q1: %.1f Q2: %.1f Q3: %.1f\n",getQuartile(score_new,i,1),getQuartile(score_new,i,2),getQuartile(score_new,i,3));
                break; 
            case 2: 
                printf("\n%s\nProfessor: %s\n",sub_name, pro_name); 
                printf("---------------------\n"); 
                printf("SID      Score\n"); 
                sortByScore(sid_new,score_new,i);
                printf("---------------------\n"); 
                printf("Average: %.4f\n",getAverage(score_new,i));
                printf("Q1: %.1f Q2: %.1f Q3: %.1f\n",getQuartile(score_new,i,1),getQuartile(score_new,i,2),getQuartile(score_new,i,3));
                break; 
            default: 
                break; 
        } */
        printf("\nSort By (1.SID 2.Score 0.exit):"); 
        scanf("%d",&choose); 
    }
    
    return 0; 
} 
