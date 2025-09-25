# RtmUpdateAndUnlockRoute function

## Description

The
**RtmUpdateAndUnlockRoute** function updates the position of the route in the set of routes for a destination, and adjusts the best route information for the destination.

This function is used after a client has locked a route and updated it directly (also known as *in-place updating*).

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteHandle` [in]

Handle to the route to change.

### `TimeToLive` [in]

Specifies the time, in milliseconds, after which the route is expired. Specify INFINITE to prevent routes from expiring.

### `RouteListHandle` [in]

Handle to an optional route list to which to move the route. This parameter is optional and can be set to **NULL**.

### `NotifyType` [in]

Set this parameter to **NULL**. *NotifyType* is reserved for future use.

### `NotifyHandle` [in]

Set this parameter to **NULL**. *NotifyHandle* is reserved for future use.

### `ChangeFlags` [out]

Receives RTM_ROUTE_CHANGE_BEST if the best route was changed.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this route. |

## Remarks

Before calling this function, the client should lock the route using
[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute), which returns a pointer to the route. Then, the client can update the route information using the pointer. Finally, the client should call
**RtmUpdateAndUnlockRoute**. If the function executes successfully, the route is unlocked. If the call failed, the client must unlock the route by calling
[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute) with the *LockRoute* parameter set to **FALSE**.

For sample code using this function, see
[Update a Route In Place Using RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/RRAS/update-a-route-in-place-using-rtmupdateandunlockroute).

## See also

[RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddroutetodest)

[RtmDeleteRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteroutetodest)

[RtmGetRoutePointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetroutepointer)

[RtmHoldDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmholddestination)

[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute)