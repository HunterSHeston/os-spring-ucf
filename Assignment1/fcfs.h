
#ifndef FCFS_H
#define FCFS_H


void fcfs( Execution executionData, Processes processArray[] );
void sortByArival(Execution executionData, Processes processArray[]);
int passTimeUnit(int time, Execution executionData, Processes processArray[], int selectedProcess, FILE *fp);

#endif