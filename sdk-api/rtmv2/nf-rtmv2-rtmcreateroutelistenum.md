# RtmCreateRouteListEnum function

## Description

The
**RtmCreateRouteListEnum** function creates an enumeration of routes on the specified route list.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteListHandle` [in]

Handle to the route list to enumerate that is obtained from a previous call to
[RtmCreateRouteList](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreateroutelist).

### `RtmEnumHandle` [out]

On input, *RtmEnumHandle* is a pointer to **NULL**.

On output, *RtmEnumHandle* receives a pointer to a handle to the enumeration. Use this handle in all subsequent calls to functions that enumerate the list of routes.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |

## Remarks

When the enumeration handle is no longer required, release it by calling
[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle).

For sample code using this function, see
[Use a Client-Specific Route List](https://learn.microsoft.com/windows/desktop/RRAS/use-a-client-specific-route-list).

## See also

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmGetListEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetlistenumroutes)