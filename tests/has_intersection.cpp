#include <gtest/gtest.h>

#include <cg/operations/has_intersection/segment_segment.h>
#include <cg/operations/has_intersection/triangle_segment.h>

TEST(has_intersection, segment_segment)
{
   using cg::point_2;
   using cg::segment_2;

   segment_2 s[] =
   {
      segment_2(point_2(0, 0), point_2(2, 2)),
      segment_2(point_2(1, 0), point_2(0, 1)),
      segment_2(point_2(0, 0), point_2(2, 0)),
      segment_2(point_2(0, 0), point_2(2, -1))
   };

   EXPECT_TRUE(cg::has_intersection(s[0], s[1]));
   EXPECT_TRUE(cg::has_intersection(s[1], s[2]));
   EXPECT_TRUE(cg::has_intersection(s[0], s[2]));

   EXPECT_FALSE(cg::has_intersection(s[1], s[3]));
}

TEST(has_intersection, triangle_segment)
{
   using cg::point_2;
   using cg::segment_2;

   cg::triangle_2 t(point_2(0, 0), point_2(1, 1), point_2(2, 0));

   EXPECT_TRUE(cg::has_intersection(t, segment_2(point_2(0, 0), point_2(-1, -1))));

   EXPECT_TRUE(cg::has_intersection(t, segment_2(point_2(0, 1), point_2(2, 1))));
   EXPECT_FALSE(cg::has_intersection(t, segment_2(point_2(0, 2), point_2(2, 2))));
}
