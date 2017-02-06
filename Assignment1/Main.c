#include <stdio.h>
#include <stdlib.h>


typedef struct {

	const char* name;
	int arivalTime;
	int burstTime;

} Processes;

typedef struct {

	int processCount;
	int runFor;
	char* algorithmType;
	int quantum;

} Execution;


void readData(Execution * exicutionData, Processes *processArray);

int main(void) {

	Processes processArray[128] = { {0} };
	Execution exicutionData = { 0 };

	readData(&exicutionData, processArray);
	
	if ( strcmp(exicutionData.algorithmType, "rr") == 0) {
		
	}
	else if (strcmp(exicutionData.algorithmType, "fsfc") == 0) {

	}
	else if (strcmp(exicutionData.algorithmType, "sjf") == 0) {

	}
	else {
		printf("Invalid algorithm %s", exicutionData.algorithmType);
	}


	return 0;
}


void readData(Execution * exicutionData, Processes *processArray) {

	FILE *fp;

	fp = fopen("set2_process.in", "r");

	if (fp == NULL) {  
		printf("%s", "File Not Found exiting....\n");
		system("exit");
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
	
		fscanf(fp, "%s %s %s %s %i %s %i", &temp, &temp, &name, &temp, &processArray[i].arivalTime, &temp, &processArray[i].burstTime);
		processArray[i].name = malloc(sizeof(char) * strlen(name));
		strcpy(processArray[i].name, name);

		i++;
	}

	fclose(fp);

}