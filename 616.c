#include<stdio.h>
#include<stdlib.h>

double getdata1(int);
double getdata2(int);

double getdata1(int times){
    double dsum=0.0;

    for(int i=1;i<=times;i++){
        dsum+=1.0/i;
    }
    return dsum;
}

double getdata2(int times){
    double dsum=0.0;

    for(int i=1;i<=times;i++){
        if(i%2)
            dsum+=1.0/i;
        else
            dsum-=1.0/i;
    }
    return dsum;
}

void main(void){
    char charstr[27];
    char achar='a';
    int data=0,data1=0,data2=0;
    double ddata1=0.0,ddata2=0.0;
    long long lldata=0,lldata1=0;

    for(int i=0;i<26;i++){
        charstr[i]=achar+i;
    }
    charstr[26]='\0';
    printf("String %s array size is:%d\n",charstr,sizeof charstr);

    for(int i=1;i<=6;i++){
        for(int j=1;j<=i;j++)
            putchar('$');
        putchar('\n');
    }

    achar='F';
    for(int i=1;i<=achar-'A'+1;i++){
        for(int j=1;j<=i;j++)
            putchar(achar-j+1);
        putchar('\n');
    }

    printf("Please input a character between A and Z:");
    achar=getchar();
    for(int i=0;i<=achar-'A';i++){
        for(int j=0;j<=achar-'A'-i;j++)
            putchar(' ');
        for(int k=i;k>=(0-i);k--){
            putchar('A'+i-abs(k));
        }
        putchar('\n');
    }


    for(int i=77;i<128;i++){
        printf("%d and %d\n",i*i,i*i*i);
    }

    printf("20 times is %12.10f\n",getdata1(20));
    printf("100 times is %12.10f\n",getdata1(100));
    printf("500 times is %12.10f\n",getdata1(500));

    printf("20 times is %12.10f\n",getdata2(20));
    printf("100 times is %12.10f\n",getdata2(100));
    printf("500 times is %12.10f\n",getdata2(500));

    ddata1=1000000;
    ddata2=1000000;

    for(int i=1;;i++){
        ddata1+=100000;
        ddata2*=1.05;
        if(ddata2>ddata1){
            printf("year is %d,ddata1 is %20.10f,ddata2 is %20.10f\n",i,ddata1,ddata2);
            break;
        }
    }

    ddata1=1000000;
    for(int i=1;;i++){
        ddata1+=1000000*0.08;
        ddata1-=100000;
        printf("year is %d,ddata1 is %20.10f\n",i,ddata1);
        if(ddata1<100000){
            break;
        }
    }

}
