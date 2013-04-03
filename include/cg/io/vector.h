#pragma once

#include "io_utils.h"
#include "cg/primitives/vector.h"

namespace cg
{
   template <class Scalar>
   std::ostream & operator << (std::ostream & out, vector_2t<Scalar> const & v)
   {
      out << "(" << v.x << ", " << v.y << ")";
      return out;
   }
}
