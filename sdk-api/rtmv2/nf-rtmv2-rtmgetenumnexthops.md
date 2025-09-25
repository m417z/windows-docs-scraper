# RtmGetEnumNextHops function

## Description

The
**RtmGetEnumNextHops** function retrieves the next set of next hops in the specified enumeration.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EnumHandle` [in]

Handle to the next-hop enumeration.

### `NumNextHops` [in, out]

On input, *NumNextHops* is a pointer to a **UINT** value specifying the maximum number of next hops that can be received by *NextHopHandles*.

On output, *NumNextHops* receives the actual number of next hops received by *NextHopHandles*.

### `NextHopHandles` [out]

On input, *NextHopHandles* pointers to an
[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info) structure.

On output, *NextHopHandles* receives an array of handles to next hops.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The value pointed to by *NumRoutes* is larger than the maximum number of routes a client is allowed to retrieve with one call. Check [RTM_REGN_PROFILE](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_regn_profile) for the maximum number of next hops that the client is allowed to retrieve with one call. |
| **ERROR_NO_MORE_ITEMS** | There are no more next hops to enumerate. |

## Remarks

When the next hops are no longer required, release them by calling
[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops).

## See also

[RtmCreateNextHopEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatenexthopenum)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops)