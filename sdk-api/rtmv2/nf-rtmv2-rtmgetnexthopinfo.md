# RtmGetNextHopInfo function

## Description

The
**RtmGetNextHopInfo** function returns information about the specified next hop.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NextHopHandle` [in]

Handle to the next hop.

### `NextHopInfo` [out]

On input, *NextHopInfo* a pointer to an
[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info) structure.

On output, *NextHopInfo* is filled with the requested next-hop information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

When the next hop handle is no longer required, release it by calling
[RtmDeleteNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeletenexthop).

## See also

[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info)

[RtmReleaseNextHopInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthopinfo)