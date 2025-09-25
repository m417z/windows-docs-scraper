# RtmDeleteRouteList function

## Description

The
**RtmDeleteRouteList** function removes all routes from a client-specific route list, then frees any resources allocated to the list.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteListHandle` [in]

Handle to the route list to delete.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

This function also releases the handle to the route list.

## See also

[RtmCreateRouteList](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreateroutelist)

[RtmInsertInRouteList](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminsertinroutelist)