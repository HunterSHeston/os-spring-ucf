#ifndef SJF_H
#define SJF_H



void sjf(Execution executionData, Processes processArray[]);
void sortByBurst(Execution executionData, Processes processArray[], int haveArrived);
void passTimeUnitSJF( int time, Execution executionData, Processes arrivedProcesses[], int haveArrived, char* currentProcess, FILE *fp);
void checkArrival(int time, Execution executionData, Processes arrivedProcesses[], Processes processArray[], int* haveArrived, FILE *fp);

#endif 