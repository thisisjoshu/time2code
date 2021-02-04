#include <stdio.h>
#include <unistd.h>
#include "time2code.h"

// DO NOT CHANGE/EDIT THIS FILE!!

void execute_test(int count[2], int test_num, int town, int month, int day, 
    int time, int expected);
void test_passed(int points[2]);
void test_failed(int points[2], int test_num);
void give_feedback(int test_num, int town, int month, int day, int time, 
    int expected);

int *run_unit_tests(void) {
    static int count[2] = {0, 0};
    int test_num = 0;

    printf("\n");
    printf("running first set of tests...\n");
    sleep(1);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 42, 0, 0, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, 76, 12, 3, 0, INVALID_INPUT);
    
    test_num++;
    execute_test(count, test_num, -1, 12, 3, 0, INVALID_INPUT);
    
    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, -5, 3, 0, INVALID_INPUT);
    
    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 5, 0, 0, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 0, 1, 0, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 5, -6, 0, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 5, 3, -6, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 4, 2600, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 78, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 2, 30, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 1, 32, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 32, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 5, 32, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 7, 32, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 8, 32, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 10, 32, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 12, 32, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 4, 31, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 6, 31, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 9, 31, 500, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 11, 31, 500, INVALID_INPUT);

    printf("\n");
    printf("running second set of tests...\n");
    sleep(1);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 5, 20, 0, 1000);

    test_num++;
    execute_test(count, test_num, TOWN_WELLINGTON, 1, 31, 2200, 1100);

    test_num++;
    execute_test(count, test_num, TOWN_ADELAIDE, 6, 20, 100, 1030);

    test_num++;
    execute_test(count, test_num, TOWN_BRISBANE, 8, 20, 1000, 2000);

    test_num++;
    execute_test(count, test_num, TOWN_BROKEN_HILL, 8, 15, 1200, 2130);

    test_num++;
    execute_test(count, test_num, TOWN_CANBERRA, 6, 15, 1200, 2200);

    test_num++;
    execute_test(count, test_num, TOWN_MELBOURNE, 6, 15, 1400, 0);

    test_num++;
    execute_test(count, test_num, TOWN_HOBART, 6, 15, 1500, 100);

    test_num++;
    execute_test(count, test_num, TOWN_EUCLA, 6, 15, 1200, 2045);

    test_num++;
    execute_test(count, test_num, TOWN_DARWIN, 6, 15, 1200, 2130);

    test_num++;
    execute_test(count, test_num, TOWN_LORD_HOWE_IS, 7, 15, 1100, 2130);

    test_num++;
    execute_test(count, test_num, TOWN_PERTH, 5, 10, 1200, 2000);

    test_num++;
    execute_test(count, test_num, TOWN_PERTH, 5, 10, 1100, 1900);

    test_num++;
    execute_test(count, test_num, TOWN_AUCKLAND, 5, 10, 1000, 2200);

    test_num++;
    execute_test(count, test_num, TOWN_CHRISTCHURCH, 5, 10, 900, 2100);

    test_num++;
    execute_test(count, test_num, TOWN_WELLINGTON, 5, 10, 1200, 0);

    printf("\n");
    printf("running third set of tests...\n");
    sleep(1);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 20, 0, 1100);

    test_num++;
    execute_test(count, test_num, TOWN_ADELAIDE, 1, 20, 100, 1130);

    test_num++;
    execute_test(count, test_num, TOWN_BROKEN_HILL, 2, 20, 0, 1030);

    test_num++;
    execute_test(count, test_num, TOWN_CANBERRA, 3, 20, 0, 1100);

    test_num++;
    execute_test(count, test_num, TOWN_MELBOURNE, 3, 20, 1000, 2100);

    test_num++;
    execute_test(count, test_num, TOWN_HOBART, 3, 20, 800, 1900);

    test_num++;
    execute_test(count, test_num, TOWN_LORD_HOWE_IS, 11, 20, 0, 1100);

    test_num++;
    execute_test(count, test_num, TOWN_AUCKLAND, 3, 20, 0, 1300);

    test_num++;
    execute_test(count, test_num, TOWN_CHRISTCHURCH, 12, 20, 0, 1300);

    test_num++;
    execute_test(count, test_num, TOWN_WELLINGTON, 10, 20, 0, 1300);

    printf("\n");
    printf("running final set of tests...\n");
    sleep(1);

    test_num++;
    execute_test(count, test_num, TOWN_EUCLA, 2, 20, 2359, 844);

    test_num++;
    execute_test(count, test_num, TOWN_EUCLA, 2, 20, 2355, 840);

    test_num++;
    execute_test(count, test_num, TOWN_EUCLA, 2, 20, 845, 1730);

    test_num++;
    execute_test(count, test_num, TOWN_ADELAIDE, 7, 19, 1400, 2330);

    test_num++;
    execute_test(count, test_num, TOWN_PERTH, 6, 20, 2359, 759);

    test_num++;
    execute_test(count, test_num, TOWN_DARWIN, 4, 25, 1206, 2136);

    test_num++;
    execute_test(count, test_num, TOWN_CHRISTCHURCH, 9, 26, 200, 1500);

    test_num++;
    execute_test(count, test_num, TOWN_LORD_HOWE_IS, 10, 3, 200, 1300);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 10, 3, 200, 1300);

    test_num++;
    execute_test(count, test_num, TOWN_WELLINGTON, 4, 4, 300, 1500);

    test_num++;
    execute_test(count, test_num, TOWN_LORD_HOWE_IS, 4, 4, 200, 1230);

    test_num++;
    execute_test(count, test_num, TOWN_MELBOURNE, 4, 4, 300, 1300);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 4, 560, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 4, 60, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 4, 61, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 4, 172, INVALID_INPUT);

    test_num++;
    execute_test(count, test_num, TOWN_SYDNEY, 3, 4, 99, INVALID_INPUT);
    
    sleep(1);

    return count;
}

void execute_test(int count[2], int test_num, int town, int month, int day, 
    int time, int expected) {

    int output = get_local_time(town, month, day, time);
    if (output == expected) {
        test_passed(count);
    } else {
        test_failed(count, test_num);
        give_feedback(test_num, town, month, day, time, expected);
    }
}

void test_passed(int points[2]) {
    printf("test passed\n");
    points[0]++;
}

void test_failed(int points[2], int test_num) {
    printf("test %d failed\n", test_num);
    points[1]++;
}

void give_feedback(int test_num, int town, int month, int day, int time, 
    int expected) {

    printf("\n---------------test-%d-feedback---------------\n", test_num);
    printf("The input for this test was:\n");
    printf("\n");
    printf("UTC month = %d\n", month);
    printf("UTC day = %d\n", day);
    printf("UTC time = %d\n", time);
    printf("\n");

    int local_time = get_local_time(town, month, day, time);
    printf("Your program produced the following output:\n");
    if (local_time == INVALID_INPUT)
         printf("invalid input - local time could not be calculated\n");
    else
        printf("local_time is %d\n", local_time);
    printf("\n");

    printf("The expected output is the following:\n");

    if (expected == INVALID_INPUT)
        printf("invalid input - local time could not be calculated\n");
    else
        printf("local_time is %d\n", expected);
    printf("\n----------------------------------------------\n");
}