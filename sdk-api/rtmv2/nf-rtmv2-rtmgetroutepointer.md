# RtmGetRoutePointer function

## Description

The
**RtmGetRoutePointer** function obtains a direct pointer to a route that allows the owner of the route read access.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteHandle` [in]

Handle to the route.

### `RoutePointer` [out]

On input, *RoutePointer* is a pointer to **NULL**.

On output, *RoutePointer* receives a pointer to the route.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this route. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

The pointer that was returned points to the public part of the route.

## See also

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)

[RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddroutetodest)

[RtmDeleteRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteroutetodest)

[RtmHoldDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmholddestination)

[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute)

[RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmupdateandunlockroute)