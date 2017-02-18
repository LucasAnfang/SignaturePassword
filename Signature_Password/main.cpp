//
//  main.cpp
//  Signature_Password
//
//  Created by luke anfang on 2/13/17.
//  Copyright © 2017 luke anfang. All rights reserved.
//

#include <iostream>
#include <curses.h>
#include <string>
#include "Timer.h"
#include "TimedSignature.h"
#include "UserInputHandler.h"



int main(int argc, const char * argv[]) {
    UserInputHandler::Start();
    UserInputHandler::PromptOption(LoginPrompt, RegisterPrompt);
//    char username[30];
//    char password[30];
//    //char passwordAttempt[30];
//    std::cout << "HIIIIII\n"; 
//    //initialize screan, sets up memory, clears the screan
//    initscr();
// //moves the cursor
//    //int x = 10;
//    //int y = 10;
//    //move(y,x);
//    addstr("What would you like your username to be? ");
//    //refreshes screan to match what is in memory
//    refresh();
//    getstr(username);
//    
//
//    addstr("Enter a password: ");
//    //refresh();
//    int passwordIndex = 0;
//    //getstr(password);
//    int c;
//    TimedSignature* timedSignature = new TimedSignature();
//    bool moribund = false;
//    Timer* t = new Timer();
//    while(!moribund)
//    {
//        //waits for user input, returns int value of the key
//        c = getch();
//        if(c == '\n'){
//            std::cout << "enter was pressed\n";
//            break;
//        }
//        if(c == KEY_BACKSPACE && passwordIndex > 0){
//            delch();
//            --passwordIndex;
//            t -> start();
//        }
//        else
//        {
//            if(passwordIndex == 0)
//            {
//                t -> start();
//            }
//            else
//            {
//                float elapsed = t -> getElapsed();
//                timedSignature -> insertTime(elapsed);
//                t -> start();
//            }
//            password[passwordIndex] = c;
//            ++passwordIndex;
//        }
//        //printw("[%s]",c);
//    }
//    //deallocates memory, ends curses
//    endwin();
//    printf("\nPleased to meet you, %s !\n Shhhh this was your password [%s]!\n",username,password);
//    std::cout << *timedSignature << std::endl;
//    for (int i=0;i < timedSignature -> mSize;i++) {
//        printf("[%lf] ",timedSignature->times[i]);
//    }

    return 0;
}


