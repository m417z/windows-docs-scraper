# RtmCreateRouteList function

## Description

The
**RtmCreateRouteList** function creates a list in which the caller can keep a copy of the routes it owns.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteListHandle` [out]

On input, *RouteListHandle* is a pointer to **NULL**.

On output, *RouteListHandle* receives a pointer to a handle to the new route list.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |

## Remarks

For sample code using this function, see
[Use a Client-Specific Route List](https://learn.microsoft.com/windows/desktop/RRAS/use-a-client-specific-route-list).

## See also

[RtmDeleteRouteList](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteroutelist)

[RtmInsertInRouteList](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminsertinroutelist)