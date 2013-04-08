#pragma once

#include <cg/primitives/segment.h>
#include <cg/primitives/range.h>
#include <cg/primitives/point.h>

#include <cg/operations/orientation.h>

namespace cg
{
   inline bool has_intersection(segment_2 a, segment_2 b)
   {
      orientation_t ab[2];
      for (size_t l = 0; l != 2; ++l)
         ab[l] = orientation(a[0], a[1], b[l]);

      if (ab[0] == ab[1] && ab[0] == CG_COLLINEAR)
      {
         if (a[0] > a[1]) std::swap(a[0], a[1]);
         if (b[0] > b[1]) std::swap(b[0], b[1]);

         typedef range_t<point_2> point_range;

         return !(point_range(a[0], a[1]) & point_range(b[0], b[1])).is_empty();
      }

      if (ab[0] == ab[1])
         return false;

      for (size_t l = 0; l != 2; ++l)
         ab[l] = orientation(b[0], b[1], a[l]);

      return ab[0] != ab[1];
   }
}
