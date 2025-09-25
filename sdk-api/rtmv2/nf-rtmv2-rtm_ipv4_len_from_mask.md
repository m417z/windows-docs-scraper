# RTM_IPV4_LEN_FROM_MASK macro

## Description

The
**RTM_IPV4_LEN_FROM_MASK** macro converts an IPv4 mask to a generic route length.

## Parameters

### `Len`

Receives the converted length

### `Mask`

Specifies the mask to convert.

## Remarks

For example, if a client supplies the *Mask* 255.255.255.255, the *Len* 24 is returned.

The macro is defined as follows:

```cpp
#include <windows.h>

#define RTM_CHECK_NTH_BIT(Value, N, Len)                           \
        if ((Value) & (1 << (N)))                                  \
        {                                                          \
            (Len) += (N); (Value) <<= (N);                         \
        }

#define RTM_IPV4_LEN_FROM_MASK(Len, Mask)                   \
        {                                                   \
            ULONG _Temp_ = ntohl(Mask);                     \
            (Len) = 0;                                      \
            RTM_CHECK_NTH_BIT(_Temp_, 16, (Len));           \
            RTM_CHECK_NTH_BIT(_Temp_,  8, (Len));           \
            RTM_CHECK_NTH_BIT(_Temp_,  4, (Len));           \
            while (_Temp_)                                  \
            {                                               \
                (Len) +=  1; _Temp_ <<=  1;                 \
            }                                               \
        }                                                    \

```

## See also

[RTM_IPV4_GET_ADDR_AND_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_get_addr_and_len)

[RTM_IPV4_GET_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_get_addr_and_mask)

[RTM_IPV4_MAKE_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_make_net_address)

[RTM_IPV4_MASK_FROM_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_mask_from_len)

[RTM_IPV4_SET_ADDR_AND_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_set_addr_and_len)

[RTM_IPV4_SET_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_set_addr_and_mask)

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)