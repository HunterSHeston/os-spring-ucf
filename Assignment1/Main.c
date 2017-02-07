#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {

	char* name;  			//name of a process
	int arivalTime; 		//time of arival
	int burstTime;			//burst time

} Processes;

typedef struct {

	int processCount;		//number of processes
	int runFor;				//time units to run
	char* algorithmType;	//type of algorith: rr | fsfc | sjf
	int quantum;			//time quantum 

} Execution;


void readData(Execution * exicutionData, Processes *processArray);

int main(void) {

	Processes processArray[128] = { {0} };
	Execution executionData = { 0 };

	readData(&executionData, processArray);
	
	if ( strcmp(executionData.algorithmType, "rr") == 0) {

		//roundRobin( executionData, processArray ); replace with your function call

	}
	else if (strcmp(executionData.algorithmType, "fsfc") == 0) {

		//fsfc( executionData, processArray ); replace with your function call

	}
	else if (strcmp(executionData.algorithmType, "sjf") == 0) {

		//shortestJobFirst( executionData, processArray ); replace with your function call

	}
	else {
		printf("Invalid algorithm %s\n", executionData.algorithmType);
	}

	//int i;
	// for( i = 0; i < executionData.processCount; i++ ){

	// 	printf("%s, %i, %i\n", processArray[i].name, processArray[i].arivalTime, processArray[i].burstTime);

	// }

	return 0;
}


void readData(Execution * exicutionData, Processes *processArray) {

	FILE *fp;

	fp = fopen("set2_process.in", "r");

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


	if (strcmp(exicutionData->algorithmType, "rr") == 0) {
		fgets(temp, 128, fp);
		token = strtok(temp, " ");
		exicutionData->quantum = atoi(strtok(NULL, " "));
	}
	else {
		exicutionData->quantum = 0;
	}

	int i = 0;
	char name[8];

	while (feof(fp) == 0) {
		

		fgets(temp, 128, fp);
		
		printf("%i, %i\n", sizeof(strtok(temp, " ")), sizeof("end"));
		
		// if(strcmp(strtok(temp, " "), "end") == 0){
		// 	break;
		// }

		printf("%s\n", strtok(temp, " "));

		strtok(NULL, " ");
		token = strtok(NULL, " ");
		printf("|%s|\n", token);
		processArray[i].name = malloc(sizeof(char) * strlen(token));
		strcpy(processArray[i].name, token);
		strtok(NULL, " ");
		processArray[i].arivalTime = atoi(strtok(NULL, " "));
		strtok(NULL, " ");		
		processArray[i].burstTime = atoi(strtok(NULL, " "));


		i++;



	/*
		fscanf(fp, "%s %s %s %s %i %s %i", &temp, &temp, &name, &temp, &processArray[i].arivalTime, &temp, &processArray[i].burstTime);
		processArray[i].name = malloc(sizeof(char) * strlen(name));
		strcpy(processArray[i].name, name);

		i++;
	*/
	}

	fclose(fp);

}