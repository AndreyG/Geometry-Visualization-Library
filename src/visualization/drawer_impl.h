#ifndef _DRAWER_IMPL_H_
#define _DRAWER_IMPL_H_

#include <QtOpenGL>

#include "visualization/viewer.h"

namespace visualization
{

struct drawer_impl : drawer_type
{
    void set_color(QColor const & c);
    void draw_line(segment_type const &, float width);
    void draw_line(point_type const &, point_type const &, float width);
    void draw_point(point_type const & pt, float radius);

    drawer_impl()
        : current_color_ (Qt::black)
    {}

    void clear();

    struct point_buffer_t
    {
        std::vector<GLfloat>    points;
        std::vector<GLdouble>   colors;
        float radius;
    };

    struct segment_buffer_t
    {
        std::vector<GLfloat>    segments;
        std::vector<GLdouble>   colors;
        float width;
    };

    std::vector<point_buffer_t>     point_buffers;
    std::vector<segment_buffer_t>   segment_buffers;

private:
    QColor current_color_;
};

}

#endif /*_DRAWER_IMPL_H_*/
