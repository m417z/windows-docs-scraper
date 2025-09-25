# RtmLockNextHop function

## Description

The
**RtmLockNextHop** function locks or unlocks a next hop. This function should be called by the next hop's owner to lock the next hop before making changes to the next hop. A pointer to the next hop is returned.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NextHopHandle` [in]

Handle to the next hop to lock or unlock.

### `Exclusive` [in]

Specifies whether to lock or unlock the next hop in an exclusive (**TRUE**) or shared (**FALSE**) mode.

### `LockNextHop` [in]

Specifies whether to lock or unlock the next hop. Specify **TRUE** to lock the next hop; specify **FALSE** to unlock it.

### `NextHopPointer` [out]

On input, *NextHopPointer* is a pointer to **NULL**.

On output, if the client owns the next hop, *NextHopPointer* receives a pointer to the next-hop; otherwise, *NextHopPointer* remains unchanged.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this next hop. |
| **ERROR_NOT_FOUND** | The specified next hop was not found. |

## Remarks

Clients cannot change the **NextHopAddress** and **InterfaceIndex** members of the [RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info) structure; these values are used to uniquely identify a next hop.

## See also

[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info)

[RtmAddNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddnexthop)

[RtmDeleteNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeletenexthop)

[RtmFindNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmfindnexthop)

[RtmGetNextHopPointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetnexthoppointer)