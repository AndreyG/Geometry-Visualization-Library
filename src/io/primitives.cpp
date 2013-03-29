#include "stdafx.h"

#include "io/point.h"
#include "io/segment.h"
#include "io/range.h"
#include "io/rectangle.h"

namespace geom {
namespace structures {

    namespace
    {
        std::istream & skip_char(std::istream & in, char ch)
        {
            char c;
            while ((in >> c) && (c != ch));
            return in;
        }
    }

    std::istream & operator >> (std::istream & in, point_2f & pt)
    {
        return skip_char(skip_char(skip_char(in, '(') >> pt.x, ',') >> pt.y, ')');
    }

    std::ostream & operator << (std::ostream & out, point_2f const & pt)
    {
        out << "(" << pt.x << ", " << pt.y << ")";
        return out;
    }

    std::ostream & operator << (std::ostream & out, vector_2f const & v)
    {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }

    std::istream & operator >> (std::istream & in, segment_2f & seg)
    {
        return skip_char(skip_char(skip_char(in, '[') >> seg[0], ',') >> seg[1], ']');
    }

    std::ostream & operator << (std::ostream & out, segment_2f const & seg)
    {
        out << "[" << seg[0] << ", " << seg[1] << "]";
        return out;
    }

    std::istream & operator >> (std::istream & in, range_f & r)
    {
        return skip_char(skip_char(skip_char(in, '[') >> r.inf, ',') >> r.sup, ']');
    }

    std::ostream & operator << (std::ostream & out, range_f const & r)
    {
        out << "[" << r.inf << ", " << r.sup << "]";
        return out;
    }

    std::istream & operator >> (std::istream & in, rectangle_2f & rect)
    {
        return skip_char(skip_char(skip_char(in, '(') >> rect.x, ',') >> rect.y, ')');
    }

    std::ostream & operator << (std::ostream & out, rectangle_2f const & rect)
    {
        out << "(" << rect.x << ", " << rect.y << ")";
        return out;
    }

}}
