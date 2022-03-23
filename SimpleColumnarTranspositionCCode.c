/* Simple Columnar Transposition Cipher ---By Yogesh Bhople */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
char * encrypt(char pt[],int col, int *col_seq) {
	 int pt_len = strlen(pt);
	 printf("\n PT length is %d",pt_len);
	 char *ct =(char *)malloc(sizeof(char)*pt_len);
	 int i,j;
	 int rows = ceil((float)pt_len/col);
	 printf("\n no. of rows is %d",rows);
	 char **row_ptr = (char **)malloc(sizeof(char *)*rows);
	 for(i=0;i<rows;i++)
	 	row_ptr[i]=(char *)malloc(sizeof(char)*col);
	 int str_ptr=0;	
	 for(i=0;i<rows;i++) {
	 	for(j=0;j<col;j++) {
	 		if(str_ptr<pt_len)
	 			row_ptr[i][j]=pt[str_ptr++];
	 		else
			 	row_ptr[i][j]='$';	
	  	}
	}
	
	//row_ptr[i][j]='\0';
	printf("\n");
	 for(i=0;i<rows;i++) 
	 	for(j=0;j<col;j++)
	 		printf("%c",row_ptr[i][j]);
	 int k=0; 
	 for(i=0;i<col;i++)
	 	for(j=0;j<rows;j++) {
	 		if(row_ptr[j][col_seq[i]-1]!='$')
	 			ct[k++]=row_ptr[j][col_seq[i]-1];
		 } 	
		 ct[k]='\0';	
	return ct;
}
char * decrypt(char *ct,int col, int *col_seq) {
	 int ct_len = strlen(ct);
	 char *pt =(char *)malloc(sizeof(char)*ct_len);
	 int i,j,count;
	 int str_ptr=0;
	 int lastRowFilledCell=ct_len%col;
	 int empty_cell=col-lastRowFilledCell;
	 int rows = ceil((float)ct_len/col);
	 printf("\n no. of rows is %d",rows);
	 char **row_ptr = (char **)malloc(sizeof(char *)*rows);
	 for(i=0;i<rows;i++)
	 	row_ptr[i]=(char *)malloc(sizeof(char)*col);
	 for(i=0;i<rows;i++) 
	 	for(j=0;j<col;j++)
	 		row_ptr[i][j]='*';	
	 for(count=0;count<empty_cell;count++)
	 	row_ptr[rows-1][col-1-count]='$';
	 for(i=0;i<rows;i++) 
	 	for(j=0;j<col;j++)
	 		printf("%c",row_ptr[i][j]);	
	 printf("\n Empty cells are %d",empty_cell);
	 str_ptr=0;
	 for(i=0;i<col;i++) {
	 	for(j=0;j<rows;j++) {
	 		if(str_ptr<ct_len ) {
	 			if(row_ptr[j][col_seq[i]-1]!='$') {
	 				row_ptr[j][col_seq[i]-1]=ct[str_ptr++];
	 				//str_ptr++;
				 }
				 }
	 		
	  		}
	 }
	  	printf("\n");
	 for(i=0;i<rows;i++) 
	 	for(j=0;j<col;j++)
	 		printf("%c",row_ptr[i][j]);
	 int k=0; 
	 for(i=0;i<rows;i++)
	 	for(j=0;j<col;j++) {
	 		if(row_ptr[i][j]!='$')
	 			pt[k++]=row_ptr[i][j];
		 } 	
		 pt[k]='\0';	
	return pt;		 	
}
int main() {
	char pt[100];
	char *ct,*dpt;
	int col,i;
	printf("\n Enter key---no. of colums \n");
	scanf("%d",&col);
	int *col_seq=(int *)malloc(sizeof(int)*col);
	printf("\n Enter Key---column seq.\n");
	for(i=0;i<col;i++)
		scanf("%d",&col_seq[i]);
	for(i=0;i<col;i++)	
		printf("%d",col_seq[i]);
	printf("\n Enter plain text \n");
	scanf("%s",pt);	
	ct=encrypt(pt,col,col_seq);
	printf("\n Encrypted Cipher Text is %s",ct);
	decrypt(ct,col,col_seq);
	dpt=decrypt(ct,col,col_seq);
	printf("Decrypted Cipher Text is : %s",dpt); 
	getch();
	return 1;
}
