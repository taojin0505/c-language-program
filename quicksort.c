#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

static int MAX_STRING_LENGTH = 20;

void quickSortString(int,char []);
int randQuickSortString(char *dataArray[],int p,int r);
int randPartition(char *dataArray[],int p,int r);

int main(int argc,char *argv[]){
	char *fileName, dataType;
	int dataSize = 0;

	if(argc == 4){
		dataType = argv[1][0];
		dataSize = atoi(argv[2]);
		fileName = argv[3];
	}else
		printf("Usage:%s s|i|f n fileName\n",argv[0]);

	switch(dataType){
		case 's':
			quickSortString(dataSize,fileName);
			break;
		default:
			printf("Wrong input type :%c \n",dataType);
	}
	return 0;
}

void quickSortString(int dataSize,char fileName[]){
	char stringData[dataSize][MAX_STRING_LENGTH]; 
	char *stringDataPointer[dataSize]; 
	FILE *fp = fopen(fileName,"r");
	int i=0;
	long usednsec;
	struct timespec startTime,endTime;

	for(i=0;fgets(stringData[i],MAX_STRING_LENGTH,fp) != NULL;i++)
		printf("%s",stringData[i]);
		;
	for(i=0;i<dataSize;i++)
		stringDataPointer[i]=stringData[i];

	clock_gettime(CLOCK_REALTIME,&startTime);

	randQuickSortString(stringDataPointer,0,dataSize);

	clock_gettime(CLOCK_REALTIME,&endTime);
	usednsec = (endTime.tv_sec-startTime.tv_sec)*1000000000+endTime.tv_nsec-startTime.tv_nsec;
	printf("use time : %ld ns\n",usednsec);
	for(i=0;i<dataSize;i++)
		printf("%s",stringDataPointer[i]);
}

int randQuickSortString(char *dataArray[],int p,int r){
	int i =0;

	if(p<r){
		i = randPartition(dataArray,p,r);
		if(i==p)
			return 0;
		randQuickSortString(dataArray,p,i-1);
		randQuickSortString(dataArray,i,r);
	}
}

int randPartition(char *dataArray[],int p,int r){
	int randVal =0,k=0;
	char *mainVal,*tmpVal;
	int i=p-1,j=p;
	struct timespec time_ns;

	if(p==r)
		return p;
	clock_gettime(CLOCK_REALTIME,&time_ns);
	srand(time_ns.tv_nsec);
	randVal = p+rand()%(r-p);
	printf("p  %d  r  %d   %d\n",p,r,randVal);
	mainVal = dataArray[randVal];
	dataArray[randVal]=dataArray[r-1];
	dataArray[r-1]=mainVal;
	for(j=p;j<r-1;j++){
		if(strcmp(dataArray[j],mainVal) <= 0){
			i = i + 1;
			printf("i  %d  j  %d\n",i,j);
			tmpVal = dataArray[i];
			dataArray[i]=dataArray[j];
			dataArray[j] = tmpVal;
		}
	}
	randVal =i;
	for(k=p-1;k<r;k++)
		printf("%s",dataArray[k]);
	return i+1;
}
