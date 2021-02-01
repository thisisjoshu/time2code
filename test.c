#include <stdio.h>
#include "time2code.h"

// DO NOT CHANGE THIS FUNCTION!!

int *run_unit_tests(void) {
    static int count[2] = {0, 0};

    printf("\n");
    printf("running first set of tests...\n");

    if (get_local_time(TOWN_SYDNEY, 42, 0, 0) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(76, 12, 3, 0) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }
    
    if (get_local_time(-1, 12, 3, 0) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }
    
    if (get_local_time(TOWN_SYDNEY, -5, 3, 0) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }
    
    if (get_local_time(TOWN_SYDNEY, 5, 0, 0) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 0, 1, 0) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 5, -6, 0) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 5, 3, -6) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 4, 2600) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 78, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 2, 30, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 1, 32, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 32, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 5, 32, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 7, 32, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 8, 32, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 10, 32, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 12, 32, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 4, 31, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 6, 31, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 9, 31, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 11, 31, 500) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    printf("\n");
    printf("running second set of tests...\n");

    if (get_local_time(TOWN_SYDNEY, 5, 20, 0) == 1000) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_WELLINGTON, 1, 31, 2200) == 1100) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_ADELAIDE, 6, 20, 100) == 1030) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_BRISBANE, 8, 20, 1000) == 2000) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_BROKEN_HILL, 8, 15, 1200) == 2130) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_CANBERRA, 6, 15, 1200) == 2200) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_MELBOURNE, 6, 15, 1400) == 0) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_HOBART, 6, 15, 1500) == 100) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_EUCLA, 6, 15, 1200) == 2045) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_DARWIN, 6, 15, 1200) == 2130) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_LORD_HOWE_IS, 7, 15, 1100) == 2130) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_PERTH, 5, 10, 1100) == 1900) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_PERTH, 5, 10, 1100) == 1900) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_AUCKLAND, 5, 10, 1000) == 2200) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_CHRISTCHURCH, 5, 10, 900) == 2100) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_WELLINGTON, 5, 10, 1200) == 0) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    printf("\n");
    printf("running third set of tests...\n");

    if (get_local_time(TOWN_SYDNEY, 3, 20, 0) == 1100) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_ADELAIDE, 1, 20, 100) == 1130) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_BROKEN_HILL, 2, 20, 0) == 1030) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_CANBERRA, 3, 20, 0) == 1100) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_MELBOURNE, 3, 20, 1000) == 2100) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_HOBART, 3, 20, 800) == 1900) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_LORD_HOWE_IS, 11, 20, 0) == 1100) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_AUCKLAND, 3, 20, 0) == 1300) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_CHRISTCHURCH, 12, 20, 0) == 1300) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_WELLINGTON, 10, 20, 0) == 1300) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    printf("\n");
    printf("running final set of tests...\n");
    // offset 845
    if (get_local_time(TOWN_EUCLA, 2, 20, 2359) == 844) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_EUCLA, 2, 20, 2355) == 840) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }
    if (get_local_time(TOWN_EUCLA, 2, 20, 845) == 1730) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_ADELAIDE, 7, 19, 1400) == 2330) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_PERTH, 6, 20, 2359) == 759) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_DARWIN, 4, 25, 1206) == 2136) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_CHRISTCHURCH, 9, 26, 200) == 1500) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_LORD_HOWE_IS, 10, 3, 200) == 1300) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 10, 3, 200) == 1300) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_WELLINGTON, 4, 4, 300) == 1500) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_LORD_HOWE_IS, 4, 4, 200) == 1230) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_MELBOURNE, 4, 4, 300) == 1300) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 4, 560) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 4, 60) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 4, 61) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 4, 172) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }

    if (get_local_time(TOWN_SYDNEY, 3, 4, 99) == INVALID_INPUT) {
        printf("test passed\n");
        count[0]++;
    } else {
        printf("test failed :(\n");
        count[1]++;
    }
    return count;
}

