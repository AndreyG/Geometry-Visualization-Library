#ifndef _POINT_H_
#define _POINT_H_

#include "geom/primitives/vector.h"

namespace geom {
namespace structures {

    struct point_2f
    {
        float x, y;

        point_2f(float x, float y)
            : x(x)
            , y(y)
        {}

        point_2f()
            : x(0)
            , y(0)
        {}

        point_2f & operator += (vector_2f const & delta)
        {
            x += delta.x;
            y += delta.y;
            return *this;
        }
    };

    inline bool operator < (point_2f const & a, point_2f const & b)
    {
        if (a.x == b.x)
            return a.y < b.y;
        else
            return a.x < b.x;
    }

    inline bool operator > (point_2f const & a, point_2f const & b)
    {
        return b < a;
    }

    inline bool operator == (point_2f const & a, point_2f const & b)
    {
        return (a.x == b.x) && (a.y == b.y);
    }

    inline bool operator != (point_2f const & a, point_2f const & b)
    {
        return !(a == b);
    }

    // в этом месте возможно переполнение!
    inline vector_2f const operator - (point_2f const & a, point_2f const & b)
    {
        return vector_2f(a.x - b.x, a.y - b.y);
    }

    // в этом месте возможно переполнение!
    inline point_2f const operator + (point_2f const & pt, vector_2f const & delta)
    {
        point_2f res(pt);
        res += delta;
        return res;
    }
}}

#endif /* _POINT_H_ */
