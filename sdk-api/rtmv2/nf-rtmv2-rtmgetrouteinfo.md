# RtmGetRouteInfo function

## Description

The
**RtmGetRouteInfo** function returns information for the specified route.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteHandle` [in]

Handle to the route to find.

### `RouteInfo` [out]

If a pointer must be returned: On input, *RouteInfo* is a pointer to **NULL**. On output, *RouteInfo* receives a pointer to the route; otherwise, *RouteInfo* remains unchanged.

If a pointer does not need to be returned: On input, *RouteInfo* is **NULL**.

### `DestAddress` [out]

If a pointer must be returned: On input, *DestAddress* is a pointer to **NULL**. On output, *DestAddress* receives a pointer to the destination's
[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address) structure; otherwise, *DestAddress* remains unchanged.

If a pointer does not need to be returned: On input, *DestAddress* is **NULL**.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

When the routes are no longer required, release them by calling
[RtmReleaseRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaserouteinfo).

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)

[RtmReleaseRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaserouteinfo)