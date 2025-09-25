# RtmFindNextHop function

## Description

The
**RtmFindNextHop** function finds a specific next hop in a client's next-hop list.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NextHopInfo` [in]

Pointer to an
[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info) structure that contains information identifying the next hop to find. Use the **NextHopAddress** and **InterfaceIndex** members to identify the next hop to find.

### `NextHopHandle` [out]

If a handle must be returned: On input, *NextHopPointer* is a pointer to **NULL**. On output, if the client owns the next hop, *NextHopPointer* receives a pointer to the next-hop handle; otherwise, *NextHopPointer* remains unchanged.

If a handle does not need to be returned: On input, *NextHopPointer* is **NULL**.

### `NextHopPointer` [out]

If a pointer must be returned: On input, *NextHopPointer* is a pointer to **NULL**. On output, if the client owns the next hop, *NextHopPointer* receives a pointer to the next-hop; otherwise, *NextHopPointer* remains unchanged.

If a pointer does not need to be returned: On input, *NextHopPointer* is **NULL**.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this next hop. |
| **ERROR_NOT_FOUND** | The specified next hop was not found. |

## Remarks

The *NextHopPointer* is valid as long as the client has not released *NextHopHandle*.

## See also

[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info)

[RtmAddNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddnexthop)

[RtmDeleteNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeletenexthop)

[RtmGetNextHopPointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetnexthoppointer)

[RtmLockNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlocknexthop)