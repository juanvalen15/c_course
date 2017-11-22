//
//  main.c
//  cFunda_quiz14_q3
//
//  Created by Juan on 22/11/2017.
//  Copyright © 2017 juan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char a[10] = "Hello";
    *(a+4) = 0;
    
    printf("%s\n",a);
    
    return 0;
}


