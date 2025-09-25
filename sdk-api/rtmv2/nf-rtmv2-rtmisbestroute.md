# RtmIsBestRoute function

## Description

The
**RtmIsBestRoute** function returns the set of views in which the specified route is the best route to a destination.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `RouteHandle` [in]

Handle to the route to check.

### `BestInViews` [out]

Receives a pointer to the set of views for which the specified route is the best route.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RtmGetExactMatchDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchdestination)

[RtmGetExactMatchRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchroute)

[RtmGetLessSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetlessspecificdestination)

[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination)