//
//  main.c
//  cFunda_quiz4_q1
//
//  Created by Juan on 21/11/2017.
//  Copyright © 2017 juan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int house = 1234;
    int *which_house = &house;
    *which_house = 5678;
    printf("house = %d\n", house);
    
    return 0;
}
