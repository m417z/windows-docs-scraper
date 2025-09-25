# RtmGetEnumRoutes function

## Description

The
**RtmGetEnumRoutes** function retrieves the next set of routes in the specified enumeration.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EnumHandle` [in]

Handle to the route enumeration.

### `NumRoutes` [in, out]

On input, *NumRoutes* is a pointer to a **UINT** value that specifies the maximum number of routes that can be received by *RouteHandles*.

On output, *NumRoutes* receives the actual number of routes received by *RouteHandles*.

### `RouteHandles` [out]

On input, *RouteHandles* is a pointer to an
[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info) structure.

On output, *RouteHandles* receives an array of handles to routes.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The value pointed to by *NumRoutes* is larger than the maximum number of routes a client is allowed to retrieve with one call. Check [RTM_REGN_PROFILE](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_regn_profile) for the maximum number of routes that the client is allowed to retrieve with one call. |
| **ERROR_NO_MORE_ITEMS** | There are no more routes to enumerate. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |

## Remarks

When the routes are no longer required, release them by calling
[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes).

For sample code using this function, see
[Enumerate All Routes](https://learn.microsoft.com/windows/desktop/RRAS/enumerate-all-routes).

## See also

[RtmCreateRouteEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreaterouteenum)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes)