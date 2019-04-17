#include <stdio.h>
int main()
{


    char local_19[4] = {0x4, 0x3, 0x2, 0x1 }; //67305985
    int local_15 = 0;
    char local_1b[2] = {0x98, 0x44} //38980

    rotate(local_19, 4);
    xor(&local_19, 4, &local_1b, 2);
    add(&local_19, 4, &local_1b, 2);
    xor(&local_19, 4, &local_1b, 2);
    rotate(&local_19, 4);
    printf("Final: %s\n", local_19);
}

void rotate(int param_1, size_t param_2)
{   int i = 0;
    //void *pvVar1; --> memcopy??? 
    while(i < param_2) {
       int *ptr[i] = param_1[param_2 + i -1]; 
       i +=1;
    }

    int j = 0;
    while(j < param_2){
        param_1[j] = *ptr[j];
        j +=1;
    }
    return;
}


void xor(int param_1,uint param_2,int param_3,uint param_4)
{
   int i = 0;
   while(i<param_2) {

       param_1[i] = param_1[i]^param_3(i%param_4);
       i +=1;
   }

}


void add(int param_1,uint param_2,int param_3,uint param_4) 
{
    int i = 0;

    while(i <param_2) {
       param_1[i] = param_1[i] + (i%param_4);
       i +=1;
    }
    return;
}
