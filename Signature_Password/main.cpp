//
//  main.cpp
//  Signature_Password
//
//  Created by luke anfang on 2/13/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#include <iostream>
#include <curses.h>

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
    bool moribund = false;
    while(!moribund)
    {
        c = getch();
        if(c == '\n'){
            std::cout << "enter was pressed\n";
            break;
        }
        if(c == KEY_BACKSPACE && passwordIndex > 0){
            --passwordIndex;
        }
        else
        {
            password[passwordIndex] = c;
            ++passwordIndex;
        }
        //printw("[%s]",c);
    }
    printw("\nPleased to meet you, %s ! Shhhh this was your password [%s]!",username,password);
    refresh();
    getch();
    //printf("received %c (%d)\n", c, (int) c);
    //if(c == '\n') std::cout << "enter was pressed\n";
    endwin();
    return 0;
}
