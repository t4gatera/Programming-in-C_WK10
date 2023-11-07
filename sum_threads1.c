#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

long long sum =0; 
void *sum_run (void *arg){
 long long *limit_ptr = (long long *) arg;
 int limit = *limit_ptr;
 for(int i=0; i<=limit; i++){
 sum += i;
 }
 pthread_exit(0);
}

int main(int argc, char **argv){

long long limit = atoll(argv[1]);
pthread_t tid;

pthread_create(&tid, NULL, sum_run, &limit);

//wait until the thread is doing its work
pthread_join(tid, NULL);
printf("The sum is %lld\n", sum);

}
