#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "type_aliases.h"
#include "geom/primitives/range.h"

namespace geom {
namespace structures {

    struct vector_type
    {
        float x, y;

        vector_type(float x, float y)
            : x(x)
            , y(y)
        {}
    };

    inline float operator ^ (vector_type const & v1, vector_type const & v2)
    {
        float x1 = v1.x, y1 = v1.y, x2 = v2.x, y2 = v2.y;
        return x1 * y2 - x2 * y1;
    }

    inline float operator * (vector_type const & v1, vector_type const & v2)
    {
        float x1 = v1.x, y1 = v1.y, x2 = v2.x, y2 = v2.y;
        return x1 * x2 + y1 * y2;
    }

    inline vector_type const operator - (vector_type const & v) { return vector_type(-v.x, -v.y); }

}}

#endif /* _VECTOR_H_ */
