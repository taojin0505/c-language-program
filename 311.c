#include<stdio.h>
#include<math.h>
#include<limits.h>

int main(void){
    int i=0;
    float f=0.0;
    unsigned int r=0;

    printf("\nINT UNSIGNED INT LENGTH AND MAX VALUE\n\n");
    i=INT_MAX;
    printf("int i is %d,f is %f,r is %d\n",i,f,r);
    printf("int i %d length is %d\n",i,sizeof(i));
    printf("2 power 31    is %2f\n",pow(2,31));
    printf("int i -1      is %d\n",i-1);
    printf("int i +1      is %d\n",i+1);
    printf("int i +2      is %d\n",i+2);
    r=INT_MAX;
    printf("value %d length is %d\n",r,sizeof(r));
    printf("2 power 31 is %d\n",(int)pow(2,31));
    printf("2 power 32 is %u\n",(unsigned int)pow(2,32));
    printf("r + 1      is %u\n",r+1);
    printf("r * 2      is %u\n",r*2);
    printf("r * 4      is %u\n",r*4);
    printf("r * 8      is %u\n",r*8);


    printf("\nFloat LENGTH AND MAX VALUE:\n\n");
    f=3.4E38;
    printf("3.4E38     is %e and length is %d\n",(float)f,sizeof(f));
    printf("3.4E39     is %e\n",(float)3.4E39);
    printf("3.4E39 - 1 is %e\n",(float)(3.4E39-1));
    printf("3.4E38 - 1 is %e\n",(float)(3.4E38-1));
    printf("3.4E38 + 1 is %e\n",(float)(3.4E38+1));

    printf("\n\nInput a number between 0-255:");
    scanf("%d",&i);
    printf("you enter value is %d,it is char %c",i,i);

    for(i=0;i<20;i++){
        putchar(7);
    }
    printf("\n\aStart by the sudden sound,shouted:\"by the great Pumkia,what was that\"");

    printf("\n\nInput a float number:");
    scanf("%f",&f);
    printf("you enter value is %f,it is  %e",f,f);

    printf("\n\nInput your age:");
    scanf("%d",&i);
    printf("you age is %d years,it is %e seconds",i,i*3.156e10);


    printf("\n\nInput the water:");
    scanf("%d",&i);
    printf("water is %d g,it is %e element",i,i*950*3.0e23);

    printf("\n\nInput your age:");
    scanf("%d",&i);
    printf("you age is %d years,it is %f seconds",i,i*3.156e10);
}
