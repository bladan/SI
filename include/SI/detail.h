#pragma once

#include <limits>
#include <ratio>
#include <stdexcept>

namespace SI::detail {
template <template <char, class, typename> class U, char _Exponent = 1,
          typename _Ratio = std::ratio<1>>
constexpr auto generate_unit_type_overflow_check(const uint64_t magnitude) {
  if (magnitude >
      std::numeric_limits<
          typename U<_Exponent, _Ratio, int64_t>::internal_type>::max()) {
    throw std::overflow_error("supplied value too large");
  }
  return U<_Exponent, _Ratio, int64_t>(magnitude);
}

/// @returns the ratio between two ratios
template <
    typename _lhs, typename _rhs,
    typename std::enable_if<_lhs::ratio::num == 1 || _lhs::ratio::den == 1,
                            _lhs>::type * = nullptr>
static constexpr auto ratio_to() {
  typedef std::ratio_divide<_rhs, _lhs> resulting_ratio;
  return resulting_ratio{};
}

template <typename _Tp> struct is_ratio : std::false_type {};

template <intmax_t _Num, intmax_t _Den>
struct is_ratio<std::ratio<_Num, _Den>> : std::true_type {};

} // namespace SI::detail
