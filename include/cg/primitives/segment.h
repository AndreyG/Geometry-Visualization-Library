#pragma once

#include <stdexcept>
#include <boost/lexical_cast.hpp>

#include "point.h"

namespace cg
{
   template <class Scalar> struct segment_2t;
   typedef segment_2t<float> segment_2f;
   typedef segment_2t<double> segment_2;

   template <class Scalar>
   struct segment_2t
   {
      segment_2t() {}

      segment_2t(point_2t<Scalar> const & beg, point_2t<Scalar> const & end)
         : beg(beg)
         , end(end)
      {}

      point_2t<Scalar> const & operator[] (size_t i) const
      {
         switch (i)
         {
         case 0: return beg;
         case 1: return end;
         default:
            throw std::logic_error("invalid index: " + boost::lexical_cast<std::string>(i));
         }
      }

      point_2t<Scalar> & operator[] (size_t i)
      {
         switch (i)
         {
         case 0: return beg;
         case 1: return end;
         default:
            throw std::logic_error("invalid index: " + boost::lexical_cast<std::string>(i));
         }
      }

   private:
      point_2t<Scalar> beg, end;
   };

   template <class Scalar>
   point_2t<Scalar> const & min(segment_2t<Scalar> const & seg) { return std::min(seg[0], seg[1]); }

   template <class Scalar>
   point_2t<Scalar> const & max(segment_2t<Scalar> const & seg) { return std::max(seg[0], seg[1]); }

   template <class Scalar>
   bool operator == (segment_2t<Scalar> const & a, segment_2t<Scalar> const & b)
   {
      return (a[0] == b[0]) && (a[1] == b[1]);
   }

   template <class Scalar>
   bool operator != (segment_2t<Scalar> const & a, segment_2t<Scalar> const & b)
   {
      return !(a == b);
   }
}
