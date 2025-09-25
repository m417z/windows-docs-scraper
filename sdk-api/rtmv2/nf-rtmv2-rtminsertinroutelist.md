# RtmInsertInRouteList function

## Description

The
**RtmInsertInRouteList** function inserts the specified set of routes into the client's route list. If a route is already in another list, the route is removed from the old list and inserted into the new one.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteListHandle` [in]

Handle to the route list to which to add routes. Specify **NULL** to remove the specified routes from their old lists.

### `NumRoutes` [in]

Specifies the number of routes in *RouteHandles*.

### `RouteHandles` [in]

Pointer to an array of route handles to move from the old list to the new list.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

When the routes are no longer required, release them by calling
[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes).

For sample code using this function, see
[Use a Client-Specific Route List](https://learn.microsoft.com/windows/desktop/RRAS/use-a-client-specific-route-list).

## See also

[RtmCreateRouteList](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreateroutelist)

[RtmDeleteRouteList](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteroutelist)