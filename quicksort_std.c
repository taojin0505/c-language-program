#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

static int MAX_STRING_LENGTH = 22;
static char *outFileName = "c.out";

void quickSortString(int,char []);
char *strdup1(char const *string);

int cmpstr(const void *a,const void *b){
	return strcmp(*(char **)a,*(char **)b);
}

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

char *strdup1(char const *string){
	char *new_string;

	new_string = malloc( (strlen( string)) * sizeof(char) );
	if( new_string != NULL)
		strcpy(new_string, string);
	return new_string;
};

void quickSortString(int dataSize,char fileName[]){
	char **stringData = (char **)malloc(dataSize * sizeof(char *));
	char tmpString[MAX_STRING_LENGTH]; 
	FILE *fp = fopen(fileName,"r");
	FILE *fpw = fopen(outFileName,"w");
	int i=0;
	long usednsec;
	struct timespec startTime,endTime;

	for(i=0;fgets(tmpString,MAX_STRING_LENGTH,fp) != NULL;i++){
		stringData[i] = strdup1(tmpString);
	//	printf("%d  %s",i+1,stringData[i]);
	}

	clock_gettime(CLOCK_REALTIME,&startTime);

	qsort(stringData,dataSize,sizeof(char *),cmpstr);

	clock_gettime(CLOCK_REALTIME,&endTime);
	usednsec = (endTime.tv_sec-startTime.tv_sec)*1000000000+endTime.tv_nsec-startTime.tv_nsec;
	printf("use time : %ld ns\n",usednsec);
	for(i=0;i<dataSize;i++){
	//	printf("%d  %s \n",i,stringData[i]);
		fputs(stringData[i],fpw);
		free(stringData[i]);
	}

	free(*stringData);
	if((i=fclose(fp))!=0)
		printf("close failed,err code %d",i);
	fclose(fpw);
}


