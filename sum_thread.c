#include<stdio.h>
#include<stdlib.h>

void main(int argc, char **argv){
 long long value = atoll(argv[1]);
 long long sum=0;
 for (long long count = 0; count<=value; count++){
  sum +=count;
 }
 printf("The sum is %lld \n", sum);
}
