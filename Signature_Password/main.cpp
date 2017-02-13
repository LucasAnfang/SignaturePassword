//
//  main.cpp
//  Signature_Password
//
//  Created by luke anfang on 2/13/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#include <iostream>
#include <curses.h>
#include "Timer.h"
#include "TimedSignature.h"

int main(int argc, const char * argv[]) {
    char username[30];
    char password[30];
    initscr();
    
    addstr("What would you like your username to be? ");
    refresh();
    getstr(username);
    
    addstr("Enter a password: ");
    //refresh();
    int passwordIndex = 0;
    //getstr(password);
    int c;
    TimedSignature* timedSignature = new TimedSignature();
    bool moribund = false;
    Timer* t = new Timer();
    while(!moribund)
    {
        c = getch();
        if(c == '\n'){
            std::cout << "enter was pressed\n";
            break;
        }
        if(c == KEY_BACKSPACE && passwordIndex > 0){
            delch();
            --passwordIndex;
            t -> start();
        }
        else
        {
            if(passwordIndex == 0)
            {
                t -> start();
            }
            else
            {
                float elapsed = t -> getElapsed();
                timedSignature -> insertTime(elapsed);
                t -> start();
            }
            password[passwordIndex] = c;
            ++passwordIndex;
        }
        //printw("[%s]",c);
    }
    endwin();
    printf("\nPleased to meet you, %s !\n Shhhh this was your password [%s]!\n",username,password);
    for (int i=0;i < timedSignature -> mSize;i++) {
        printf("[%lf] ",timedSignature->times[i]);
    }
    //printf("received %c (%d)\n", c, (int) c);
    //if(c == '\n') std::cout << "enter was pressed\n";
    
    return 0;
}
