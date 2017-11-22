//
//  main.c
//  cFunda_quiz14_q2
//
//  Created by Juan on 22/11/2017.
//  Copyright © 2017 juan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char a[10];
    a[0] = 's';
    a[1] = 101;
    a[2] = 'a'+2;
    a[3] = 'r';
    a[4] = 101;
    a[5] = 'u'-1;
    a[6] = 0;
    
    printf("%s\n",a);
    
    return 0;
}

