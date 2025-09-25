# RtmAddRouteToDest function

## Description

The
**RtmAddRouteToDest** function adds a new route to the routing table or updates an existing route in the routing table. If the best route changes, a change notification is generated.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteHandle` [in, out]

If the client has a handle (updating a route): On input, *RouteHandle* is a pointer to the route handle. On output, *RouteHandle* is unchanged.

If the client does not have a handle and a handle must be returned (client is adding or updating a route): On input, *RouteHandle* is a pointer to **NULL**. On output, *RouteHandle* receives a pointer to the route handle. The values in *RouteInfo* are used to identify the route to update.

If a handle does not need to be returned (client is adding or updating a route): On input, *RouteHandle* is **NULL**. The values in *RouteInfo* are used to identify the route to update.

### `DestAddress` [in]

Pointer to the destination network address to which the route is being added or updated.

### `RouteInfo` [in]

Pointer to the route information to add or update.

### `TimeToLive` [in]

Specifies the time, in milliseconds, after which the route is expired. Specify INFINITE to prevent routes from expiring.

### `RouteListHandle` [in]

Handle to a route list to which to move the route. This parameter is optional and can be set to **NULL**.

### `NotifyType` [in]

Set this parameter to **NULL**. This parameter is reserved for future use.

### `NotifyHandle` [in]

Set this parameter to **NULL**. This parameter is reserved for future use.

### `ChangeFlags` [in, out]

On input, *ChangeFlags* is a pointer to an **RTM_ROUTE_CHANGE_FLAGS** data type that indicates whether the routing table manager should add a new route or update an existing one.

On output, *ChangeFlags* is a pointer to an **RTM_ROUTE_CHANGE_FLAGS** data type that receives the flag indicating the type of change that was actually performed, and if the best route was changed. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_ROUTE_CHANGE_FIRST** | Indicates that the routing table manager should not check the **Neighbour** member of the *RouteInfo* parameter when determining if two routes are equal. |
| **RTM_ROUTE_CHANGE_NEW** | Returned by the routing table manager to indicate a new route was created. |
| **RTM_ROUTE_CHANGE_BEST** | Returned by the routing table manager to indicate that the route that was added or updated was the best route, or that because of the change, a new route became the best route. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this route. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |

## Remarks

Two routes are considered equal if the following values are equal:

* The destination network
* The owner of the route
* The neighbor that supplied the route

When a client is updating a route, it is more efficient to pass a handle to the route to update in the *RouteHandle* parameter, because the routing table manager does not have to perform a search for the route in the routing table.

If a handle was returned, release the handle when it is no longer required by calling
[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes).

For sample code using this function, see
[Add and Update Routes Using RtmAddRouteToDest](https://learn.microsoft.com/windows/desktop/RRAS/add-and-update-routes-using-rtmaddroutetodest).

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info)

[RtmDeleteRouteToDest](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteroutetodest)

[RtmGetRoutePointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetroutepointer)

[RtmHoldDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmholddestination)

[RtmLockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockroute)

[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes)

[RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmupdateandunlockroute)