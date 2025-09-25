# RtmGetListEnumRoutes function

## Description

The
**RtmGetListEnumRoutes** function enumerates a set of routes in a specified route list.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EnumHandle` [in]

Handle to the route list to enumerate.

### `NumRoutes` [in, out]

On input, *NumRoutes* is a pointer to a **UINT** value that specifies the maximum number of routes that can be received by *RouteHandles*.

On output, *NumRoutes* receives the actual number of routes received by *RouteHandles*.

### `RouteHandles` [out]

On input, *DestInfo* is a pointer to an array of
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structures.

On output, *DestInfo* is filled with the requested destination information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The value pointed to by *NumRoutes* is larger than the maximum number of routes a client is allowed to retrieve with one call. Check [RTM_REGN_PROFILE](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_regn_profile) for the maximum number of routes that the client is allowed to retrieve with one call. |

## Remarks

Call this function repeatedly to retrieve all routes.

There are no more routes to enumerate when the routing table manager returns zero in *NumRoutes*.

For sample code using this function, see
[Use a Client-Specific Route List](https://learn.microsoft.com/windows/desktop/RRAS/use-a-client-specific-route-list).

## See also

[RtmCreateRouteListEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreateroutelistenum)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)