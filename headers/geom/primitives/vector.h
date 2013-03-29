#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "type_aliases.h"
#include "geom/primitives/range.h"

namespace geom {
namespace structures {

    struct vector_2f
    {
        float x, y;

        vector_2f(float x, float y)
            : x(x)
            , y(y)
        {}
    };

    inline float operator ^ (vector_2f const & v1, vector_2f const & v2)
    {
        float x1 = v1.x, y1 = v1.y, x2 = v2.x, y2 = v2.y;
        return x1 * y2 - x2 * y1;
    }

    inline float operator * (vector_2f const & v1, vector_2f const & v2)
    {
        float x1 = v1.x, y1 = v1.y, x2 = v2.x, y2 = v2.y;
        return x1 * x2 + y1 * y2;
    }

    inline vector_2f const operator - (vector_2f const & v) { return vector_2f(-v.x, -v.y); }

}}

#endif /* _VECTOR_H_ */
