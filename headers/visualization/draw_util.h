#include "visualization/viewer.h"

#include "geom/primitives/rectangle.h"
#include "geom/primitives/contour.h"

namespace visualization
{
    void draw(drawer_type & drawer, geom::structures::rectangle_2f    const & rect);
    void draw(drawer_type & drawer, geom::structures::contour_2f      const & cnt, bool draw_vertices = false);
}
