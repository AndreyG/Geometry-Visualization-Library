#ifndef _RANGE_H_
#define _RANGE_H_

#include "type_aliases.h"
#include <limits>

namespace geom {
namespace structures {

    // closed range
    struct range_f
    {
        float inf, sup;

        range_f(float inf, float sup)
            : inf(inf)
            , sup(sup)
        {}

        range_f()
            : inf(0)
            , sup(-1)
        {}

        bool is_empty() const { return inf > sup; }

        bool contains(float x) const { return (inf <= x) && (x <= sup); }

        static range_f maximal()
        {
            static const float max_val = std::numeric_limits<float>::max();
            return range_f(-max_val, max_val);
        }
    };

    inline range_f const operator & (range_f const & a, range_f const & b)
    {
        return range_f(std::max(a.inf, b.inf), std::min(a.sup, b.sup));
    }

    inline float center(range_f const & r)
    {
        return .5f + r.inf / 2.f + r.sup / 2.f;
    }

    inline float size(range_f const & r)
    {
        return r.sup - r.inf;
    }

}}

#endif /* _RANGE_H_ */
