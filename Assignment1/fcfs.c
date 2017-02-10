#include "Main.h"
#include "fcfs.h"


void fcfs( Execution executionData, Processes processArray[] ){










	//simple loop that will print all the processes recieved from Main.c
	printf("%s\n", "from fcfs.c");
	 int i;
	 for( i = 0; i < executionData.processCount; i++ ){
	 
	 	printf("%s, %i, %i\n", processArray[i].name, processArray[i].arivalTime, processArray[i].burstTime);
	 
	 }

	 printf("%s\n", "ksjdfhakjhd");
	 sortByArival(executionData, processArray);

	 for( i = 0; i < executionData.processCount; i++ ){
	 
	 	printf("%s, %i, %i\n", processArray[i].name, processArray[i].arivalTime, processArray[i].burstTime);
	 
	 }


	 
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