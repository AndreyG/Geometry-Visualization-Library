#ifndef _SEGMENT_IO_H_
#define _SEGMENT_IO_H_

#include "geom/primitives/segment.h"

namespace geom {
namespace structures {

    std::istream & operator >> (std::istream & in, segment_2f & seg);
    std::ostream & operator << (std::ostream & out, segment_2f const & seg);

}}
#endif /* _SEGMENT_IO_H_ */
