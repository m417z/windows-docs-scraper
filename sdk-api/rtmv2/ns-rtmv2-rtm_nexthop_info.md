# RTM_NEXTHOP_INFO structure

## Description

The
**RTM_NEXTHOP_INFO** structure is used to exchange next-hop information with the routing table manager.

## Members

### `NextHopAddress`

Specifies the network address for this next hop.

### `NextHopOwner`

Handle to the client that owns this next hop.

### `InterfaceIndex`

Specifies the outgoing interface index.

### `State`

Flags that indicates the state of this next hop. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_NEXTHOP_STATE_CREATED** | The next hop has been created. |
| **RTM_NEXTHOP_STATE_DELETED** | The next hop has been deleted. |

### `Flags`

Flags that convey status information for the next hop. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_NEXTHOP_FLAGS_REMOTE** | This next hop points to a remote destination that is not directly reachable. To obtain the complete path, the client must perform a recursive lookup. |
| **RTM_NEXTHOP_FLAGS_DOWN** | This flag is reserved for future use. |

### `EntitySpecificInfo`

Contains information specific to the client that owns this next hop.

### `RemoteNextHop`

Handle to the destination with the indirect next-hop address. This member is only valid when the **Flags** member is set to RTM_NEXTHOP_FLAGS_REMOTE. This cached handle can prevent multiple lookups for this indirect next hop.

## See also

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RtmAddNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmaddnexthop)

[RtmDeleteNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeletenexthop)

[RtmFindNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmfindnexthop)

[RtmGetNextHopInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetnexthopinfo)

[RtmGetNextHopPointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetnexthoppointer)

[RtmLockNextHop](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlocknexthop)

[RtmReleaseNextHopInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthopinfo)