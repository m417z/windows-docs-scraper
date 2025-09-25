# RTM_NEXTHOP_LIST structure

## Description

The
**RTM_NEXTHOP_LIST** structure contains a list of next hops used to determine equal-cost paths in a route.

## Members

### `NumNextHops`

Specifies the number of equal cost next hops in **NextHops**.

### `NextHops`

Array of next-hop handles.

## See also

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)