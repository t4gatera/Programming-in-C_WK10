#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct sum_run_struct{
 int limit;
 long long answer;
};
 
void *sum_run (void *arg){
 struct sum_run_struct *arg_str = (struct sum_run_struct*) arg;
 long long sum =0;
 for(int i=0; i<=arg_str->limit; i++){
 sum += i;
 }
 arg_str->answer = sum;
 pthread_exit(0);
}

int main(int argc, char **argv){

int num_args = argc - 1;
struct sum_run_struct args[num_args];
pthread_t tid[num_args];

for(int i = 0; i<num_args; i++){
 args[i].limit = atoll(argv[i+1]);
 pthread_create(&tid[i], NULL, sum_run, &args[i]);
}

//wait until the thread is doing its work
for(int i=0; i< num_args; i++){
 pthread_join(tid[i], NULL);
}

for(int i=0; i<num_args; i++){
 printf("The sum is: %lld\n", args[i].answer);
}

}
