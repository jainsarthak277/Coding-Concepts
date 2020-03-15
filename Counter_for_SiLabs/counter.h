#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

#define NUM_THREADS		(2)
#define handle_error(msg)	\
				{\
					printf(msg);\
				 	exit(1);\
				}

int count = 0;
FILE* fp;

pthread_barrier_t bar;
pthread_attr_t rt_sched_attr[NUM_THREADS];

int counter(void);
void* func_1(void*); 
void* func_2(void*); 
void thread_core_set(void);
