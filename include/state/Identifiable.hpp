#ifndef state_pattern_Identifiable_hpp
#define state_pattern_Identifiable_hpp

namespace state_pattern {

class Identifiable {
   protected:
      Identifiable(const char* pIdentifier)
         : mpIdentifier(pIdentifier) { }

   public:
      const char* identifier() const { return mpIdentifier; }

   private:
      const char* mpIdentifier;
};

} // namespace state_pattern
#endif // state_pattern_Identifiable_hpp
