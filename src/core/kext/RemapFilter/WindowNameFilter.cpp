#include <IOKit/IOLib.h>

#include "WindowNameFilter.hpp"
#include "CommonData.hpp"
#include "IOLogWrapper.hpp"
#include "bridge.h"

namespace org_pqrs_Karabiner {
  namespace RemapFilter {
    void
    WindowNameFilter::initialize(const unsigned int* vec, size_t length)
    {
      for (size_t i = 0; i < length; ++i) {
        targets_.push_back(AddValue(vec[i]));
      }
    }

    bool
    WindowNameFilter::isblocked(void)
    {
      unsigned int current = CommonData::getcurrent_workspacedata().windowname;

      switch (get_type()) {
        case BRIDGE_FILTERTYPE_WINDOWNAME_NOT:
        case BRIDGE_FILTERTYPE_WINDOWNAME_ONLY:
        {
          bool isnot = (get_type() == BRIDGE_FILTERTYPE_WINDOWNAME_NOT);

          for (size_t i = 0; i < targets_.size(); ++i) {
            if (targets_[i] == current) {
              return isnot ? true : false;
            }
          }
          return isnot ? false : true;
        }

        default:
          IOLOG_ERROR("WindowNameFilter::isblocked unknown type_(%d)\n", get_type());
          break;
      }

      return false;
    }
  }
}
