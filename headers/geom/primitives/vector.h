#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "type_aliases.h"

namespace geom {
namespace structures {

    struct vector_type
    {
        int32 x, y;

        vector_type(int32 x, int32 y)
            : x(x)
            , y(y)
        {}

        vector_type & operator *= (double alpha)
        {
            x *= alpha;
            y *= alpha;
            return *this;
        }
    };

    inline int64 operator ^ (vector_type const & v1, vector_type const & v2)
    {
        int64 x1 = v1.x, y1 = v1.y, x2 = v2.x, y2 = v2.y;
        return x1 * y2 - x2 * y1;
    }

    inline int64 operator * (vector_type const & v1, vector_type const & v2)
    {
        int64 x1 = v1.x, y1 = v1.y, x2 = v2.x, y2 = v2.y;
        return x1 * x2 + y1 * y2;
    }

    inline vector_type const operator - (vector_type const & v) { return vector_type(-v.x, -v.y); }

    inline vector_type const operator * (vector_type const & v, double alpha)
    {
        vector_type res(v);
        res *= alpha;
        return res;
    }

    inline vector_type const operator * (double alpha, vector_type const & v) { return v * alpha; }

}}

#endif /* _VECTOR_H_ */
