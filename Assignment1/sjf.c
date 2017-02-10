#include "Main.h"
#include "sjf.h"

void sjf(Execution executionData, Processes processArray[]){

		








	//simple loop that will print all the processes recieved from Main.c
	printf("%s\n", "from rr.c");
	 int i;
	 for( i = 0; i < executionData.processCount; i++ ){
	 
	 	printf("%s, %i, %i\n", processArray[i].name, processArray[i].arivalTime, processArray[i].burstTime);
	 
	 }


	 int time = 0;
	 int selectedProcess = -1;
	 while(time <= executionData.runFor){

	 	sortByBurst(executionData, processArray);

	 	selectedProcess = passTimeUnitSJF(time, executionData, processArray, selectedProcess);

	 	printf("%i\n", time);
	 	time++;
	 }


}


int passTimeUnitSJF( int time, Execution executionData, Processes processArray[], int selectedProcess ){

	checkArrival(time, executionData, processArray);

	if(selectedProcess == -1){

	}

}











void checkArrival(int time, Execution executionData, Processes processArray[]){

	//check to see if a process has arrived
	int i = 0;
	for( i = 0; i < executionData.processCount; i++){
		if(time == processArray[i].arivalTime){
			printf("Time %i: %s arrived\n", time, processArray[i].name);
		}
	}

}









	














void sortByBurst(Execution executionData, Processes processArray[]){

	Processes temp;

	int i, j;
	for(i = 0; i < executionData.processCount; i++){
		for(j = 0; j < executionData.processCount; j++){

			if(processArray[i].burstTime < processArray[j].burstTime){

				temp = processArray[i];
				processArray[i] = processArray[j];
				processArray[j] = temp;
			}
		}
	}

}