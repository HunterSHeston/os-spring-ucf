#ifndef SJF_H
#define SJF_H



void sjf(Execution executionData, Processes processArray[]);
void sortByBurst(Execution executionData, Processes processArray[]);
int passTimeUnitSJF( int time, Execution executionData, Processes processArray[], int selectedProcess );
void checkArrival(int time, Execution executionData, Processes processArray[]);

#endif 