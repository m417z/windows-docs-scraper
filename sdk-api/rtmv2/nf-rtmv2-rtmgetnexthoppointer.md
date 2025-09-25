# RtmGetNextHopPointer function

## Description

The
**RtmGetNextHopPointer** function obtains a direct pointer to the specified next hop. The pointer allows the next-hop owner direct read access to the routing table manager's
[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info) structure.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NextHopHandle` [in]

Handle to the next hop.

### `NextHopPointer` [out]

If the client is the owner of the next hop, *NextHopPointer* receives a pointer to the next hop.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this next hop. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

Clients should only use this pointer for read-only access.

When the next hop handle is no longer required, release it by calling
[RtmReleaseNextHopInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthopinfo).

## See also

[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info)

[RtmAddNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddnexthop)

[RtmDeleteNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeletenexthop)

[RtmFindNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmfindnexthop)

[RtmLockNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlocknexthop)