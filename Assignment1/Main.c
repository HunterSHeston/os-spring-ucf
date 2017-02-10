#include "Main.h"
#include "fcfs.h"
#include "rr.h"
#include "sjf.h"



void readData(Execution * exicutionData, Processes *processArray);

int main(void) {

	Processes processArray[128] = { {0} };
	Execution executionData = { 0 };

	readData(&executionData, processArray);
	

	Processes trimedProcesses[executionData.processCount];

	trimProcesses( executionData.processCount, processArray, trimedProcesses);

//	 fcfs( executionData, trimedProcesses);
	// rr( executionData, processArray);
	// sjf( executionData, processArray);


	printf("%s\n",executionData.algorithmType );
	if ( strcmp(executionData.algorithmType, "rr") == 0) {

		//call to start rr
		rr( executionData, trimedProcesses ); 

	}
	else if (strcmp(executionData.algorithmType, "fcfs") == 0) {

		fcfs( executionData, trimedProcesses ); //call to fsfc
	

	}
	else if (strcmp(executionData.algorithmType, "sjf") == 0) {

		sjf( executionData, trimedProcesses ); //replace with your function call

	}
	else {
		printf("Invalid algorithm %s\n", executionData.algorithmType);
	}

	 //int i;
	 //for( i = 0; i < executionData.processCount; i++ ){
	 //
	 //	printf("%s, %i, %i\n", processArray[i].name, processArray[i].arivalTime, processArray[i].burstTime);
	 //
	 //}

	return 0;
}


void readData(Execution * exicutionData, Processes *processArray) {

	FILE *fp;

	fp = fopen("set1_process.in", "r");

	if (fp == NULL) {  
		printf("%s", "File Not Found exiting....\n");
		exit(0);
	}

	char temp[128];
	char *token;

	fgets(temp, 128, fp);
	token = strtok(temp, " ");
	exicutionData->processCount = atoi(strtok(NULL, " "));
		
	fgets(temp, 128, fp);
	token = strtok(temp, " ");
	exicutionData->runFor = atoi(strtok(NULL, " "));

	fgets(temp, 128, fp);
	token = strtok(temp, " ");
	token = strtok(NULL, " ");
	exicutionData->algorithmType = malloc(sizeof(char) * strlen(token));
	strcpy(exicutionData->algorithmType, token);

	fgets(temp, 128, fp);
	if (strcmp(exicutionData->algorithmType, "rr") == 0) {
		
		token = strtok(temp, " ");
		exicutionData->quantum = atoi(strtok(NULL, " "));
	}
	else {
		exicutionData->quantum = 0;
	}



	int i = 0;
	while (feof(fp) == 0) {
		

		fgets(temp, 128, fp);
		token = strtok(temp, " ");
		 if(strcmp(token, "end\n") == 0){
		 	break;
		 }

		strtok(NULL, " ");
		token = strtok(NULL, " ");
		processArray[i].name = malloc(sizeof(char) * strlen(token));
		strcpy(processArray[i].name, token);
		strtok(NULL, " ");
		processArray[i].arivalTime = atoi(strtok(NULL, " "));
		strtok(NULL, " ");		
		processArray[i].burstTime = atoi(strtok(NULL, " "));

		i++;
	}

	fclose(fp);

}

void trimProcesses(int processCount, Processes processArray[], Processes trimedProcesses[]){


	int i = 0;
	for(i = 0; i < processCount; i++){
		trimedProcesses[i] = processArray[i];
	}

}