#define _GNU_SOURCE
#include "counter.h"

int main()
{
	int rc;
	pthread_t t1, t2;
	
	pthread_barrier_init(&bar, NULL, NUM_THREADS);		//Barrier is initialized with 2 threads as the limit
	thread_core_set();					//Threads are assigned to core

	fp = fopen("actual_output.txt", "w+");

	rc = pthread_create(&t1, (pthread_attr_t*)&(rt_sched_attr[0]), func_1, NULL);	//Thread 1 initialized with affinity set to cpu-0
	if(rc)
	{
		handle_error("Error in creating thread 1")
	}
	
	rc = pthread_create(&t2, (pthread_attr_t*)&(rt_sched_attr[1]), func_2, NULL);	//Thread 1 initialized with affinity set to cpu-0
	if(rc)
	{
		handle_error("Error in creating thread 2")
	}

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	fclose(fp);
	printf("\n");

	return 0;
}


/**
 * @brief CPU affinity of thread is obtained for user-viewing purposes. Thread waits till barrier is hit by 
 * both threads, ensuring both threads start incrementing counter at same time.
 * Two for loops are run, for a total of 5000 iterations per thread
 *
 * @param threadp empty void pointer supplied as template
 *
 * @return 
 */
void* func_1(void* threadp)
{
	int cpucore=sched_getcpu();		//Get CPU affinity and store in cpucore
	cpu_set_t cpuset;

	CPU_ZERO(&cpuset);
	pthread_t thread = pthread_self();
	pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset);	//Verify that affinity of thread 1 for cpu-0 is set

	printf("Thread idx=1 ran on core=%d, affinity contained:", cpucore);
	for(int i=0; i<2; i++)
		if(CPU_ISSET(i, &cpuset))  printf(" CPU-%d ", i);
	printf("\n");

	pthread_barrier_wait(&bar);		//Wait till both threads have hit barrier, then start incrementing count
//	printf("In thread 1\n");
	for(int j=0; j<5; j++)
	{
		for(int i=0; i<1000; i++)
		{
//			printf("%d\n", count);
//			count++;
			count = counter();
		}
	}
	printf("Last of T1: %d\n", count);	//print final value of variable as seen by thread1 when done
	fprintf(fp, "%d\n", count);
	pthread_exit(NULL);
}


/**
 * @brief CPU affinity of thread is obtained for user-viewing purposes. Thread waits till barrier is hit by 
 * both threads, ensuring both threads start incrementing counter at same time.
 * Two for loops are run, for a total of 5000 iterations per thread
 *
 * @param threadp empty void pointer supplied as template
 *
 * @return 
 */
void* func_2(void* threadp)
{
	int cpucore=sched_getcpu();		//Get CPU affinity and store in cpucore
	cpu_set_t cpuset;
	
	CPU_ZERO(&cpuset);
	pthread_t thread = pthread_self();
	pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset);	//Verify that affinity of thread 1 for cpu-0 is set

	printf("Thread idx=2 ran on core=%d, affinity contained:", cpucore);
	for(int i=0; i<2; i++)
		if(CPU_ISSET(i, &cpuset))  printf(" CPU-%d ", i);
	printf("\n");
	
	pthread_barrier_wait(&bar);		//Wait till both threads have hit barrier, then start incrementing count
//	printf("In thread 2\n");
	for(int j=0; j<5; j++)
	{
		for(int i=0; i<1000; i++)
		{
//			printf("%d\n", count);
//			count++;
			count = counter();
		}
	}
	printf("Last of T2: %d\n", count);		//print final value of variable as seen by thread1 when done
	fprintf(fp, "%d\n", count);
	pthread_exit(NULL);
}


/**
 * @brief Assigns respective cores to threads, by use of cpu_set and bit manipulation
 */
void thread_core_set(void)
{
	int rc;
//	cpu_set_t allcpuset;
	cpu_set_t threadcpu;
	
	CPU_ZERO(&threadcpu);
	CPU_SET(0, &threadcpu);
	printf("Launching thread 1\n");
	rc=pthread_attr_init(&rt_sched_attr[0]);
	if(rc)
	{
		handle_error("Unable to initialize thread1 attributes")
	}
	rc=pthread_attr_setaffinity_np(&rt_sched_attr[0], sizeof(cpu_set_t), &threadcpu);
	if(rc)
	{
		handle_error("Unable to set thread1 cpu affinity")
	}


	CPU_ZERO(&threadcpu);
	CPU_SET(1, &threadcpu);
	printf("Launching thread 2\n");
	rc=pthread_attr_init(&rt_sched_attr[1]);
	if(rc)
	{
		handle_error("Unable to initialize thread2 attributes")
	}
	rc=pthread_attr_setaffinity_np(&rt_sched_attr[1], sizeof(cpu_set_t), &threadcpu);
	if(rc)
	{
		handle_error("Unable to set thread2 cpu affinity")
	}
}


/**
 * @brief function call to increment global variable count
 * If count is kept static to function counter(), latency in returning value of count to calling thread 
 * deteriorates performance even more than from what is observed.
 */
int counter()
{
	static int count;
	count++;
	return count;
}
