#include<stdio.h>
#include<strings.h>
#include<float.h>

#define pi 3.14159

int main(void){
    char fname[20],sname[20];
    int i;
    float f;
    double d;

    printf("Input your first name:");
    scanf("%s",fname);
    printf("Input your second name:");
    scanf("%s",sname);
    printf("Thanks,your name is:%s %s.\n",fname,sname);
    printf("your name is \"%s\"\n",sname);
    printf("your name is \"%20s\"\n",sname);
    printf("your name is \"%-20s\"\n",sname);
    printf("%s  %s\n",fname,sname);
    printf("%*d  %*d\n",strlen(fname),strlen(fname),strlen(sname),strlen(sname));
    printf("%-*d  %-*d\n",strlen(fname),strlen(fname),strlen(sname),strlen(sname));

    printf("Input your height in cm:");
    scanf("%f",&f);
    printf("your height is:%1.2f m\n",f/100);

    f=1.0/3.0;
    d=1.0/3.0;
    printf("%.4f\n",f);
    printf("%.12f\n",f);
    printf("%.16f\n",f);

    printf("%.4f\n",d);
    printf("%.12f\n",d);
    printf("%.16f\n",d);
    f=FLT_DIG;
    d=DBL_DIG;
    printf("%e  %e\n",f,d);
    printf("%f  %f\n",f,d);

    return 0;
}
