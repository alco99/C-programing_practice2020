#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void sortBySID(char sid[][10], double score[], int i);
void sortByScore(char sid[][10], double score[], int i);
double getAverage(double score[],int i);
double getQuartile(double score[],int i,int q);
