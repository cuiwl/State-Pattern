#ifndef state_pattern_Parent_hpp
#define state_pattern_Parent_hpp

namespace state_pattern {

template <typename Parent_>
class Parent {
   public:
      typedef Parent_   ParentType;

   protected:
      Parent(ParentType& parent)
         : mpParent(&parent) { }

   public:
      ParentType& parent() { return *mpParent; }

      const ParentType& parent() const { return *mpParent; }

   private:
      ParentType* mpParent;
};

} // namespace state_pattern
#endif // state_pattern_Parent_hpp
