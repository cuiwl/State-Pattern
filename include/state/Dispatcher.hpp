#ifndef state_pattern_Dispatcher_hpp
#define state_pattern_Dispatcher_hpp

namespace state_pattern {

// method
template <typename StateHolder_>
class DispatchCall {
   public:
      template <typename Call_>
      void dispatchCall(Call_& call, const char* pMessage) 
      {
         if (stateHolder().started())
         {
            if (pMessage) 
            {
               stateHolder().logStateMsg(pMessage);
            }
            stateHolder().setState(stateHolder().state().handleCall(call));
         }
      }

   private:
      StateHolder_& stateHolder() { return *static_cast<StateHolder_*>(this); }
};

template <typename StateHolder_>
class DispatchResult {
   public:
      template <typename Call_>
      void dispatchResult(Call_& call, const char* pMessage) 
      {
         if (stateHolder().started()) 
         {
            if (pMessage)
            {
               stateHolder().logStateMsg(pMessage);
            }
            stateHolder().setState(stateHolder().state().onResult(call));
         }
      }

   private:
      StateHolder_& stateHolder() { return *static_cast<StateHolder_*>(this); }
};

template <typename StateHolder_>
class DispatchError 
{
   public:
      template <typename Call_>
      void dispatchError(Call_& call, const char* pMessage) 
      {
         if (stateHolder().started()) 
         {
            if (pMessage)
            {
               stateHolder().logStateError(pMessage);
            }
            stateHolder().setState(stateHolder().state().onError(call));
         }
      }

   private:
      StateHolder_& stateHolder() { return *static_cast<StateHolder_*>(this); }
};

} // namespace state_pattern
#endif // state_pattern_Dispatcher_hpp
