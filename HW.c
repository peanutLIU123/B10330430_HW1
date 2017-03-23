#include<stdio.h>
#include<stdlib.h>

char plaintext[] = "sentfrommyiphone";
int length = sizeof(plaintext) / sizeof(plaintext[0]);
int main(int argc,char **argv)
{		
	printf("Plaintext:sentfrommyiphone\n");
	encry1();
	encry2();
    encry3();	
    encry4();
    encry5();
	encry6();
	 	
	scanf(" ");
	return 0;
}
void  encry1(){
		printf("\n");
		printf("1.");
		printf("\n");
		
		printf("after encry:");
		int i=0;
		
		
		
		char ciphertext[16]; 
		for(i=0;i<length-1;i++){
		int check=plaintext[i]+3;
		if(check>122) check-=26; 
		ciphertext[i]=check;
		printf("%c",ciphertext[i]);
		}
		printf("\n");
		printf("after decry:");
		for(i=0;i<length-1;i++){
		int check=ciphertext[i]-3;
		if(check<97) check+=26; 
		printf("%c",check);
		}
}
void  encry2(){
		
		printf("\n");
		printf("2.\n");
		char row1[] = "abcdefghijklmnopqrstuvwxyz";
		char row2[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
		
		printf("after encry:");
		int i;
		char ciphertext[16];
		for(i=0;i<length-1;i++){
			int j=0;
			for(j=0;j<26;j++){
				if(row1[j]==plaintext[i])
				{
					ciphertext[i]=row2[j];
					break;
				}	
			}
		
		printf("%c",ciphertext[i]);
		}
		
		printf("\n");
		printf("after decry:");
		
		for(i=0;i<length-1;i++){
			int j=0;
			for(j=0;j<26;j++){
				if(row2[j]==ciphertext[i])
				{	
				printf("%c",row1[j]);
					//plaintext[i]=row1[j];
					break;
				}	
			}
		
	
		}
		
}

void  encry3(){
		int i;
		char ciphertext[16];	
		printf("\n");
		printf("3.\n");
		printf("after encry:");
		char key[5][5]={{'d','p','a','b','c'},
						{'e','f','g','h','i'},
						{'k','l','m','n','o'},
						{'q','r','s','t','u'},
						{'v','w','x','y','z'},
						};
		for(i=0;i<length-1;i+=2){
			char a=plaintext[i];
			char b=plaintext[i+1];
			int row1,col1;
			int row2,col2;
			int j,k;
			for(j=0;j<5;j++){
				for(k=0;k<5;k++){
					if(key[j][k]==a) row1=j,col1=k;
					if(key[j][k]==b) row2=j,col2=k;
				}
			}
			
			if(row1==row2){
				if(++col1>4)col1-=5;
				if(++col2>4)col2-=5;
				ciphertext[i]=key[row1][col1];
				ciphertext[i+1]=key[row1][col2];
			}
			else if(col1==col2){
				if(++row1>4)row1-=5;
				if(++row2>4)row2-=5;
				ciphertext[i]=key[row1][col1];
				ciphertext[i+1]=key[row2][col1];
			}
			else{
				ciphertext[i]=key[row1][col2];
				ciphertext[i+1]=key[row2][col1];
			}
		}
		for(i=0;i<16;i++)
		printf("%c",ciphertext[i]);
		
		
		printf("\n");
		printf("after decry:");
		for(i=0;i<length-1;i+=2){
			char a=ciphertext[i];
			char b=ciphertext[i+1];
			int row1,col1;
			int row2,col2;
			int j,k;
			for(j=0;j<5;j++){
				for(k=0;k<5;k++){
					if(key[j][k]==a) row1=j,col1=k;
					if(key[j][k]==b) row2=j,col2=k;
				}
			}
			
			if(row1==row2){
				if(--col1<0)col1+=5;
				if(--col2<0)col2+=5;
				printf("%c%c",key[row1][col1],key[row1][col2]);
				
			}
			else if(col1==col2){
				if(--row1<0)row1+=5;
				if(--row2<0)row2+=5;
				printf("%c%c",key[row1][col1],key[row2][col1]);
				
			}
			else{
				printf("%c%c",key[row1][col2],key[row2][col1]);
			
			}
		}
	
}

void  encry4(){
		printf("\n");
		printf("4.");
		printf("\n");
		printf("after encry:");
		char operator_key[3][5]={{'0','1','0','1','0'},
							{'0','1','1','0','0'},
							{'1','0','0','1','1'}} ;
		int i=0;
	
		char record[16][5];
		char ciphertext[16]; 
		for(i=0;i<length-1;i++){
			char operator_i[5]={'0','0','0','0','0'};
			int a=plaintext[i]-97;
		
			int c=4;
			while(a>0){
				int b=a%2;
				a=a/2;
				if(b==1) operator_i[c]='1';
				
				c--; 
			}
		
			int j,z=16;
		
			int final_sum=0; 
			for(j=0;j<5;j++){
				if(operator_key[i%3][j]!=operator_i[j]) {
					final_sum+=z;
					record[i][j]='1';
				}
				else record[i][j]='0';
			 	
				z=z/2;
			}
			if(final_sum>25)final_sum-=26;
			
			ciphertext[i]=97+final_sum;
			
		}
		
		for(i=0;i<length-1;i++){
			printf("%c",ciphertext[i]);
		}
		printf("\n");
		printf("after decry:");
		for(i=0;i<length-1;i++){
			char operator_i[5]={'0','0','0','0','0'};
			int a=ciphertext[i]-97;
		
			int c=4;
			while(a>0){
				int b=a%2;
				a=a/2;
				if(b==1) operator_i[c]='1';
				
				c--; 
			}
			
			int j,z=16;
			
			int final_sum=0; 
			for(j=0;j<5;j++){
				if(operator_key[i%3][j]!=record[i][j])
			 	final_sum+=z;
				z=z/2;
			}
			if(final_sum>25)final_sum-=26;
			printf("%c",97+final_sum);
			
			
		}
}

void  encry5(){
		printf("\n");
		printf("5.");
		printf("\n");
		
		printf("after encry:");
		int i=0,j;
		char ciphertext[16];	
		char new_plain[length/8][8];
		char new_cipher[length/8][8];
		for(i=0;i<2;i++){
			for(j=0;j<8;j++)
			new_plain[i][j]=plaintext[8*i+j];
		}
		
		int b=0,k;
		int z=length/8;
		int key[8]={5,2,8,3,4,6,7,1};
		for(i=0;i<8;i++){
			
			for(j=0;j<8;j++){
				if(key[j]==i+1){
						
					//int z=length/8;
					for(k=0;k<z;k++)
					ciphertext[b+k]=new_plain[k][j];
				}
			}
			b+=z;
			//new_plain[i][j]=plaintext[8*i+j];
		}
		for(i=0;i<length-1;i++){
			printf("%c",ciphertext[i]);
		}
		printf("\n");
		printf("after decry:");
		for(i=0;i<8;i++){
			for(j=0;j<z;j++)
				new_cipher[j][i]=ciphertext[(key[i]-1)*z+j];	
		}
		for(i=0;i<z;i++){
			for(j=0;j<8;j++)
			printf("%c",new_cipher[i][j]);
		}
	
}

void  encry6(){
	printf("\n");
	printf("6.");
	
	char plaintext[] = " sentfrommyiphone";
	printf("\n");
	printf("after encry:");
	int table[17]={0,15,11,2,10,16,3,7,14,4,12,9,6,1,5,8,13};
	int reverse_table[17]={0,15,11,2,10,16,3,7,14,4,12,9,6,1,5,8,13};
	char ciphertext[17];
		int i,j;
		for(i=1;i<=16;i++){
			for(j=1;j<=16;j++)
			{
				if(table[j]==i)
				break;
			}
			ciphertext[j]=plaintext[i];
		}
		for(i=1;i<=16;i++)
		printf("%c",ciphertext[i]);
		printf("\n");
	printf("after decry:");
		for(i=1;i<=16;i++){
			for(j=1;j<=16;j++)
			{
				if(table[j]==i)
				break;
			}
			printf("%c",ciphertext[j]);
		}
	
}
