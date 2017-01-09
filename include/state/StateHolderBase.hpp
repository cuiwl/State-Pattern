#ifndef state_pattern_StateHolderBase_hpp
#define state_pattern_StateHolderBase_hpp

#include "DefaultLogging.hpp"

namespace state_pattern {

template <typename State_,
          typename Logging_ = log::EmptyStateHolderLogging>
class StateHolderBase : public Logging_
{
   // types
   public:
      typedef State_       StateType;

   // constructor
   public:
      StateHolderBase()
         : Logging_(), mpState(0) { }

      StateHolderBase(const Logging_& logging) 
         : Logging_(logging), mpState(0) { }

   // queries / accessors
   public:
      const bool started() const { return (mpState != 0); }

      const StateType& state() const { return (*mpState); }

      StateType& state() { return (*mpState); }

   // commands
   public:
      void start(StateType& initialState) 
      {
         if (!started()) 
         {
            logStart(&initialState);
            mpState = &initialState;
            mpState->enter();
         }
      }

      void stop() 
      {
         if (started()) 
         {
            mpState->leave();
            mpState = 0;
         }
      }

      // transition from oldState to newState
      void setState(StateType& newState) 
      {
         if (started()) {
            logStateChange(mpState, &newState);

            StateType* oldState = mpState;
            mpState = &newState;
            oldState->leave();
            if (mpState == &newState) {
               mpState->enter();
            }
         }
      }

      void setState(StateType* pState) 
      {
         if (pState != 0) {
            setState(*pState);
         }
      }

   // attributes
   private:
      StateType* mpState;

   // copy prevention
   private:
      StateHolderBase(const StateHolderBase& src);
      StateHolderBase& operator=(const StateHolderBase& src);
};

} // namespace state_pattern
#endif // state_pattern_StateHolderBase_hpp
