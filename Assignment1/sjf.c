#include "Main.h"
#include "sjf.h"

void sjf(Execution executionData, Processes processArray[]){

	FILE *fp;
	fp = fopen("processes.out", "w");
	if(fp == NULL){
		printf("File not opened1\n");
		exit(0);
	}

	fprintf(fp, "%i process\n", executionData.processCount);
	fprintf(fp, "Using Shortest Job First (Pre)\n\n" );

	 int i = 0;
	 int time = 0;
	 int haveArrived = 0;
	 int *haveArrivedPtr = &haveArrived;
	 char currentProcess[8];
	 Processes arrivedProcesses[executionData.processCount];
	 
	 while(time < executionData.runFor){
	 	checkArrival(time, executionData, arrivedProcesses, processArray, haveArrivedPtr, fp);
	 	sortByBurst(executionData, arrivedProcesses, haveArrived);
		passTimeUnitSJF(time, executionData, arrivedProcesses, haveArrived, currentProcess, fp);
		time++;
	 }

	 fprintf( fp,"Finished at time %i\n\n", time);
		
	 	
		 for(i = 0; i < haveArrived; i++){
		 	fprintf(fp, "%s wait %i turnaround %i\n", arrivedProcesses[i].name, arrivedProcesses[i].wait, arrivedProcesses[i].turnaround);

		 }


	fclose(fp);
}


void passTimeUnitSJF( int time, Execution executionData, Processes arrivedProcesses[], int haveArrived, char* currentProcess, FILE *fp){

		int i = 0;
		int j;
		while( arrivedProcesses[i].burstTime <= 0 && i < haveArrived ){
			i++;
		}
		
		if(i == haveArrived){
			i--;
		}
		
		
		if(strcmp(arrivedProcesses[i].name, "end\n") == 0){
			fprintf(fp, "Time: %s\n", "IDLE");
			return;
		}
		
		if( strcmp(currentProcess, arrivedProcesses[i].name) != 0){
			fprintf(fp, "Time %i: %s selected (burst %i)\n", time, arrivedProcesses[i].name, arrivedProcesses[i].burstTime);
			strcpy(currentProcess, arrivedProcesses[i].name);

		}

		for(j = 0; j < haveArrived-1; j++){
			if(strcmp(currentProcess, arrivedProcesses[j].name) != 0){
				arrivedProcesses[j].wait++;
			}
		}

		arrivedProcesses[i].turnaround++;
		arrivedProcesses[i].burstTime--;
		if(arrivedProcesses[i].burstTime <= 0){
			fprintf(fp, "Time %i: %s finished\n", time+1, arrivedProcesses[i].name);
		}
}




void checkArrival(int time, Execution executionData, Processes arrivedProcesses[], Processes processArray[], int* haveArrivedPtr, FILE *fp){

	//check to see if a process has arrived
	int i = 0;
	for( i = 0; i < executionData.processCount; i++){
		if(time == processArray[i].arivalTime){
			fprintf(fp, "Time %i: %s arrived\n", time, processArray[i].name);
			arrivedProcesses[*haveArrivedPtr] = processArray[i];
			(*haveArrivedPtr)++;
		}
	}
}

void sortByBurst(Execution executionData, Processes processArray[], int haveArrived){

	Processes temp;

	int i, j;
	for(i = 0; i < haveArrived; i++){
		for(j = 0; j < haveArrived; j++){

			if(processArray[i].burstTime < processArray[j].burstTime){

				temp = processArray[i];
				processArray[i] = processArray[j];
				processArray[j] = temp;
			}
		}
	}

}