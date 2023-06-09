#ifndef __UTILS_FIELD_GEN_INCLUDED__
#define __UTILS_FIELD_GEN_INCLUDED__

#include <climits>
#include <cstddef>
#include <cstdint>
#include <type_traits>

template <typename Holder, unsigned BIT_NUM = 0>
struct BitFlag : std::integral_constant<Holder, 1 << BIT_NUM>
{
    static_assert(std::is_same<uint8_t, Holder>::value || std::is_same<uint16_t, Holder>::value ||
                  std::is_same<uint32_t, Holder>::value || std::is_same<uint64_t, Holder>::value);
    static_assert(BIT_NUM < sizeof(Holder) * CHAR_BIT);

    using Next = BitFlag<Holder, BIT_NUM + 1>;
};

#endif
