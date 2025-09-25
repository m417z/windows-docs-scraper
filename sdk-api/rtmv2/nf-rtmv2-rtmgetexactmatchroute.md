# RtmGetExactMatchRoute function

## Description

The
**RtmGetExactMatchRoute** function searches the routing table for a route that exactly matches the specified route. The route to search for is indicated by a network address, subnet mask, and other route-matching criteria. If an exact match is found, the route information is returned.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestAddress` [in]

Pointer to the destination network address.

### `MatchingFlags` [in]

Specifies the criteria to use when searching for the route. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_MATCH_FULL** | Match routes with all criteria. |
| **RTM_MATCH_INTERFACE** | Match routes that are on the same interface. |
| **RTM_MATCH_NEIGHBOUR** | Match routes with the same neighbor. |
| **RTM_MATCH_NEXTHOP** | Match routes that have the same next hop. |
| **RTM_MATCH_NONE** | Match none of the criteria; all routes for the destination are returned. |
| **RTM_MATCH_OWNER** | Match routes with the same owner. |
| **RTM_MATCH_PREF** | Match routes that have the same preference. |

### `RouteInfo` [in, out]

On input, *RouteInfo* is a pointer an
[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info) structure that contains the criteria that specifies the route to find.

On output, *RouteInfo* receives the route information for the route that matched the criteria.

### `InterfaceIndex` [in]

If RTM_MATCH_INTERFACE is specified in *MatchingFlags*, *InterfaceIndex* specifies the interface on which the route must be present (that is, the route has a next hop on that interface).

### `TargetViews` [in]

Specifies the views from which to return information. If the client specifies RTM_VIEW_MASK_ANY, destination information is returned from all views; however, no view-specific information is returned.

### `RouteHandle` [out]

If a handle must be returned: On input, *RouteHandle* is a pointer to **NULL**.

On output, *RouteHandle* receives a pointer to the route handle; otherwise, *RouteHandle* remains unchanged.

If a handle does not need to be returned: On input, *RouteHandle* is **NULL**.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_FOUND** | The specified route was not found. |

## Remarks

Consider using
[RtmGetExactMatchDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchdestination) if you have no route-matching criteria specified in the *MatchingFlags* parameter.

The following members of the
[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info) structure that is passed in the *RouteInfo* parameter are used to match a route:

* **Neighbour**
* **NextHopsList**
* **PrefInfo**
* **RouteOwner**

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)

[RtmGetExactMatchDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchdestination)

[RtmGetLessSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetlessspecificdestination)

[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination)

[RtmIsBestRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmisbestroute)