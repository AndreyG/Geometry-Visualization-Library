#include "stdafx.h"

#include "visualization/draw_util.h"

#include "common/range.h"

#include "io/point.h"

using geom::structures::rectangle_type;
using geom::structures::contour_type;
using geom::structures::contour_circulator;

namespace visualization
{
    void draw(drawer_type & drawer, rectangle_type const & rect)
    {
        drawer.draw_line(rect.corner(0, 0), rect.corner(1, 0));
        drawer.draw_line(rect.corner(1, 0), rect.corner(1, 1));
        drawer.draw_line(rect.corner(1, 1), rect.corner(0, 1));
        drawer.draw_line(rect.corner(0, 1), rect.corner(0, 0));
    }

    void draw(drawer_type & drawer, contour_type const & cnt, bool draw_vertices)
    {
        contour_circulator beg(cnt), it = beg;

        do
        {
            point_type pt = *it;
            if (draw_vertices)
                drawer.draw_point(pt, 3);
            ++it;
            drawer.draw_line(segment_type(pt, *it));
        }
        while (it != beg);
    }
}
