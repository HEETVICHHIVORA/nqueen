#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>


int n=5;

int mat[5][5];

int count=0;


bool isSafe(int currX,int currY){


int i=currX;

int j=currY;


while(i>=0){

if(mat[i][j]==1) return 0;

i--;

}


i=currX;

j=currY;


while(i>=0 && j>=0){

if(mat[i][j]==1) return 0;

i--;

j--;

}


i=currX;

j=currY;


while(i>=0 && j<n){

if(mat[i][j]==1) return 0;

i--;

j++;

}




return 1;


}



void putq(int row,int queen){


if(queen==0){


++count;


for(int i=0;i<n;i++){

for(int j=0;j<n;j++){

printf("%d\t",mat[i][j]);

}

printf("\n");

}

printf("\n");

printf("\n");


return;


}


for(int col=0;col<n;col++){

int currX=row;

int currY=col;


if(row==0 || isSafe(currX,currY) ){  

              

mat[currX][currY]=1;

putq(row+1,queen-1);

mat[currX][currY]=0;

}


}



}






void main(){


for(int i=0;i<n;i++){

for(int j=0;j<n;j++){

mat[i][j]=0;

}

}





int queens=n;

putq(0,queens);


printf("Total feasible solutions: %d\n",count);

}