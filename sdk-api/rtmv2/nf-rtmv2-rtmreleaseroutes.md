# RtmReleaseRoutes function

## Description

The
**RtmReleaseRoutes** function releases the route handles.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NumRoutes` [in]

Specifies the number of routes in *RouteHandles*.

### `RouteHandles` [in]

Pointer to an array of route handles to release. The handles were obtained with a previous call to
[RtmGetEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumroutes).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RtmCreateRouteEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreaterouteenum)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmGetEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumroutes)