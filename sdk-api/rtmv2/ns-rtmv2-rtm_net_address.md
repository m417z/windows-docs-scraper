# RTM_NET_ADDRESS structure

## Description

The [RTM_NET_ADDRESS](https://learn.microsoft.com/windows/win32/api/rtmv2/ns-rtmv2-rtm_net_address) structure is used to communicate address information to the routing table manager for any address family. The address family must use only with contiguous address masks that are less than 8 bytes.

## Members

### `AddressFamily`

Specifies the type of network address for this address (such as IPv4).

### `NumBits`

Specifies the number of bits in the network part of the **AddrBits** bit array (for example, 192.168.0.0 has 8 bits).

### `AddrBits`

Specifies an array of bits that form the address prefix.

## Remarks

If the client specifies an address and a mask length that do not correspond to each other, inconsistent results are returned by the routing table manager. For example, if a client specifies an address as 10.10.10.10 and a length as 24 when calling
[RTM_IPV4_SET_ADDR_AND_LEN](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_ipv4_set_addr_and_len), the routing table manager may return an incorrect *NetAddress*.

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info)

[RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddroutetodest)

[RtmCreateDestEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatedestenum)

[RtmCreateNextHopEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatenexthopenum)

[RtmCreateRouteEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreaterouteenum)

[RtmGetExactMatchDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchdestination)

[RtmGetExactMatchRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchroute)

[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination)

[RtmGetRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetrouteinfo)