#ifndef TEST_TEST_H
#define TEST_TEST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define FILE_IN

int test() {
#ifdef FILE_IN
    freopen("./data_files/test.in","r",stdin);
#endif
    int temp_int;
    char temp_char;
    int N,M;
    int * p;
    scanf("%d %d",&N, &M);
    M = 7;
    printf("%d %d\n",sizeof(int),M*sizeof(int));
    int* arr = (int*)malloc( M * sizeof(int)); //切记这里给的大小，是10  *  int（4个字节）
    if(arr == NULL)
    {
        perror("malloc"); //有可能，malloc开辟空间失败，则malloc会返回NULL
        return 1;
    }
    arr[0] = 1;
    int* arr2 = (int*)malloc( M * sizeof(int));
    printf("%p %p %d \n",&arr,arr, arr[0]);
    printf("%p %p %d \n",&arr2,arr2, arr2[0]);
    int* tmp = (int*)realloc(arr,2*M*sizeof(int));
    printf("%p %p %d \n",&arr,arr, arr[0]);
    printf("%p %p %d ",&tmp,tmp, tmp[0]);
    if(tmp != NULL){
        arr = tmp;
    }
    else{
        return 1;
    }
    free(arr2);
    free(arr);
//    for (int i = 0; i < N; ++i) {
//        int array[10] = {0};
//        int j = 0;
//        while(true){
//            scanf("%d",&temp_int);
//            array[j] = temp_int;
//            ++j;
//            printf("%d ", temp_int);
//            temp_char  = getchar();
//            if( temp_char == '\n') break;
//        }
//    }

    return 0;
}
#endif //TEST_TEST_H
