#pragma once

#include <cg/primitives/point.h>
#include <cg/primitives/segment.h>

#include <boost/array.hpp>

namespace cg
{
   template <class Scalar>
   struct triangle_2t;

   typedef triangle_2t<double> triangle_2;

   template <class Scalar>
   struct triangle_2t
   {
      triangle_2t() {}
      triangle_2t(point_2 const & a, point_2 const & b, point_2 const & c)
      {
         // gcc 4.2
         pts_[0] = a;
         pts_[1] = b;
         pts_[2] = c;
      }

      point_2t<Scalar> &         operator [] (size_t id)       { return pts_[id]; }
      point_2t<Scalar> const &   operator [] (size_t id) const { return pts_[id]; }

      segment_2t<Scalar> side(size_t id) const { return segment_2t<Scalar>(pts_[(id + 1) % 3], pts_[(id + 2) % 3]); }

   private:
      boost::array<point_2t<Scalar>, 3 > pts_;
   };
}
