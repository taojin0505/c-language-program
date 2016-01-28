#include<stdio.h>
#include<math.h>

void fellow(){
    printf("For he's a jolly good fellow!\n");
}

void nobodydeny(){
    printf("Which nothing can deny!\n");
}

void smaile(){
    printf("smile!");
}
void one_three(){
    printf("one\n");
}

void two(){
    printf("two\n");
}

void three(){
    printf("three\n");
}

int main(void){
    int i=0,j=0;
    int toes=0;

    printf("tony tao\n");
    printf("tony\n");
    printf("tao\n");
    printf("tony tao\n");
    printf("shanghai China\n");
    printf("my age is 28,and it is %d days\n",28*365);

    for(i=0;i<3;i++){
        fellow();
    }
    nobodydeny();

    toes=10;

    printf("toes is :%d,double toes is :%d,toes sqrt is %f\n",toes,2*toes,pow(toes,2));

    for(i=3;i>0;i--){
        for(j=0;j<i;j++){
            smaile();
        }
        printf("\n");
    }

    printf("Starting now:\n");
    one_three();
    two();
    three();
    printf("done\n");

    return 0;
    }
