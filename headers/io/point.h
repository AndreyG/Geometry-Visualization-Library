#ifndef _POINT_IO_H_
#define _POINT_IO_H_

#include "geom/primitives/point.h"

namespace geom {
namespace structures {

    std::istream & operator >> (std::istream & in, point_2f & pt);
    std::ostream & operator << (std::ostream & out, point_2f const & pt);

}}

#endif /* _POINT_IO_H_ */
