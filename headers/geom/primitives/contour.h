#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include <vector>

#include "geom/primitives/point.h"
#include "common/range.h"

namespace geom {
namespace structures {

    struct contour_2f
    {
        contour_2f(contour_2f const &)              = delete;
        contour_2f& operator = (contour_2f const &) = delete;

        contour_2f(contour_2f && cnt);
        contour_2f& operator = (contour_2f && cnt);

        typedef std::vector<point_2f>::const_iterator const_iterator;

        const_iterator begin()    const { return pts_.begin(); }
        const_iterator end()      const { return pts_.end();   }

        size_t vertices_num() const { return pts_.size(); }

        point_2f const & operator [] (size_t idx) const { return pts_[idx]; }

    private:
        friend struct contour_builder_type;

        contour_2f(std::vector<point_2f> && pts);

        std::vector<point_2f> pts_;
    };

    typedef common::range_circulator<contour_2f> contour_circulator;

}}

#endif /* _CONTOUR_H_ */
