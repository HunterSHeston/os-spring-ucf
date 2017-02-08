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
}

char* minArrivalTime( Execution* , Processes* , aTime* );

void rr(Execution *executionData, Processes *processArray){
    FILE* output = fopen("process.out" ,"w");
    int i = 0,j,k,m,w;
    int idle = 1;
    aTime* info;

    fprintf(output, "%d processes\nUsing Round-Robin\nQuantum %d\n" executionData.processCount, executionData.quantum);

    while ( i < executionData.runFor){

        for(k = 0; k < executionData.processCount;k++){


            for(j = 0; j < executionData.quantum; j++){


                if(j == 0){
                    fprintf(output,"Time %d: %s selected(burst %d)\n", i, processArray[info[k].index].name, info[k].burst);
                }


                if(info[k].burst > 0){
                    info[k].burst--;
                    if(info[k].burst == 0){
                        info[k].finished = 1;
                        info[k].timeFinished = i;
                    }
                    for(w = 0; w < executionData.processCount; w++){
                        if(w != k && !info[w].finished){
                            info[w].wait++;
                        }
                    }
                    i++;

                    if(i == executionData.runFor){
                        break;
                    }
                }



                else{
                    int modIndex;

                    for(m = 1; m < executionData.processCount; m++){
                        modIndex = (k+m)%executionData.processCount;
                        if(!info[modIndex].finished){
                            fprintf(output, "Time %d: %s finished\n", i, processArray[info[k].index].name);
                            fprintf(output,"Time %d: %s selected(burst %d)\n", i, processArray[info[modIndex].index].name, info[modIndex].burst);
                            info[modIndex].burst--;

                            for(w = 0; w < executionData.processCount; w++){
                                if(w != k && !info[w].finished){
                                    info[w].wait++;
                                }
                            }

                            idle = 0;
                            break;
                        }
                    }
                    if(idle){
                        fprintf(output, "Time %d: Idle\n", i);
                    }
                }
            }
            if(i == executionData.runFor){
                break;
            }
        }


    }
    if(i == executionData.runFor){
        //COMPLETED RUNTIME!
        fprintf(output,"Finished at time %d\n", i);

        for(k = 0; k < executionData.processCount; k++){
            if(!info[k].finshed){
                //info[k] HAS NOT COMPLETED!
                fprintf(output, "%s did not finish\n", processArray[info[k].index].name);
            }
            else{
                fprintf(output, "%s wait %d turnaround %d", processArray[info[k].index].name, info[k].wait, info[k].timeFinished);
            }
        }
    }

}

//Sorts processes by arrival time with a secondary of burst time and
//returns the sorted array with the indices (Indexes is not the proper spelling), quantum, arrival time, and burst stored in an array
char* minArrivalTime(Execution *executionData, Processes *processArray, aTime * info){
    int i,j;

    info[0].index = 0;
    info[0].arrival = processArray[0].arrivalTime;

    for(i = 0; i < executionData.processCount; i++){
        for(j = 1; j < executionData.processCount; j++){

            //Sort by arrivalTime, uses sorted as flag
            if((processArray[j].arrivalTime < info[i].arrival) && (info[i].sorted == 0)){

                info[i].arrival = processArray[j].arrivalTime;
                info[i].index = j;
                info[i].sorted = 1;
                info[i].finished = 0;
                info[i].burst = processArray[j].burst;
                info[i].wait = 0;
            }
            //If arrivalTimes are equal, then sort by burst
            if((processArray[j].arrivalTime == info[i].arrival) && (info[i].sorted == 0) &&
               (processArray[j].burst < info[i].burst)){

                info[i].arrival = processArray[j].arrivalTime;
                info[i].index = j;
                info[i].sorted = 1;
                info[i].finished = 0;
                info[i].burst = processArray[j].burst;
                info[i].wait = 0;
            }
        }
    }

    return info;
}
