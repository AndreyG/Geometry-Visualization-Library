#ifndef _RANGE_H_
#define _RANGE_H_

#include "type_aliases.h"
#include <limits>

namespace geom {
namespace structures {

    // closed range
    struct range_type
    {
        float inf, sup;

        range_type(float inf, float sup)
            : inf(inf)
            , sup(sup)
        {}

        range_type()
            : inf(0)
            , sup(-1)
        {}

        bool is_empty() const { return inf > sup; }

        bool contains(float x) const { return (inf <= x) && (x <= sup); }

        static range_type maximal()
        {
            static const float max_val = std::numeric_limits<float>::max();
            return range_type(-max_val, max_val);
        }
    };

    inline range_type const operator & (range_type const & a, range_type const & b)
    {
        return range_type(std::max(a.inf, b.inf), std::min(a.sup, b.sup));
    }

    inline float center(range_type const & r)
    {
        return .5f + r.inf / 2.f + r.sup / 2.f;
    }

    inline float size(range_type const & r)
    {
        return r.sup - r.inf;
    }

}}

#endif /* _RANGE_H_ */
