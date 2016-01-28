#include<stdio.h>

int main(void){
	float x=0;
	char name[20];
	
	printf("please enter the your name :");
	scanf("%s",name);
	printf("please enter the foot values :");
	scanf("%f",&x);
	printf("hi %s, foot %2f is %2f meters",name,x,x*2.54);
	return 0;
}
