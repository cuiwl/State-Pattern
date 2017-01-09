
#include "../include/state/DefaultLogging.hpp"
#include <iostream>

namespace state_pattern {
namespace log {

void DefaultLoggingBase::logMsg(const char* pMsg) 
{
   printf("%s \n", pMsg);
}

void DefaultLoggingBase::logError(const char* pMsg) 
{
   printf("%s \n", pMsg);
}

void DefaultLoggingBase::_logStart(const char* pStateHolderIdentifier,
                                   const char* pStateIdentifier)
{
   printf("%s:started with initial state '%s' \n", pStateHolderIdentifier, pStateIdentifier);
}

void DefaultLoggingBase::_logStateChange(const char* pStateHolderIdentifier,
                                         const char* pFromStateIdentifier,
                                         const char* pToStateIdentifier)
{
   printf("%s:%s->%s \n", pStateHolderIdentifier, pFromStateIdentifier, pToStateIdentifier);
}

void DefaultLoggingBase::_logStateMsg(const char* pStateHolderIdentifier,
                                      const char* pMessage)
{
   printf("%s:%s \n", pStateHolderIdentifier, pMessage);
}

void DefaultLoggingBase::_logStateError(const char* pStateHolderIdentifier,
                                        const char* pMessage)
{
   printf("%s:%s \n", pStateHolderIdentifier, pMessage);
}

} // namespace log
} // namespace state_pattern
