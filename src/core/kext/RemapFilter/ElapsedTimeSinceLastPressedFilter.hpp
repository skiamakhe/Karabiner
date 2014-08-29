#ifndef ELAPSEDTIMESINCELASTPRESSEDFILTER_HPP
#define ELAPSEDTIMESINCELASTPRESSEDFILTER_HPP

#include "RemapFilterBase.hpp"

namespace org_pqrs_Karabiner {
  namespace RemapFilter {
    class ElapsedTimeSinceLastPressedFilter : public RemapFilterBase {
    public:
      ElapsedTimeSinceLastPressedFilter(unsigned int type) : RemapFilterBase(type) {}

      void initialize(const unsigned int* vec, size_t length);
      bool isblocked(void);

    private:
      Vector_FilterValueWithDataType targets_;
    };
  }
}

#endif
