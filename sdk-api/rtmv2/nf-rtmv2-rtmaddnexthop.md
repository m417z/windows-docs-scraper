# RtmAddNextHop function

## Description

The
**RtmAddNextHop** function adds a new next-hop entry or updates an existing next-hop entry to a client's next-hop list. If a next hop already exists, the routing table manager returns a handle to the next hop. This handle can then be used to specify a next hop to a destination when adding or updating a route.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NextHopInfo` [in]

Pointer to a structure that contains information identifying the next hop to add or update. The **NextHopOwner** and **State** members are ignored; these members are set by the routing table manager. The **Flags** member can be one of the following values.

| Flag | Meaning |
| --- | --- |
| **RTM_NEXTHOP_FLAGS_REMOTE** | This next hop points to a remote destination that is not directly reachable. To obtain the complete path, the client must perform a recursive lookup. |
| **RTM_NEXTHOP_FLAGS_DOWN** | This flag is reserved for future use. |

### `NextHopHandle` [in, out]

If the client has a handle (client is updating a next hop): On input, *NextHopHandle* is a pointer to the next-hop handle. On output, *NextHopHandle* is unchanged.

If the client does not have a handle and a handle must be returned (client is adding or updating a next hop): On input, *NextHopHandle* is a pointer to **NULL**. On output, *NextHopHandle* receives a pointer to the next-hop handle. The values in *NextHopInfo* are used to identify the next hop to update.

If a handle does not need to be returned (client is adding or updating a next hop): On input, *NextHopHandle* is **NULL**. The values in *NextHopInfo* are used to identify the next hop to update.

### `ChangeFlags` [out]

On input, *ChangeFlags* is a pointer to an **RTM_NEXTHOP_CHANGE_FLAGS** data type.

On output, *ChangeFlags* receives a flag indicating whether a next hop was added or updated. If *ChangeFlags* is zero, a next hop was updated; if *ChangeFlags* is **RTM_NEXTHOP_CHANGE_NEW**, a next hop was added.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this next hop. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |

## Remarks

If *NextHopHandle* points to a non-**NULL** handle, the next hop specified by the handle is updated. Otherwise, a search is made for the address specified by *NextHopInfo*. If a next hop is found, it is updated. If no match is found, a new next hop is added.

If a handle was returned, release the handle when it is no longer required by calling
[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops).

## See also

[Next Hop Flags](https://learn.microsoft.com/windows/desktop/RRAS/next-hop-flags)

[RTM_NEXTHOP_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_nexthop_info)

[RtmDeleteNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeletenexthop)

[RtmFindNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmfindnexthop)

[RtmGetNextHopPointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetnexthoppointer)

[RtmLockNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlocknexthop)

[RtmReleaseNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthops)