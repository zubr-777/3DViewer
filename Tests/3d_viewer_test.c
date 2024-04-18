#include <check.h>
#include "../3DViewer/parser.h"
#include "../3DViewer/transformation.h"
#include "../3DViewer/validate.h"

void free_mem(shared *model);

//! === PARSE_VERTEXES ===
START_TEST(parser_main_vertexes)
{
  const char *str = "Tests/cube.obj";
  validate(str);
  shared a = {0};
  parser(str, &a); // поменять везде местами

  ck_assert_float_eq_tol(a.p_vertex[0], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[14], -0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 1.000001, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[21], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], -1, 1e-6);
  free_mem(&a);
}
END_TEST

START_TEST(parser_main_polygons)
{

  const char *str = "Tests/cube.obj";
  shared a = {0};
  validate(str);
  parser(str, &a);
  ck_assert_uint_eq(a.p_facet[0], 1);
  ck_assert_uint_eq(a.p_facet[1], 2);
  ck_assert_uint_eq(a.p_facet[2], 2);
  ck_assert_uint_eq(a.p_facet[3], 3);
  ck_assert_uint_eq(a.p_facet[4], 3);
  ck_assert_uint_eq(a.p_facet[5], 1);
  ck_assert_uint_eq(a.p_facet[6], 7);
  ck_assert_uint_eq(a.p_facet[7], 6);
  ck_assert_uint_eq(a.p_facet[8], 6);
  ck_assert_uint_eq(a.p_facet[9], 5);
  ck_assert_uint_eq(a.p_facet[10], 5);
  ck_assert_uint_eq(a.p_facet[11], 7);
  ck_assert_uint_eq(a.p_facet[12], 4);
  ck_assert_uint_eq(a.p_facet[13], 5);
  ck_assert_uint_eq(a.p_facet[14], 5);
  ck_assert_uint_eq(a.p_facet[15], 1);
  ck_assert_uint_eq(a.p_facet[16], 1);
  ck_assert_uint_eq(a.p_facet[17], 4);
  ck_assert_uint_eq(a.p_facet[18], 5);
  ck_assert_uint_eq(a.p_facet[19], 6);
  ck_assert_uint_eq(a.p_facet[20], 6);
  ck_assert_uint_eq(a.p_facet[21], 2);
  ck_assert_uint_eq(a.p_facet[22], 2);
  ck_assert_uint_eq(a.p_facet[23], 5);
  ck_assert_uint_eq(a.p_facet[24], 2);
  ck_assert_uint_eq(a.p_facet[25], 6);
  ck_assert_uint_eq(a.p_facet[26], 6);
  ck_assert_uint_eq(a.p_facet[27], 7);
  ck_assert_uint_eq(a.p_facet[28], 7);
  ck_assert_uint_eq(a.p_facet[29], 2);
  ck_assert_float_eq(a.p_facet[30], 0);
  ck_assert_float_eq(a.p_facet[31], 3);
  ck_assert_float_eq(a.p_facet[32], 3);
  ck_assert_float_eq(a.p_facet[33], 7);
  ck_assert_float_eq(a.p_facet[34], 7);
  ck_assert_float_eq(a.p_facet[35], 0);
  ck_assert_float_eq(a.p_facet[36], 0);
  ck_assert_float_eq(a.p_facet[37], 1);
  ck_assert_float_eq(a.p_facet[38], 1);
  ck_assert_float_eq(a.p_facet[39], 3);
  ck_assert_float_eq(a.p_facet[40], 3);
  ck_assert_float_eq(a.p_facet[41], 0);
  ck_assert_float_eq(a.p_facet[42], 4);
  ck_assert_float_eq(a.p_facet[43], 7);
  ck_assert_float_eq(a.p_facet[44], 7);
  ck_assert_float_eq(a.p_facet[45], 5);
  ck_assert_float_eq(a.p_facet[46], 5);
  ck_assert_float_eq(a.p_facet[47], 4);
  ck_assert_float_eq(a.p_facet[48], 0);
  ck_assert_float_eq(a.p_facet[49], 4);
  ck_assert_float_eq(a.p_facet[50], 4);
  ck_assert_float_eq(a.p_facet[51], 1);
  ck_assert_float_eq(a.p_facet[52], 1);
  ck_assert_float_eq(a.p_facet[53], 0);
  ck_assert_float_eq(a.p_facet[54], 1);
  ck_assert_float_eq(a.p_facet[55], 5);
  ck_assert_float_eq(a.p_facet[56], 5);
  ck_assert_float_eq(a.p_facet[57], 2);
  ck_assert_float_eq(a.p_facet[58], 2);
  ck_assert_float_eq(a.p_facet[59], 1);
  ck_assert_float_eq(a.p_facet[60], 3);
  ck_assert_float_eq(a.p_facet[61], 2);
  ck_assert_float_eq(a.p_facet[62], 2);
  ck_assert_float_eq(a.p_facet[63], 7);
  ck_assert_float_eq(a.p_facet[64], 7);
  ck_assert_float_eq(a.p_facet[65], 3);
  ck_assert_float_eq(a.p_facet[66], 4);
  ck_assert_float_eq(a.p_facet[67], 0);
  ck_assert_float_eq(a.p_facet[68], 0);
  ck_assert_float_eq(a.p_facet[69], 7);
  ck_assert_float_eq(a.p_facet[70], 7);
  ck_assert_float_eq(a.p_facet[71], 4);

  free_mem(&a);
}
END_TEST

START_TEST(parser_main_counts)
{
  const char *str = "Tests/cube.obj";
  shared a = {0};
  validate(str);
  parser(str, &a);
  ck_assert_uint_eq(a.vertex_amount, 8);
  ck_assert_uint_eq(a.facet_amount, 72);
  free_mem(&a);

  // ! === PARSE_SCALE ===
}
END_TEST

START_TEST(parser_main_scale)
{

  const char *str = "Tests/cube.obj";
  shared a = {0};
  validate(str);
  parser(str, &a);
  scaling(&a, 3);

  ck_assert_float_eq_tol(a.p_vertex[0], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[14], -2.999997, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 2.999997, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 3.000003, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[21], -3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 3, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], -3, 1e-6);
  free_mem(&a);

  //! === PARSE_ROTATE_X ===
}
END_TEST

START_TEST(parser_main_rotate_x)
{

  const char *str = "Tests/cube.obj";
  validate(str);
  shared a = {0};
  parser(str, &a);
  rotate(&a, OX_ROTATE, 2 * 3.141592 / 180);

  ck_assert_float_eq_tol(a.p_vertex[0], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 1.034290, 1e-5);
  ck_assert_float_eq_tol(a.p_vertex[14], -0.964490, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 1.034291, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[21], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], -0.964491, 1e-6);

  free_mem(&a);

  //! === PARSE_ROTATE_Y ===
}
END_TEST

START_TEST(parser_main_rotate_y)
{

  const char *str = "Tests/cube.obj";
  validate(str);
  shared a = {0};
  parser(str, &a);
  rotate(&a, OY_ROTATE, 2 * 3.141592 / 180);

  ck_assert_float_eq_tol(a.p_vertex[0], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[14], -0.964490, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 0.964490, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 1.034291, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 0.964491, 1e-5);
  ck_assert_float_eq_tol(a.p_vertex[21], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], -1.034290, 1e-6);
  free_mem(&a);

  // //! === PARSE_ROTATE_Z ===
}
END_TEST

START_TEST(parser_main_rotate_Z)
{

  const char *str = "Tests/cube.obj";
  shared a = {0};
  validate(str);
  parser(str, &a);
  ;
  rotate(&a, OZ_ROTATE, 2 * 3.141592 / 180);

  ck_assert_float_eq_tol(a.p_vertex[0], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], -0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[14], -0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 0.964490, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 1.000001, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[21], -1.034290, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], -1, 1e-5);
  free_mem(&a);

  //! === PARSE_MOVE_X ===
}
END_TEST

START_TEST(parser_main_move_x)
{
  const char *str = "Tests/cube.obj";
  validate(str);
  shared a = {0};
  parser(str, &a);
  move_model(&a, 10, 0, 0);

  ck_assert_float_eq_tol(a.p_vertex[0], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[14], -0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 10.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 1.000001, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[21], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], -1, 1e-6);
  free_mem(&a);

  //! === PARSE_MOVE_Y ===
}
END_TEST

START_TEST(parser_main_move_y)
{

  const char *str = "Tests/cube.obj";
  shared a = {0};
  validate(str);
  parser(str, &a);
  move_model(&a, 0, 10, 0);

  ck_assert_float_eq_tol(a.p_vertex[0], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[14], -0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 1.000001, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[21], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], -1, 1e-6);
  free_mem(&a);

  //! === PARSE_MOVE_Z ===
}
END_TEST

START_TEST(parser_main_move_z)
{

  const char *str = "Tests/cube.obj";
  shared a = {0};
  validate(str);
  parser(str, &a);
  move_model(&a, 0, 0, 10);

  ck_assert_float_eq_tol(a.p_vertex[0], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[1], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[2], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[3], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[4], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[5], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[6], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[7], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[8], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[9], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[10], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[11], 9, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[13], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[14], 9.000001, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[15], 0.999999, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[16], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[17], 11.000001, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[18], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[20], 11, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[21], -1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.p_vertex[23], 9, 1e-6);
  free_mem(&a);

  // ! === MIN_C ===
}
END_TEST

START_TEST(validator)
{
  const char *str = "Tests/cube_first.obj";
  shared a = {0};
  validate(str);
  free_mem(&a);
}
END_TEST

int main(void)
{
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, parser_main_vertexes);
  tcase_add_test(tc1_1, parser_main_scale);
  tcase_add_test(tc1_1, parser_main_polygons);
  tcase_add_test(tc1_1, validator);
  tcase_add_test(tc1_1, parser_main_counts);
  tcase_add_test(tc1_1, parser_main_rotate_x);
  tcase_add_test(tc1_1, parser_main_rotate_y);
  tcase_add_test(tc1_1, parser_main_rotate_Z);
  tcase_add_test(tc1_1, parser_main_move_x);
  tcase_add_test(tc1_1, parser_main_move_y);
  tcase_add_test(tc1_1, parser_main_move_z);
  // tcase_add_test(tc1_1, parser_min_c);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

void free_mem(shared *model)
{
  model->vertex_amount = 0;
  model->facet_amount = 0;

  if (model->name != NULL)
  {
    free(model->name);
    model->name = NULL;
  }

  if (model->p_vertex != NULL)
  {
    free(model->p_vertex);
    model->p_vertex = NULL;
  }

  if (model->p_facet != NULL)
  {
    free(model->p_facet);
    model->p_facet = NULL;
  }
}
