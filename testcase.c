#include "munit.h"
#include "ourlib.h"

static MunitResult test_istrue(const MunitParameter params[], void* data) {
    munit_assert(1 > 0);
    munit_assert(1 != 0);
    munit_assert(2 == 2);
}

static MunitResult test_min(const MunitParameter params[], void* data) {
  munit_assert(1 == _min(1, 2));
  munit_assert(4 == _min(4, 5));

  return MUNIT_OK;
}

static MunitResult test_max(const MunitParameter params[], void* data) {
  munit_assert(2 == _max(1, 2));
  munit_assert(5 == _max(4, 5));

  return MUNIT_OK;
}

static MunitResult test_divide(const MunitParameter params[], void* data) {
  munit_assert(.5 == _divide(1, 2));
  munit_assert(.8 == _divide(4, 5));

  return MUNIT_OK;
}

static MunitResult test_multiply(const MunitParameter params[], void* data) {
  munit_assert(2 == _multiply(1, 2));
  munit_assert(20 == _multiply(4, 5));

  return MUNIT_OK;
}

static MunitResult test_round(const MunitParameter params[], void* data) {
  munit_assert(1 == _round(1.2));
  munit_assert(5 == _round(4.9));

  return MUNIT_OK;
}

static MunitResult test_floor(const MunitParameter params[], void* data) {
  munit_assert(1 == _floor(1.9));
  munit_assert(5 == _floor(5.1));

  return MUNIT_OK;
}

static MunitResult test_ceil(const MunitParameter params[], void* data) {
  munit_assert(1 == _ceil(.2));
  munit_assert(5 == _ceil(4.9));

  return MUNIT_OK;
}

static MunitResult test_exp(const MunitParameter params[], void* data) {
  munit_assert(7.38861124 == _exp(2));
  munit_assert(148.39082203502 == _exp(5));

  return MUNIT_OK;
}

static MunitResult test_pow(const MunitParameter params[], void* data) {
  munit_assert(1 == _pow(1, 2));
  munit_assert(1024 == _pow(4, 5));

  return MUNIT_OK;
}

static MunitResult test_cbrt(const MunitParameter params[], void* data) {
  munit_assert(2 == _cbrt(8));
  munit_assert(3 == _cbrt(27));

  return MUNIT_OK;
}

static MunitResult test_sqrt(const MunitParameter params[], void* data) {
  munit_assert(3 == _sqrt(9));
  munit_assert(8 == _sqrt(64));

  return MUNIT_OK;
}

static MunitResult test_log10(const MunitParameter params[], void* data) {
  munit_assert(1 == _log10(10));
  munit_assert(10 == _log10(100));

  return MUNIT_OK;
}

static MunitResult test_log(const MunitParameter params[], void* data) {
  munit_assert(1 == _log(2.7182));

  return MUNIT_OK;
}

static MunitResult test_div(const MunitParameter params[], void* data) {
  munit_assert(0 == _div(1, 2));
  munit_assert(1 == _div(4, 5));

  return MUNIT_OK;
}

static MunitResult test_abs(const MunitParameter params[], void* data) {
  munit_assert(2 == _abs(-2));
  munit_assert(4 == _abs(4));

  return MUNIT_OK;
}



static MunitTest test_suite_tests[] = {
    { (char*) "This will pass:", test_istrue, MUNIT_TEST_OPTION_NONE, NULL},
    { (char*) "int min():", test_min, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int max():", test_max, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int divide():", test_divide, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int multiply():", test_multiply, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int round():", test_round, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int floor():", test_floor, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int ceil():", test_ceil, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int exp():", test_exp, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int pow():", test_pow, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int cbrt():", test_cbrt, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int sqrt():", test_sqrt, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int log10():", test_log10, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int log():", test_log, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int div():", test_div, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "int abs():", test_abs, MUNIT_TEST_OPTION_NONE, NULL },

    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
  (char*) "",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}
