# RtmHoldDestination function

## Description

The
**RtmHoldDestination** function marks a destination to be put in the hold-down state for a certain amount of time. A hold down only happens if the last route for the destination in any view is deleted.

Routing protocols that use hold-down states continue to advertise the last route until the hold-down expires, even if newer routes arrive in the meantime. The route is advertised as a deleted route. The newer routes are, however, used by the routing protocols for forwarding purposes. New routes are advertised when the hold down expires.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestHandle` [in]

Handle to the destination to mark for holding.

### `TargetViews` [in]

Specifies the views in which to hold the destination.

### `HoldTime` [in]

Specifies how long, in milliseconds, to hold the destination.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The hold time specified was zero. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

All routes in a hold-down state are held for all views for a single, maximum hold-down time, regardless of the *HoldTime* specified.

For sample code using this function, see
[Use the Route Hold-Down State](https://learn.microsoft.com/windows/desktop/RRAS/use-the-route-hold-down-state).

## See also

[RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddroutetodest)

[RtmDeleteRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteroutetodest)

[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute)

[RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmupdateandunlockroute)