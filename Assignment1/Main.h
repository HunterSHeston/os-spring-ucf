#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct PStruct{

	char* name;  			//name of a process
	int arivalTime; 		//time of arival
	int burstTime;			//burst time

} Processes;

typedef struct EStruct{

	int processCount;		//number of processes
	int runFor;				//time units to run
	char* algorithmType;	//type of algorith: rr | fsfc | sjf
	int quantum;			//time quantum 

} Execution;

#endif /*  Main.h */