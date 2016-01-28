#include<stdio.h>

#define MINUTESOFHOUR 60
#define DAYSOFWEEK 7
#define ZEROTEMPERATURE 273.16
#define CELS 32.0

const int minutesofhour=60;
const double per=1.8;

int addenup(int);
double temperature(double);

int addemup(int num){
    for(int i=0;i<20;i++){
        num+=num;
        printf("You will earn %d$ in day %d\n",num,i+1);
    }
    return num;
}

double temperature(double temp){
    printf("the temperature is %.2f\n",temp);
    printf("the temperature is %.2f Celsius\n",per*temp+CELS);
    printf("the temperature is %.2f\n",temp+ZEROTEMPERATURE);
    return temp+ZEROTEMPERATURE;
}
void main(viod){

    int minutes=0,i=0,days=1;
    double tempe=0.0;

    printf("please into the minutes:");
    for(scanf("%d",&minutes);minutes>=0;printf("please into the minutes:"),scanf("%d",&minutes)){
        printf("You input %d hour and %d minutes\n",(int)minutes/MINUTESOFHOUR,minutes%minutesofhour);
    }


    printf("Please input a integer:");
    scanf("%d",&i);
    printf("date delimited by TAB\n");
    for(int j=i;j<i+10;j++){
        printf("%d\t",j);
    }
    printf("\ndate delimited by SPACE\n");
    for(int j=i;j<i+10;j++){
        printf("%d%c",j,32);
    }
    printf("\ndate delimited by CR\n");
    for(int j=i;j<i+10;j++){
        printf("%d\r",j);
    }
    printf("\ndate delimited by LF\n");
    for(int j=i;j<i+10;j++){
        printf("%d\n",j);
    }

    printf("Please input a day:");
    scanf("%d",&days);
    while(days>0){
        printf("You input %d week and %d day\n",(int)days/DAYSOFWEEK,days%DAYSOFWEEK);
        printf("Please input a day:");
        scanf("%d",&days);
    }

    printf("Please input you earned a day:");
    scanf("%d",&i);
    addemup(i);

    printf("Please input the temperature:");
    scanf("%lf",&tempe);
    printf("%la\n",tempe);
    temperature(tempe);
}
