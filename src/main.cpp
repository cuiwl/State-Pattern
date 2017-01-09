// main.cpp : Defines the entry point for the console application.
//

#include "../include/FSM.hpp"

int main(int argc, char* argv[])
{
   state_pattern::FSM fsm;

   fsm.start();
   fsm.handleCall(state_pattern::FSM_Running);
   fsm.stop();

	return 0;
}

