# RTM_ROUTE_INFO structure

## Description

The
**RTM_ROUTE_INFO** structure is used to exchange route information with the routing table manager. Do not change the read-only information.

## Members

### `DestHandle`

Handle to the destination that owns the route.

### `RouteOwner`

Handle to the client that owns this route.

### `Neighbour`

Handle to the neighbor that informed the routing table manager of this route. This member is **NULL** for a link-state protocol.

### `State`

Flags the specify the state of this route. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_ROUTE_STATE_CREATED** | Route has been created. |
| **RTM_ROUTE_STATE_DELETING** | Route is being deleted. |
| **RTM_ROUTE_STATE_DELETED** | Route has been deleted. |

### `Flags1`

Flags used for compatibility with RTMv1.

### `Flags`

Flags used to specify information about the route. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_ROUTE_FLAGS_ANY_BCAST** | The route is one of the following broadcast types: RTM_ROUTE_FLAGS_LIMITED_BC, RTM_ROUTE_FLAGS_ONES_NETBC, RTM_ROUTE_FLAGS_ONES_SUBNET_BC, RTM_ROUTE_FLAGS_ZEROS_NETBC, RTM_ROUTE_FLAGS_ZEROS_SUBNETBC |
| **RTM_ROUTE_FLAGS_ANY_MCAST** | The route is one of the following multicast types: RTM_ROUTE_FLAGS_MCAST, RTM_ROUTE_FLAGS_LOCAL_MCAST |
| **RTM_ROUTE_FLAGS_ANY_UNICAST** | The route is one of the following unicast types: RTM_ROUTE_FLAGS_LOCAL, RTM_ROUTE_FLAGS_REMOTE, RTM_ROUTE_FLAGS_MYSELF |
| **RTM_ROUTE_FLAGS_LIMITED_BC** | Indicates that this route is a limited broadcast address. Packets to this destination should not be forwarded. |
| **RTM_ROUTE_FLAGS_LOCAL** | Indicates a destination is on a directly reachable network. |
| **RTM_ROUTE_FLAGS_LOCAL_MCAST** | Indicates that this route is a route to a local multicast address. |
| **RTM_ROUTE_FLAGS_MCAST** | Indicates that this route is a route to a multicast address. |
| **RTM_ROUTE_FLAGS_MYSELF** | Indicates the destination is one of the router's addresses. |
| **RTM_ROUTE_FLAGS_NET_BCAST** | Flag grouping that contains: RTM_ROUTE_FLAGS_ONES_NETBC, RTM_ROUTE_FLAGS_ZEROS_NETBC |
| **RTM_ROUTE_FLAGS_ONES_NETBC** | Indicates that the destination matches an interface's *all-ones* broadcast address. If broadcast forwarding is enabled, packets should be received and resent out all appropriate interfaces. |
| **RTM_ROUTE_FLAGS_ONES_SUBNETBC** | Indicates that the destination matches an interface's all-ones subnet broadcast address. If subnet broadcast forwarding is enabled, packets should be received and resent out all appropriate interfaces. |
| **RTM_ROUTE_FLAGS_REMOTE** | Indicates that the destination is not on a directly reachable network. |
| **RTM_ROUTE_FLAGS_ZEROS_SUBNETBC** | Indicates that the destination matches an interface's *all-zeros* subnet broadcast address. If subnet broadcast forwarding is enabled, packets should be received and resent out all appropriate interfaces. |
| **RTM_ROUTE_FLAGS_ZEROS_NETBC** | Indicates that the destination matches an interface's all-zeros broadcast address. If broadcast forwarding is enabled, packets should be received and resent out all appropriate interfaces. |

### `PrefInfo`

Specifies the preference and metric information for this route.

### `BelongsToViews`

Specifies the views in which this route is included.

### `EntitySpecificInfo`

Contains the client-specific information for the client that owns this route.

### `NextHopsList`

Specifies a list of equal-cost next hops.

## See also

[RTM_NEXTHOP_LIST](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_list)

[RTM_PREF_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_pref_info)

[RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddroutetodest)

[RtmCreateRouteEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreaterouteenum)

[RtmGetExactMatchRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchroute)

[RtmGetRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetrouteinfo)

[RtmGetRoutePointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetroutepointer)

[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute)

[RtmReleaseRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaserouteinfo)