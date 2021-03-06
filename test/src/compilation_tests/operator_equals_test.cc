#include <SI/detail/unit.h>

int operator_equals_test() {
  constexpr SI::detail::unit_t<'X', 1, int64_t, std::ratio<1>> v1{1};
  constexpr SI::detail::unit_t<'X', 1, int64_t, std::kilo> v2{1};

  if (v1 == v2) {
    return 0;
  }
  return 1;
}