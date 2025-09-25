# RTM_IPV4_SET_ADDR_AND_MASK macro

## Description

The
**RTM_IPV4_SET_ADDR_AND_MASK** macro converts an IPv4 address and mask to a generic
[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address) structure.

## Parameters

### `NetAddress`

Receives the converted address structure.

### `Addr`

Specifies the IPv4 address to convert.

### `Mask`

Specifies the IPv4 mask to convert.

## Remarks

For example, if a client supplies the *Addr* 10.10.10.0 and the *Mask* 255.255.255.255, the *NetAddress* 10.10.10/24 is returned.

The macro is defined as follows:

```cpp
#include <windows.h>

#define RTM_IPV4_SET_ADDR_AND_MASK(NetAddress, Addr, Mask)  \
        (NetAddress)->AddressFamily = AF_INET;              \
        (* (ULONG *) ((NetAddress)->AddrBits)) = (Addr);    \
        RTM_IPV4_LEN_FROM_MASK((NetAddress)->NumBits, Mask)

```

## See also

[RTM_IPV4_GET_ADDR_AND_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_get_addr_and_len)

[RTM_IPV4_GET_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_get_addr_and_mask)

[RTM_IPV4_LEN_FROM_MASK](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_len_from_mask)

[RTM_IPV4_MAKE_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_make_net_address)

[RTM_IPV4_MASK_FROM_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_mask_from_len)

[RTM_IPV4_SET_ADDR_AND_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_set_addr_and_len)

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)