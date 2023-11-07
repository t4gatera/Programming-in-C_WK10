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
int num_args = argc - 1;
pthread_t tid[num_args];

for(int i = 0; i<num_args; i++){
 long long limit = atoll(argv[i+1]);
 pthread_create(&tid[i], NULL, sum_run, &limit);
}

//wait until the thread is doing its work
for(int i=0; i< num_args; i++){
 pthread_join(tid[i], NULL);
}
printf("The sum is %lld\n", sum);

}
