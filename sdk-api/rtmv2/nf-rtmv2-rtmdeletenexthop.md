# RtmDeleteNextHop function

## Description

The
**RtmDeleteNextHop** function deletes a next hop from the next-hop list.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NextHopHandle` [in]

Handle to the next hop to delete. This parameter is optional and can be set to **NULL**; if it is **NULL**, the values in *NextHopInfo* are used to identify the next hop to delete.

### `NextHopInfo` [in]

Pointer to a structure that contains information identifying the next hop to delete. This parameter is optional and can be set to **NULL**; if it is **NULL**, the handle in *NextHopHandle* is used to identify the next hop to delete.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this next hop. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |
| **ERROR_NOT_FOUND** | The specified next hop was not found. |

## Remarks

If a client specifies a *NextHopHandle*, the client should not subsequently release the handle using
[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops).

## See also

[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info)

[RtmAddNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddnexthop)

[RtmFindNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmfindnexthop)

[RtmGetNextHopPointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetnexthoppointer)