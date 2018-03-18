#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

static int MAX_STRING_LENGTH = 20;

void quickSortString(int,char []);
int randQuickSortString(char *[],int ,int);

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
	FILE *fp = fopen(fileName,"r");
	int i=0;
	struct timespec startTime,endTime;

	for(i=0;fgets(stringData[i],MAX_STRING_LENGTH,fp) != NULL;i++){
		printf("%s",stringData[i-1]);
	}
	clock_gettime(CLOCK_REALTIME,&startTime);
	printf("start time : %d \n",startTime.tv_nsec);

	randQuickSortString(&stringData,0,dataSize);

	clock_gettime(CLOCK_REALTIME,&endTime);
	printf("end time : %d \n",endTime.tv_nsec);
	for(i=0;i<MAX_STRING_LENGTH;i++){
		printf("%s",stringData[i-1]);
	}
}

int randQuickSortString(char *dataArray[],int p,int r){
	int i =0;

	i = randPartition(dataArray,p,r);
	randQuickSortString(dataArray,p,i-1);
	randQuickSortString(dataArray,i,r);
}

int randPartition(char *dataArray[],int p,int r){
	int randVal =0;
	char *mainVal,tmpVal;
	int i=p-1,j=p;

	randVal = p+rand()%(r-p);
	mainVal = dataArray[randVal];
	for(j=p;j<r;j++){
		if(strcmp(dataArray[j],mainVal) <= 0){
			i = i + 1;
			tmpVal = dataArray[i];
			dataArray[i]=dataArray[j];
			dataArray[j] = tmpVal;
		}
	}
	dataArray[i+1]=mainVal;
	return i+1;
}
