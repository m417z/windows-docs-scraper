# RTM_IPV4_MASK_FROM_LEN macro

## Description

The
**RTM_IPV4_MASK_FROM_LEN** macro converts a generic route length to an IPv4 mask.

## Parameters

### `Len`

Specifies the generic length to convert.

## Remarks

For example, if a client supplies the *Len* 24, the mask 255.255.255.255 is returned.

The macro is defined as follows:

```cpp
#include <windows.h>

#define RTM_IPV4_MASK_FROM_LEN(Len)                         \
        ((Len) ? htonl(~0 << (32 - (Len))): 0);             \

```

## See also

[RTM_IPV4_GET_ADDR_AND_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_get_addr_and_len)

[RTM_IPV4_GET_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_get_addr_and_mask)

[RTM_IPV4_LEN_FROM_MASK](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_len_from_mask)

[RTM_IPV4_MAKE_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_make_net_address)

[RTM_IPV4_SET_ADDR_AND_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_set_addr_and_len)

[RTM_IPV4_SET_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_set_addr_and_mask)

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)