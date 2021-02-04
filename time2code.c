// time2code.c
// Assignment 1, COMP1511 18s1: Time To Code.
//
// This program is written by JOSHUA ZOBULE (z5196042)
//
// Version 1.0.2: Add version numbers and header comment.
// Version 1.0.1: Fix day/time variable mix-up in main function.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include "test.h"
#include "time2code.h"

// ADD YOUR #defines (if any) here

#define TIMEZONE_AWST    0
#define TIMEZONE_ACWST   1
#define TIMEZONE_ACST    2
#define TIMEZONE_ACDT    3
#define TIMEZONE_AEST    4
#define TIMEZONE_AEDT    5
#define TIMEZONE_LHST    6
#define TIMEZONE_LHDT    7
#define TIMEZONE_NZST    8
#define TIMEZONE_NZDT    9

#define TRUE        1
#define FALSE       0

// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE

int get_timezone(int town, int utc_month, int utc_day, int utc_time);
int town_observes_acdt(int town);
int town_observes_aedt(int town);
int town_observes_lhdt(int town);
int town_observes_nzdt(int town);
int aus_standard_time(int month, int day, int time);
int nz_standard_time(int month, int day, int time);
int lh_standard_time(int month, int day, int time);
int add_offset(int time, int offset);
int valid_input_check(int town, int month, int day, int time);
int twenty_eight_day_month(int month);
int thirty_one_day_month(int month);
int thirty_day_month(int month);

int main(void) {
    int call_get_local_time = 0;

    printf("Enter 0 to run tests\n");
    printf("Enter 1 to call get_local_time()\n");
    printf("----------------------------------------------\n");
    printf("Call which function: ");
    scanf("%d", &call_get_local_time);

    if (!call_get_local_time) {
        int *counter = run_unit_tests();
        printf("\n");
        printf("testing done\n");
        printf("----------------------------------------------\n");

        int passed = counter[0];
        int failed = counter[1];
        int total = passed + failed;

        if (passed != total) printf("You have successfully passed %d/%d tests\n", passed, total);
        if (failed != 0) printf("You have failed %d/%d tests\n", failed, total);
        
        if (passed == total) printf("Welldone! You did an awesome job! All tests passed\n");
        return 0;
    }

    int town = 0;
    int month = 0;
    int day = 0;
    int time = 0;

    printf("Enter %d for Adelaide\n", TOWN_ADELAIDE);
    printf("Enter %d for Brisbane\n", TOWN_BRISBANE);
    printf("Enter %d for Broken_hill\n", TOWN_BROKEN_HILL);
    printf("Enter %d for Canberra\n", TOWN_CANBERRA);
    printf("Enter %d for Darwin\n", TOWN_DARWIN);
    printf("Enter %d for Eucla\n", TOWN_EUCLA);
    printf("Enter %d for Hobart\n", TOWN_HOBART);
    printf("Enter %d for Lord Howe Island\n", TOWN_LORD_HOWE_IS);
    printf("Enter %d for Melbourne\n", TOWN_MELBOURNE);
    printf("Enter %d for Perth\n", TOWN_PERTH);
    printf("Enter %d for Sydney\n", TOWN_SYDNEY);
    printf("Enter %d for Auckland\n", TOWN_AUCKLAND);
    printf("Enter %d for Christchurch\n", TOWN_CHRISTCHURCH);
    printf("Enter %d for Wellington\n", TOWN_WELLINGTON);

    printf("Which town: ");
    scanf("%d", &town);

    printf("Enter UTC month as integer 1..12: ");
    scanf("%d", &month);

    printf("Enter UTC day as integer 1..31: ");
    scanf("%d", &day);

    printf("Enter UTC time as hour * 100 + minutes\n");
    printf("Enter UTC time as integer [0..2359]: ");
    scanf("%d", &time);

    int local_time = get_local_time(town, month, day, time);

    if (local_time == INVALID_INPUT) {
        printf("invalid input - local time could not be calculated\n");
    } else {
        printf("local_time is %d\n", local_time);
    }
    return 0;
}

// Given an Australian town and a 2021 UTC time
// return the local time in the Australian town

// time is returned as hours*100 + minutes
// INVALID_INPUT is return for invalid inputs

// utc_month should be 1..12
// utc_day should be 1..31
// utc_time should be 0..2359
// utc_time is hours*100 + minutes

// note UTC year is assumed to be 2021
// note UTC seconds is assumed to be zero


int get_local_time(int town, int utc_month, int utc_day, int utc_time) {
    int valid_input = valid_input_check(town, utc_month, utc_day, utc_time);

    if (valid_input == FALSE)
        return INVALID_INPUT;

    int local_time = 0;
    int timezone = 0;

    // determine what time zone (including daylight savings)
    timezone = get_timezone(town, utc_month, utc_day, utc_time);

    // add offset
    if (timezone == TIMEZONE_AWST)
        local_time = add_offset(utc_time,TIMEZONE_AWST_OFFSET);
    else if (timezone == TIMEZONE_ACWST)
        local_time = add_offset(utc_time, TIMEZONE_ACWST_OFFSET);
    else if (timezone == TIMEZONE_ACST)
        local_time = add_offset(utc_time,TIMEZONE_ACST_OFFSET);
    else if (timezone == TIMEZONE_ACDT) 
        local_time = add_offset(utc_time, TIMEZONE_ACDT_OFFSET);
    else if (timezone == TIMEZONE_AEST)
        local_time = add_offset(utc_time, TIMEZONE_AEST_OFFSET);
    else if (timezone == TIMEZONE_AEDT)
        local_time = add_offset(utc_time, TIMEZONE_AEDT_OFFSET);
    else if (timezone == TIMEZONE_LHST)
        local_time = add_offset(utc_time, TIMEZONE_LHST_OFFSET);
    else if (timezone == TIMEZONE_LHDT)
        local_time = add_offset(utc_time, TIMEZONE_LHDT_OFFSET);
    else if (timezone == TIMEZONE_NZST)
        local_time = add_offset(utc_time, TIMEZONE_NZST_OFFSET);
    else if (timezone == TIMEZONE_NZDT) 
        local_time = add_offset(utc_time, TIMEZONE_NZDT_OFFSET);
    
    return local_time;
}

// get_timezone returns the timezone for a town given the utc date and utc time
int get_timezone(int town, int utc_month, int utc_day, int utc_time) {
    // towns that do not observe daylight savings 
    if (town == TOWN_PERTH) 
        return TIMEZONE_AWST;
    if (town == TOWN_EUCLA) 
        return TIMEZONE_ACWST;
    if (town == TOWN_DARWIN) 
        return TIMEZONE_ACST;
    if (town == TOWN_BRISBANE) 
        return TIMEZONE_AEST;

    // ACST towns
    if (town_observes_acdt(town) == TRUE) {
        int standard_time = aus_standard_time(utc_month, utc_day, utc_time);
        if (standard_time == TRUE) 
            return TIMEZONE_ACST;
        else 
            return TIMEZONE_ACDT;
    }

    // AEST towns
    else if (town_observes_aedt(town) == TRUE) {
        int standard_time = aus_standard_time(utc_month, utc_day, utc_time);
        if (standard_time == TRUE) 
            return TIMEZONE_AEST;
        else   
            return TIMEZONE_AEDT;
    }

    // LHST towns
    else if (town_observes_lhdt(town) == TRUE) {
        int standard_time = lh_standard_time(utc_month, utc_day, utc_time);
        if (standard_time == TRUE)
            return TIMEZONE_LHST;
        else 
            return TIMEZONE_LHDT;
    }

    // NZST towns
    else if (town_observes_nzdt(town) == TRUE) {
        int standard_time = nz_standard_time(utc_month, utc_day, utc_time);
        if (standard_time == TRUE)
            return TIMEZONE_NZST;
        else 
            return TIMEZONE_NZDT;
    }
}

// this function determines whether or not a town observes ACDT
int town_observes_acdt(int town) {
    if (town == TOWN_ADELAIDE || town == TOWN_BROKEN_HILL)
        return TRUE;
    else 
        return FALSE;
}

// this function determines whether or not a town observes AEDT
int town_observes_aedt(int town) {
    if (town == TOWN_CANBERRA || town == TOWN_MELBOURNE ||
        town == TOWN_SYDNEY || town == TOWN_HOBART)
        return TRUE;
    else 
        return FALSE;
}

// this function determines whether or not a town observes LHDT
int town_observes_lhdt(int town) {
    if (town == TOWN_LORD_HOWE_IS)
        return TRUE;
    else 
        return FALSE;
}

// this function determines whether or not a town observes NZDT
int town_observes_nzdt(int town) {
    if (town == TOWN_AUCKLAND || town == TOWN_CHRISTCHURCH ||
        town == TOWN_WELLINGTON)
        return TRUE;
    else 
        return FALSE;
}

// this function determines if a given utc date and time is in australia's
// standard time. All australia timezones except for lord 
// howe island follows this same pattern.
int aus_standard_time(int month, int day, int time) {
    int time_converted = (month * 1000000) + (day * 10000) + time;
    int standard_time_start = 4040300;      // 4th April 3:00am
    int standard_time_end = 10030200;       // 3rd October 2:00am

    if (time_converted >= standard_time_start && 
        time_converted < standard_time_end)
        return TRUE;
    else 
        return FALSE;
}

// this function determines if a given utc date and time is in nz's
// standard time.
int nz_standard_time(int month, int day, int time) {
    int time_converted = (month * 1000000) + (day * 10000) + time;
    int standard_time_start = 4040300;      // 4th April 3:00am
    int standard_time_end = 9260200;        // 26th September 2:00am
    
    if (time_converted >= standard_time_start && 
        time_converted < standard_time_end)
        return TRUE;
    else 
        return FALSE;
}

// this function determines if a given utc date and time is in 
// lord howe island's standard time.
int lh_standard_time(int month, int day, int time) {
    int time_converted = (month * 1000000) + (day * 10000) + time;
    int standard_time_start = 4040200;      // 4th April 2:00am
    int standard_time_end = 10030200;       // 3rd October 2:00am
    
    if (time_converted >= standard_time_start && 
        time_converted < standard_time_end)
        return TRUE;
    else 
        return FALSE;
}

// this function, given an offset and the utc time, adds the 
// offset to the utc time. It fixes invalid times before returning
// the new time (local time)
int add_offset(int time, int offset) {

    int offset_minutes = offset % 100;
    int offset_hours = offset - offset_minutes;
    int new_time = time + offset_hours;
    
    if (new_time >= 2400) {
        new_time = new_time - 2400;
    }

    int new_time_minutes = new_time % 100;

    if (new_time_minutes + offset_minutes >= 60) {
        new_time = new_time + 40;
    }

    new_time = new_time + offset_minutes;

    return new_time;
}

// this function checks if inputs are valid or not
int valid_input_check(int town, int month, int day, int time) {
    int minutes = time % 100;

    if (town > 13 || town < 0)
        return FALSE;
    
    if (month > 12 || month < 1)
        return FALSE;
    
    if (time > 2359 || time < 0)
        return FALSE;
    
    if (minutes > 59)
        return FALSE;
    
    if (day < 1)
        return FALSE;
    
    if (twenty_eight_day_month(month) == TRUE && day > 28)
        return FALSE;

    if (thirty_one_day_month(month) == TRUE && day > 31)
        return FALSE;
    
    if (thirty_day_month(month) == TRUE && day > 30)
        return FALSE;

    return TRUE;
}

// this funtion returns TRUE if a month has 28 days. FALSE is
// returned otherwise
int twenty_eight_day_month(int month) {
    if (month == 2)
        return TRUE;
    
    return FALSE;
}

// this funtion returns TRUE if a month has 31 days. FALSE is
// returned otherwise
int thirty_one_day_month(int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || 
        month == 8 || month == 10 || month == 12)
        return TRUE;
    
    return FALSE;
}

// this funtion returns TRUE if a month has 30 days. FALSE is
// returned otherwise
int thirty_day_month(int month) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return TRUE;
    
    return FALSE;
}
