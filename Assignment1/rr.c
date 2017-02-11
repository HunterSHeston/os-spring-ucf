#include "Main.h"
#include "rr.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct aTime{
    int arrival;
    int index;
    int sorted;
    int burst;
    int finished;
    int timeFinished;
    int wait;
}aTime;

aTime* minArrivalTime( Execution , Processes[]);
void checkArrive(Processes[], int,int,FILE*);

void rr(Execution executionData, Processes processArray[]){
    FILE* output = fopen("process.out" ,"w");
    int i = 0,j,k,m,w;
    int idle = 1;
    aTime* info;
    info = minArrivalTime(executionData, processArray);
    fprintf(output, "%d processes\nUsing Round-Robin\nQuantum %d\n\n", executionData.processCount, executionData.quantum);

    while ( i < executionData.runFor){
	idle = 1;

        for(k = 0; k < executionData.processCount;k++){


            for(j = 0; j < executionData.quantum; j++){
		checkArrive(processArray,i, executionData.processCount,output);

                if(j == 0 && info[k].burst > 0 && info[k].arrival <= i){
                    fprintf(output,"Time %d: %s selected (burst %d)\n", i, processArray[info[k].index].name, info[k].burst);
                }


                if(info[k].burst > 0 && info[k].arrival <= i){
                    info[k].burst--;
                    if(info[k].burst == 0){
                        info[k].finished = 1;
                        info[k].timeFinished = i;
                    }
                    for(w = 0; w < executionData.processCount; w++){
                        if(w != k && !info[w].finished && info[w].arrival < i){
                            info[w].wait++;
                        }
                    }
                    i++;
		    idle = 0;
                    if(i >= executionData.runFor){
                        break;
                    }
                }



                else if(info[k].arrival <= i){
                    int modIndex;

                    for(m = 1; m < executionData.processCount; m++){
                        modIndex = (k+m)%executionData.processCount;
                        if(info[modIndex].finished == 0 && info[modIndex].arrival <= i){
                            fprintf(output, "Time %d: %s finished\n", i, processArray[info[k].index].name);
                            fprintf(output,"Time %d: %s selected (burst %d)\n", i, processArray[info[modIndex].index].name,
										 info[modIndex].burst);
				info[modIndex].burst--;
			    if(info[modIndex].burst <= 0){
				fprintf(output, "Time %d: %s finished\n", i+1, processArray[info[modIndex].index].name);
				info[modIndex].finished = 1;
				info[modIndex].timeFinished = i;
			    }
                            for(w = 0; w < executionData.processCount; w++){
                                if(w != k && !info[w].finished){
                                    info[w].wait++;
                                }
                            }
				i++;
			    
                            idle = 0;
                            break;
                        }
                    }
                   
                    }
                }
             if(idle==1){
                        fprintf(output, "Time %d: IDLE\n", i);
			i++;
            }
            if(i >= executionData.runFor){
                break;
            }
        }

    }
	
    if(i == executionData.runFor){
        //COMPLETED RUNTIME!
        fprintf(output,"Finished at time %d\n\n", i);

	for(j = 0; j < executionData.processCount; j++){
		for(k = 0; k < executionData.processCount; k++){
		    if(info[k].index == j){
				if(info[k].burst > 0){
				//info[k] HAS NOT COMPLETED!
				fprintf(output, "%s did not finish\n", processArray[info[k].index].name);
			    }
			    else{
				fprintf(output, "%s wait %d turnaround %d\n", processArray[info[k].index].name, info[k].wait, (info[k].timeFinished+1-info[k].arrival));
			    }
			}
		}
	}

    }

}

//Sorts processes by arrival time with a secondary of burst time and
//returns the sorted array with the indices (Indexes is not the proper spelling), quantum, arrival time, and burst stored in an array
aTime* minArrivalTime(Execution executionData, Processes processArray[]){
    int i,j;
    aTime info[128];
    int numProc = executionData.processCount;


    for(i = 0; i < numProc; i++){
	info[i].index = 0;
    info[i].arrival = processArray[0].arivalTime;
    info[i].finished = 0;
    info[i].burst = processArray[0].burstTime;
    info[i].sorted = 0;
    info[i].wait = 1;	

        for(j = 0; j < numProc; j++){
            //Sort by arrivalTime, uses sorted as flag
            if((processArray[j].arivalTime < info[i].arrival) && (i != 0) && processArray[j].arivalTime > info[i-1].arrival){
                info[i].arrival = processArray[j].arivalTime;
                info[i].index = j;
                info[i].sorted = 1;
                info[i].finished = 0;
                info[i].burst = processArray[j].burstTime;  
                info[i].wait = 0;
            }
	    else if (processArray[j].arivalTime < info[i].arrival && i == 0){
                info[i].arrival = processArray[j].arivalTime;
                info[i].index = j;
                info[i].sorted = 1;
                info[i].finished = 0;
                info[i].burst = processArray[j].burstTime; 
                info[i].wait = 0;



		}
            //If arrivalTimes are equal, then sort by burst
            else if((processArray[j].arivalTime == info[i].arrival) && (info[i].sorted == 0) &&
               (processArray[j].burstTime < info[i].burst)){

                info[i].arrival = processArray[j].arivalTime;
                info[i].index = j;
                info[i].sorted = 1;
                info[i].finished = 0;
                info[i].burst = processArray[j].burstTime;             
		info[i].wait = 0;
            }
        }
    }
    return info;
}

void checkArrive(Processes processArray[], int time, int length, FILE* output){
	int k;	
	for(k = 0; k < length; k++){
		if(processArray[k].arivalTime == time){
			fprintf(output,"Time %d: %s arrived\n", time, processArray[k].name);		
		}
	}
}

