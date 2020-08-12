// 1-1 Check Size Each Type
#include <stdio.h>

int check_size_each_type() {
    // char 형 변수 하나를 선언하고, 그 다음에는 100개의 인덱스를 갖는 배열을 생성 후 초기화
    char c = '0', c_array[100] = {'0', };
    // int 형 변수 하나를 선언하고, 그 다음에는 100개의 인덱스를 갖는 배열을 생성 후 초기화
    int i = 0, i_array[100] = {0, };
    // short 형 변수 하나를 선언하고, 그 다음에는 100개의 인덱스를 갖는 배열을 생성 후 초기화
    short s = 0, s_array[100] = {0, };
    // float 형 변수 하나를 선언하고, 그 다음에는 100개의 인덱스를 갖는 배열을 생성 후 초기화
    float f = 0.0, f_array[100] = {0.0, };
    // long 형 변수 하나를 선언하고, 그 다음에는 100개의 인덱스를 갖는 배열을 생성 후 초기화
    long l = 0, l_array[100] = {0, };
    
    // 각각의 변수 사이즈를 출력한다.
    printf("c = %d \t c_array = %d\n", sizeof(c), sizeof(c_array));
    printf("i = %d \t i_array = %d\n", sizeof(i), sizeof(i_array));
    printf("s = %d \t s_array = %d\n", sizeof(s), sizeof(s_array));
    printf("f = %d \t f_array = %d\n", sizeof(f), sizeof(f_array));
    printf("l = %d \t l_array = %d\n", sizeof(l), sizeof(l_array));
    
    return 0;
}
