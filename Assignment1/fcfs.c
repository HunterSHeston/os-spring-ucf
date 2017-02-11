#include "Main.h"
#include "fcfs.h"


void fcfs( Execution executionData, Processes processArray[] ){

	FILE *fp;
	fp = fopen("processes.out", "w");
	if(fp == NULL){
		printf("File not opened1\n");
		exit(0);
	}

	fprintf(fp, "%i process\n", executionData.processCount);
	

	//printf("%i process\n", executionData.processCount);

	 //sort by arrival time
	 sortByArival(executionData, processArray);

	 int time = 0;
	 int selectedProcess = -1;
	 while(time <= executionData.runFor){

	 	selectedProcess = passTimeUnit( time, executionData, processArray, selectedProcess, fp);

	 	time++;
	 }	 
	 int i;
	 for(i = 0; i < executionData.processCount; i++){
	 	fprintf(fp, "%s wait %i turnaround %i\n", processArray[i].name, processArray[i].wait, processArray[i].turnaround);
	 	//printf("%s wait %i turnaround %i\n", processArray[i].name, processArray[i].wait, processArray[i].turnaround);
	 }

	 fclose(fp);

}

int passTimeUnit(int time, Execution executionData, Processes processArray[], int selectedProcess, FILE *fp){

	//check to see if a process has arrived
	int i = 0;
	for( i = 0; i < executionData.processCount; i++){
		if(time == processArray[i].arivalTime){
			fprintf(fp, "Time %i: %s arrived\n", time, processArray[i].name);
			//printf("Time %i: %s arrived\n", time, processArray[i].name);
		}
	}


	if( (selectedProcess == -1) || (processArray[selectedProcess].burstTime <= 0) ){

		for(i = 0; i < executionData.processCount; i++){
			if(processArray[i].burstTime > 0){
			
				if(selectedProcess != -1){
					fprintf(fp, "Time %i: %s finished\n", time, processArray[selectedProcess].name);
					//printf("Time %i: %s finished\n", time, processArray[selectedProcess].name);
					processArray[selectedProcess].turnaround = time - processArray[selectedProcess].arivalTime;
				}
				fprintf(fp, "Time %i: %s selected (burst %i)\n", time, processArray[i].name, processArray[i].burstTime);
				//printf("Time %i: %s selected (burst %i)\n", time, processArray[i].name, processArray[i].burstTime);
				processArray[i].wait = time - processArray[i].arivalTime;
				processArray[i].burstTime--;
				return i;
			}
		}
	}else{

		processArray[selectedProcess].burstTime--;
	}

	return selectedProcess;

}
	







void sortByArival(Execution executionData, Processes processArray[]){

	Processes temp;

	int i, j;
	for(i = 0; i < executionData.processCount; i++){
		for(j = 0; j < executionData.processCount; j++){

			if(processArray[i].arivalTime < processArray[j].arivalTime){

				temp = processArray[i];
				processArray[i] = processArray[j];
				processArray[j] = temp;
			}
		}
	}

}



