# RtmReleaseRouteInfo function

## Description

The
**RtmReleaseRouteInfo** function releases a route structure.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteInfo` [in]

Pointer to the
[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info) structure to release. The route was obtained with a previous call to
[RtmGetRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetrouteinfo).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)

[RtmGetRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetrouteinfo)