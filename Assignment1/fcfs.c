#include "Main.h"
#include "fcfs.h"


void fcfs( Execution executionData, Processes processArray[] ){










	//simple loop that will print all the processes recieved from Main.c
	printf("%s\n", "from fcfs.c");
	 int i;
	 for( i = 0; i < executionData.processCount; i++ ){
	 
	 	printf("%s, %i, %i\n", processArray[i].name, processArray[i].arivalTime, processArray[i].burstTime);
	 
	 }

	 //sort by arrival time
	 sortByArival(executionData, processArray);

	 int time = 0;
	 int selectedProcess = -1;
	 while(time <= executionData.runFor){

	 	selectedProcess = passTimeUnit( time, executionData, processArray, selectedProcess);

	 	printf("%i\n", time);
	 	time++;
	 }	 

	 for(i = 0; i < executionData.processCount; i++){

	 	printf("%s wait %i turnaround %i\n", processArray[i].name, processArray[i].wait, processArray[i].turnaround);
	 }

}

int passTimeUnit(int time, Execution executionData, Processes processArray[], int selectedProcess){

	//check to see if a process has arrived
	int i = 0;
	for( i = 0; i < executionData.processCount; i++){
		if(time == processArray[i].arivalTime){
			printf("Time %i: %s arrived\n", time, processArray[i].name);
		}
	}


	if( (selectedProcess == -1) || (processArray[selectedProcess].burstTime <= 0) ){

		for(i = 0; i < executionData.processCount; i++){
			if(processArray[i].burstTime > 0){
			
				if(selectedProcess != -1){
					printf("Time %i: %s finished\n", time, processArray[selectedProcess].name);
					processArray[selectedProcess].turnaround = time - processArray[selectedProcess].arivalTime;
				}

				printf("Time %i: %s selected (burst %i)\n", time, processArray[i].name, processArray[i].burstTime);
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



// void runfcfs( Execution executionData, processes processArray[]){


// 	int time = 0;
// 	processes arived = NULL;

// 	while(time < executionData.runFor){

// 		arived = hasArived( time, executionData.processCount, processArray );
		
// 		if(arived != NULL){
// 			printf("Time %i: %s arived\n", time, arived.name);
// 		}



// 	}


// }

// processes hasArived( int time, int processCount, processes processArray[] ){

// 	int i;
// 	for(i = 0; i < processCount; i++){

// 	}

// }