#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "geom/primitives/range.h"
#include "geom/primitives/point.h"

namespace geom {
namespace structures {

    struct rectangle_2f
    {
        range_f x, y;

        rectangle_2f(range_f const & x, range_f const & y)
            : x(x)
            , y(y)
        {}

        rectangle_2f() {}

        bool is_empty() const
        {
            return x.is_empty() && y.is_empty();
        }

        bool contains(point_2f const & pt) const
        {
            return x.contains(pt.x) && y.contains(pt.y);
        }

        point_2f corner(size_t h, size_t v) const
        {
            return point_2f(  (h == 0) ? x.inf : x.sup,
                                (v == 0) ? y.inf : y.sup  );
        }

        static rectangle_2f maximal()
        {
            return rectangle_2f(range_f::maximal(), range_f::maximal());
        }
    };

    inline rectangle_2f const operator & (rectangle_2f const & a, rectangle_2f const & b)
    {
        return rectangle_2f(a.x & b.x, a.y & b.y);
    }

    inline point_2f center(rectangle_2f const & rect)
    {
        return point_2f(center(rect.x), center(rect.y));
    }
}}

#endif /* _RECTANGLE_H_ */
