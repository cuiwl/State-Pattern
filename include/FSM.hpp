#ifndef state_pattern_FSM_hpp
#define state_pattern_FSM_hpp

#include "state/Parent.hpp"
#include "state/Identifiable.hpp"
#include "state/StateHolderBase.hpp"
#include "state/Dispatcher.hpp"

namespace state_pattern {

enum FSM_State
{
   FSM_Down,
   FSM_Initial,
   FSM_Idle,
   FSM_Running
};

class FSM
{
   // constructor / destructor
   public:
      FSM();

      virtual ~FSM();

   // command
   public:
      void start();

      void stop();

      void handleCall(FSM_State dest) { mStateHolder.dispatchCall(dest, "Trigger Started"); }

   // State
   private:
      class State
         : public Parent<FSM>
         , public Identifiable
      {
         public:
            State(FSM&  parent,
                  char const* const    pIdentifier)
               : Parent<FSM>(parent)
               , Identifiable(pIdentifier)
            {
            }

            virtual ~State()
            {
            }
         // enter / leave
         public:
            virtual void enter();

            virtual void leave();

         // trigger / event 
         public:
            virtual State* startFSM();

            virtual State* stopFSM();

            virtual State* handleCall(FSM_State dest);
      };

      // state Down
      class Down
         : public State
      {
         public:
            Down(FSM&   parent)
               : State(parent, "FSM_Down")
            {
            }

         public:
            virtual State* startFSM();
      };

      class Initial
         : public State
      {
         public:
            Initial(FSM&   parent)
               : State(parent, "FSM_Initial")
            {
            }

         public:
            virtual State* handleCall(FSM_State dest);
      };

      class Idle
         : public State
      {
         public:
            Idle(FSM&  parent)
               : State(parent, "FSM_Idle")
            {
            }

         public:
            virtual State* handleCall(FSM_State dest);
      };

      class Running
         : public State
      {
         public:
            Running(FSM&  parent)
               : State(parent, "FSM_Running")
            {
            }

         public:
            virtual State* handleCall(FSM_State dest);
      };

   // StateHolder
      struct StateHolder
         : public StateHolderBase<State, state_pattern::log::DefaultLogging<StateHolder, State> >
         , public DispatchCall<StateHolder>
         , public DispatchResult<StateHolder>
         , public DispatchError<StateHolder>
      {
         const char* identifier() const { return "FSM"; }
      };

   // helper
   private:
      FSM& self() { return *this; }

   // attribute
   private:
      Down              mDown;
      Initial           mInitial;
      Idle              mIdle;
      Running           mRunning;
      StateHolder       mStateHolder;
};

} // namespace state_pattern
#endif // state_pattern_FSM_hpp