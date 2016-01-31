#include<stdio.h>

void menu();
float ops(int);

int main(void){
	char inputkey;

	menu();
	while(1){
		inputkey=getchar();
		if(inputkey!='q'){
			switch(inputkey){
				case 'a':
					ops(1);
					break;
				case 'b':
					ops(2);
					break;
				case 'c':
					ops(3);
					break;
				case 'd':
					ops(4);
					break;
				default:
					printf("Input Error!\n");
					break;
			}
			menu();
		}else{
			break;
		}
	}
}

void menu(){
	printf("Please input a,b,c,d to select the operation\n");
	printf("%-15s%-15s\n","a.add.","b.subtract");
	printf("%-15s%-15s\n","c.multiply","d.divide");
	printf("%-15s\n","q.quit");
	printf("Please input your chioce then press ctrl+d to continue:");
}

float ops(int op){
	float val1,val2,val3=0;
	
	printf("Please intput the first number:\n");
	scanf("%a",&val1);
	printf("Please intput the second number:\n");
	scanf("%a",&val2);
	switch(op){
	case 1:val3=val1+val2;
		   break;
	case 2:val3=val1-val2;
		   break;
	case 3:val3=val1*val2;
		   break;
	case 4:if(val2==0){
			   printf("value 2 is 0");
		   }else{
			   val3=val1/val2;
		   }
		   break;
	}
	printf("the value is %10.2f\n",val3);
	return val3;
}

