#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include <stdexcept>
#include <boost/lexical_cast.hpp>

#include "geom/primitives/point.h"

namespace geom {
namespace structures {

    struct segment_2f
    {
        segment_2f() {}

        segment_2f(point_2f const & beg, point_2f const & end)
            : beg(beg)
            , end(end)
        {}

        point_2f const & operator[] (size_t i) const
        {
            switch (i)
            {
            case 0: return beg;
            case 1: return end;
            default:
                throw std::logic_error("invalid index: " + boost::lexical_cast<std::string>(i));
            }
        }

        point_2f & operator[] (size_t i)
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
        point_2f beg, end;
    };

    inline point_2f const & min(segment_2f const & seg) { return std::min(seg[0], seg[1]); }
    inline point_2f const & max(segment_2f const & seg) { return std::max(seg[0], seg[1]); }

    inline bool operator == (segment_2f const & a, segment_2f const & b)
    {
        return (a[0] == b[0]) && (a[1] == b[1]);
    }

    inline bool operator != (segment_2f const & a, segment_2f const & b)
    {
        return !(a == b);
    }
}}

#endif /* _SEGMENT_H_ */
