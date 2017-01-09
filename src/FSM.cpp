#include "../include/FSM.hpp"

#include <iostream>

namespace state_pattern {

// constructor / destructor
FSM::FSM()
   : mDown(self())
   , mInitial(self())
   , mIdle(self())
   , mRunning(self())
   , mStateHolder()
{
   mStateHolder.start(mDown);
}

FSM::~FSM()
{
   mStateHolder.stop();
}

// command
void FSM::start()
{
   mStateHolder.setState(mStateHolder.state().startFSM());
}

void FSM::stop()
{
   mStateHolder.setState(mStateHolder.state().stopFSM());
}

// Down
FSM::State* FSM::Down::startFSM()
{
   printf("%s:startFSM \n", identifier());
   return &parent().mInitial;
}

// Initial
FSM::State* FSM::Initial::handleCall(FSM_State dest)
{
   switch (dest)
   {
   case state_pattern::FSM_Down:
      return &parent().mDown;
   case state_pattern::FSM_Initial:
      break;
   case state_pattern::FSM_Idle:
      return &parent().mIdle;
   case state_pattern::FSM_Running:
      return &parent().mRunning;
   default:
      break;
   }
   return 0;
}

// Idle
FSM::State* FSM::Idle::handleCall(FSM_State dest)
{
   switch (dest)
   {
   case state_pattern::FSM_Down:
      return &parent().mDown;
   case state_pattern::FSM_Initial:
      return &parent().mInitial;
   case state_pattern::FSM_Idle:
      break;
   case state_pattern::FSM_Running:
      return &parent().mRunning;
   default:
      break;
   }
   return 0;
}

// Running
FSM::State* FSM::Running::handleCall(FSM_State dest)
{
   switch (dest)
   {
   case state_pattern::FSM_Down:
      return &parent().mDown;
   case state_pattern::FSM_Initial:
      return &parent().mInitial;
   case state_pattern::FSM_Idle:
      return &parent().mIdle;
   case state_pattern::FSM_Running:
      break;
   default:
      break;
   }
   return 0;
}

// State
void FSM::State::enter()
{
}

void FSM::State::leave()
{
}

FSM::State* FSM::State::startFSM()
{
   return 0;
}

FSM::State* FSM::State::stopFSM()
{
   printf("%s:stopFSM \n", identifier());
   return &parent().mDown;
}

FSM::State* FSM::State::handleCall(FSM_State dest)
{
   printf("%s:handleCall - dest:%d \n", identifier(), static_cast<int>(dest));
   return 0;
}

} // namespace state_pattern