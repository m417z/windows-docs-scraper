# RtmLockRoute function

## Description

The
**RtmLockRoute** function locks or unlocks a route in the routing table. This protects the route while a client makes the necessary changes to the opaque route pointers owned by the client.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteHandle` [in]

Handle to the route to lock.

### `Exclusive` [in]

Specifies whether to lock or unlock the route in an exclusive (**TRUE**) or shared (**FALSE**) mode.

### `LockRoute` [in]

Specifies whether to lock or unlock the route. Specify **TRUE** to lock the route; specify **FALSE** to unlock it.

### `RoutePointer` [out]

If a pointer must be returned: On input, *RoutePointer* is a pointer to **NULL**. On output, if the client owns the route, *RoutePointer* receives a pointer to the next-hop; otherwise, *RoutePointer* remains unchanged.

If a handle does not need to be returned: On input, *RoutePointer* is **NULL**.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this route. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

Do not call any other RTMv2 functions until the route is unlocked by a call to
**RtmLockRoute** and the *LockRoute* parameter is set to **FALSE**, or a call to
[RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmupdateandunlockroute).

Currently, this function locks the entire destination, not just the route.

Clients can only change the **Neighbour**, **PrefInfo**, **BelongsToViews**, **EntitySpecificInfo**, and **NextHopsList** members of the
[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info) structure.

If any of these values are changed, the client must call
[RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmupdateandunlockroute) to notify the routing table manager of the changes.

## See also

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)

[RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddroutetodest)

[RtmDeleteRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteroutetodest)

[RtmGetRoutePointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetroutepointer)

[RtmHoldDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmholddestination)

[RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmupdateandunlockroute)