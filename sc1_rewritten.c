#include <stdio.h>

void rotate(char* param_1, int param_2)
{   int i = 0;
    //void *pvVar1; --> memcopy??? 
    char temp[param_2];
    while(i < param_2) {
      temp[i] = param_1[param_2 - i -1]; 
       i +=1;
    }

    int j = 0;
    while(j <= param_2){
        param_1[j] = temp[j];
        j +=1;
    }
    return;
}


void xor(char* param_1,unsigned int param_2,char* param_3,unsigned int param_4)
{
   int i = 0;
   while(i<param_2) {

       param_1[i] = param_1[i]^(param_3[i%param_4]);
       i +=1;
   }

}


void add(char* param_1,unsigned int param_2, char* param_3, unsigned int param_4) 
{
    int i = 0;

    while(i <param_2) {
       param_1[i] = param_1[i] + param_3[i%param_4];
       i +=1;
    }
    return;
}

int main()
{


    char local_19[4] = {0x4, 0x3, 0x2, 0x1 }; //67305985
    int local_15 = 0;
    char local_1b[2] = {0x98, 0x44}; //38980
    printf("Start: %s\n", local_19);
    rotate(local_19, 4);
    xor(&local_19, 4, &local_1b, 2);
    add(&local_19, 4, &local_1b, 2);
    xor(&local_19, 4, &local_1b, 2);
    rotate(&local_19, 4);

    printf("End: %s\n", local_19);
}



