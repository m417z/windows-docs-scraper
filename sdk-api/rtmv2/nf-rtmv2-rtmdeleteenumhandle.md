# RtmDeleteEnumHandle function

## Description

The
**RtmDeleteEnumHandle** function deletes the specified enumeration handle and frees all resources allocated for the enumeration.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EnumHandle` [in]

Handle to be released. Any resources associated with the handle are also freed.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RtmCreateDestEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatedestenum)

[RtmCreateNextHopEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatenexthopenum)

[RtmCreateRouteEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreaterouteenum)

[RtmCreateRouteListEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreateroutelistenum)

[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests)

[RtmGetEnumNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumnexthops)

[RtmGetEnumRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumroutes)

[RtmReleaseDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedests)

[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops)

[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes)