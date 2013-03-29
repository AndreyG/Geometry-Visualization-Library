#ifndef _PRINTER_IMPL_H_
#define _PRINTER_IMPL_H_

#include "visualization/viewer.h"

namespace visualization
{

struct printer_impl : printer_type
{
    stream_type& corner_stream();
    stream_type& global_stream(point_2f const & pt);

    printer_impl(   boost::function<void (int, int, const char *)>          const & draw_string_corner,
                    boost::function<void (float, float, const char *)>    const & draw_string_global);

private:
    boost::function<void (float, float, const char *)>    draw_string_global_;
    int corner_stream_height_indent_;

    boost::scoped_ptr<stream_type> corner_stream_;
    boost::scoped_ptr<stream_type> global_stream_;
};

}

#endif /*_PRINTER_IMPL_H_*/
