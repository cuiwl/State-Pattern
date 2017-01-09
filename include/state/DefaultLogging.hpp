#ifndef state_pattern_DefaultLogging_hpp
#define state_pattern_DefaultLogging_hpp

namespace state_pattern {
namespace log {   

struct EmptyStateHolderLogging
{
   void logStart(void* initial) { }

   void logStateChange(void* from, void* to) { }
};

// template <typename State_, 
//           typename SubClass_>
// struct SubClassLogging
// {
//    void logStart(State_* initialState) {
//       static_cast<SubClass_*>(this)->logInitialState(*initialState);
//    }
// 
//    void logStateChange(State_* from, State_* to) {
//       static_cast<SubClass_*>(this)->logChangeState(*from, *to);
//    }
// };

struct DefaultLoggingBase 
{
   static
   void logMsg(const char* pMsg);

   static
   void logError(const char* pMsg);

   static
   void _logStart(const char* pStateHolderIdentifier,
                  const char* pStateIdentifier);

   static
   void _logStateChange(const char* pStateHolderIdentifier,
                        const char* pFromStateIdentifier,
                        const char* pToStateIdentifier);

   static
   void _logStateMsg(const char* pStateHolderIdentifier,
                     const char* pMessage);

   static
   void _logStateError(const char* pStateHolderIdentifier,
                       const char* pMessage);
};

template <typename StateHolder_,
          typename State_>
class DefaultLogging
: public DefaultLoggingBase 
{
   public:
      void logStart(State_* pState) const {
         _logStart(getStateHolder().identifier(), pState->identifier());
      }

      void logStateChange(State_* pFromState,
                          State_* pToState) const {
         _logStateChange(getStateHolder().identifier(), pFromState->identifier(), pToState->identifier());
      }

      void logStateMsg(const char* pMessage) const {
         _logStateMsg(getStateHolder().state().identifier(), pMessage);
      }

      void logStateError(const char* pMessage) const {
         _logStateError(getStateHolder().state().identifier(), pMessage);
      }

   private:
      const StateHolder_& getStateHolder() const { return *static_cast<const StateHolder_*>(this); }
};

} // namespace log
} // namespace state_pattern
#endif // state_pattern_DefaultLogging_hpp
