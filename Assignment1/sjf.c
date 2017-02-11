#include "Main.h"
#include "sjf.h"

void sjf(Execution executionData, Processes processArray[]){

		
	printf("%i %s\n", executionData.processCount, "processes" );
	printf("%s\n", "Using Shortest Job First (Pre)");






	// //simple loop that will print all the processes recieved from Main.c
	// printf("%s\n", "from rr.c");
	//  int i;
	//  for( i = 0; i < executionData.processCount; i++ ){
	 
	//  	printf("%s, %i, %i\n", processArray[i].name, processArray[i].arivalTime, processArray[i].burstTime);
	 
	//  }



	 int i = 0;
	 int time = 0;
	 int haveArrived = 0;
	 int *haveArrivedPtr = &haveArrived;
	 char currentProcess[8];
	 Processes arrivedProcesses[executionData.processCount];


	 
	 while(time < executionData.runFor){
	 	//printf("%i\n", time);

	 	checkArrival(time, executionData, arrivedProcesses, processArray, haveArrivedPtr);

	 	sortByBurst(executionData, arrivedProcesses, haveArrived);

		passTimeUnitSJF(time, executionData, arrivedProcesses, haveArrived, currentProcess);

		 // printf("has arrived : %i\n",  haveArrived);
		 // for(i = 0; i < 5; i++){
		 // 	printf("burstTime: %i, %s\n", arrivedProcesses[i+1].burstTime, arrivedProcesses[i+1].name);

		 // }

	 	time++;
	 }

	 printf("Finished at time %i\n", time);

		 printf("has arrived : %i\n",  haveArrived);
		 for(i = 0; i < haveArrived; i++){
		 	printf("turnaround: %i, wait: %i, Name: %s\n", arrivedProcesses[i].turnaround, arrivedProcesses[i].wait, arrivedProcesses[i].name);

		 }

}


void passTimeUnitSJF( int time, Execution executionData, Processes arrivedProcesses[], int haveArrived, char* currentProcess){

		int i = 0;
		int j;
		while( arrivedProcesses[i].burstTime <= 0 && i < haveArrived){
			i++;
		}

		if(strcmp(arrivedProcesses[i].name, "end\n") == 0){
			printf("Time: %s\n", "IDLE");
			return;
		}

		if( strcmp(currentProcess, arrivedProcesses[i].name) == 0){
			printf("Time %i: %s selected (burst %i)\n", time, arrivedProcesses[i].name, arrivedProcesses[i].burstTime);
			strcpy(currentProcess, arrivedProcesses[i].name);

		}

		for(j = 0; j < haveArrived-1; j++){
			printf("j:  %i haveArrived: %i\n", j, haveArrived);
			if(strcmp(currentProcess, arrivedProcesses[j].name) != 0){
				arrivedProcesses[j].wait++;
			}
		}

		arrivedProcesses[i].turnaround++;
		arrivedProcesses[i].burstTime--;
		if(arrivedProcesses[i].burstTime <= 0){
			printf("Time %i: %s finished\n", time+1, arrivedProcesses[i].name);
		}
}




void checkArrival(int time, Execution executionData, Processes arrivedProcesses[], Processes processArray[], int* haveArrivedPtr){

	//check to see if a process has arrived
	int i = 0;
	for( i = 0; i < executionData.processCount; i++){
		if(time == processArray[i].arivalTime){
			printf("Time %i: %s arrived\n", time, processArray[i].name);
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