# RtmCreateRouteEnum function

## Description

The
**RtmCreateRouteEnum** function creates an enumeration of the routes for a particular destination or range of destinations in the routing table. A client can enumerate routes for one or more views, or for all views.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestHandle` [in]

Handle to the destination for which to enumerate routes. This parameter is optional, and can be set to **NULL**; specifying **NULL** enumerates all routes for all destinations. Specify **NULL** if *EnumFlags* contains RTM_ENUM_START.

### `TargetViews` [in]

Specifies the set of views to use when creating the enumeration. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_VIEW_MASK_ANY** | Return destinations from all views. This is the default value. |
| **RTM_VIEW_MASK_UCAST** | Return destinations from the unicast view. |
| **RTM_VIEW_MASK_MCAST** | Return destinations from the multicast view. |

### `EnumFlags` [in]

Specifies which routes to include in the enumeration. Two sets of flags are used; use one flag from each set (such as RTM_ENUM_ALL_ROUTES and RTM_ENUM_START).

| Constant | Meaning |
| --- | --- |
| **RTM_ENUM_ALL_ROUTES** | Return all routes. |
| **RTM_ENUM_OWN_ROUTES** | Return only those routes that the client owns. |

| Constant | Meaning |
| --- | --- |
| **RTM_ENUM_NEXT** | Enumerate routes starting at the specified address/mask length (such as 10/8). The enumeration continues to the end of the routing table. |
| **RTM_ENUM_RANGE** | Enumerate routes in the specified range specified by the address/mask length (such as 10/8). |
| **RTM_ENUM_START** | Enumerate routes starting at 0/0. Specify **NULL** for *NetAddress*. |

### `StartDest` [in]

Pointer to an
[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address) structure that contains the starting address of the enumeration. This parameter is ignored if *EnumFlags* contains RTM_ENUM_START.

### `MatchingFlags` [in]

Specifies the elements of the route to match. Only routes that match the criteria specified in *CriteriaRoute* and *CriteriaInterface* are returned, unless otherwise noted. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_MATCH_FULL** | Match routes with all criteria. |
| **RTM_MATCH_INTERFACE** | Match routes that are on the same interface. The client can specify **NULL** for *CriteriaRoute*. |
| **RTM_MATCH_NEIGHBOUR** | Match routes with the same neighbor. |
| **RTM_MATCH_NEXTHOP** | Match routes that have the same next hop. |
| **RTM_MATCH_NONE** | Match none of the criteria; all routes for the destination are returned. The *CriteriaRoute* parameter is ignored if this flag is set. |
| **RTM_MATCH_OWNER** | Match routes with same owner. |
| **RTM_MATCH_PREF** | Match routes that have the same preference. |

### `CriteriaRoute` [in]

Specifies which routes to enumerate. This parameter is optional and can be set to **NULL** if *MatchingFlags* contains RTM_MATCH_INTERFACE or RTM_MATCH_NONE.

### `CriteriaInterface` [in]

Pointer to a **ULONG** that specifies on which interfaces routes should be located. This parameter is ignored unless *MatchingFlags* contains RTM_MATCH_INTERFACE.

### `RtmEnumHandle` [out]

On input, *RtmEnumHandle* is a pointer to **NULL**.

On output, *RtmEnumHandle* receives a pointer to a handle to the enumeration. Use this handle in all subsequent calls to
[RtmGetEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumroutes),
[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes), and
[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |
| **ERROR_NOT_SUPPORTED** | One or more of the specified views is not supported. |

## Remarks

If *EnumFlags* contains RTM_ENUM_RANGE, use *NetAddress* to specify the range of the routing table to enumerate. For example, if a client sets *NetAddress* to 10/8, destinations in the range 10.0.0.0/8 to 10.255.255.255/32 are returned.

When the enumeration handle is no longer required, release it by calling
[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle).

For sample code using this function, see
[Enumerate All Routes](https://learn.microsoft.com/windows/desktop/RRAS/enumerate-all-routes).

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmGetEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumroutes)

[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes)