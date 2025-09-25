# RtmDeleteRouteToDest function

## Description

The
**RtmDeleteRouteToDest** function deletes a route from the routing table and updates the best-route information for the corresponding destination, if the best route changed. If the best route changes, a change notification is generated.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteHandle` [in]

Handle to the route to delete.

### `ChangeFlags` [out]

On input, *ChangeFlags* is a pointer to **RTM_ROUTE_CHANGE_FLAGS** data type.

On output, *ChangeFlags* receives RTM_ROUTE_CHANGE_BEST flag if the best route was changed.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this route. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |
| **ERROR_NOT_FOUND** | The specified route was not found. |

## Remarks

The *RouteHandle* should not subsequently be released by a client if the client has already called
**RtmDeleteRouteToDest** using that handle. The
**RtmDeleteRouteToDest** function deletes the route and releases the handle.

## See also

[RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddroutetodest)

[RtmGetRoutePointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetroutepointer)

[RtmHoldDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmholddestination)

[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute)

[RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmupdateandunlockroute)