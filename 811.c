#include<stdio.h>
#include<ctype.h>

int main(void){
    char ch;
    int filelength=0,count=0,flag=0,charflag=1,charcount=0,wordcount=0;

    while((ch=getchar())!=EOF){
        filelength++;
/*		printf("%3c%4d",ch,ch);*/
		if(islower(ch)&&flag==0){
			count++;
			putchar(ch);
		}
		else if(islower(ch)&&flag==1){
			printf("\ntotal %d upper characters\n",count);
			count=1;
			flag=0;
			putchar(ch);
		}else if(isupper(ch)&&flag==1){
			count++;
			putchar(ch);
		}
		else if(isupper(ch)&&flag==0){
			printf("\ntotal %d lower characters\n",count);
			count=1;
			flag=1;
			putchar(ch);
		}
		if(isalpha(ch)){
			charcount++;
			charflag=0;
		}else{
			if(charflag==0){
				wordcount++;
				charflag=1;
			}
		}
    }

    printf("there are %d characters in file\n",filelength);
	printf("there are %d characters and %d words,average word length is %2.2f\n",charcount,wordcount,(float)charcount/(float)wordcount);

}
