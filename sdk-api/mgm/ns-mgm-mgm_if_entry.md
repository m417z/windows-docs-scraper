# MGM_IF_ENTRY structure

## Description

The
**MGM_IF_ENTRY** structure describes a router interface. This structure is used in the
[PMGM_CREATION_ALERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_creation_alert_callback). In the context of this callback, the routing protocol must enable or disable multicast forwarding on each interface, notifying the multicast group manager by using the **bIsEnabled** member.

## Members

### `dwIfIndex`

Specifies the index of the interface.

### `dwIfNextHopAddr`

Specifies the address of the next hop that corresponds to the index specified by **dwIfIndex**. The **dwIfIndex** and **dwIfNextHopIPAddr** members uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of **dwIfIndex**, specify zero.

### `bIGMP`

Indicates whether or not IGMP is enabled on this interface. If **bIGMP** is **TRUE**, then IGMP is enabled on this interface. If **bIGMP** is **FALSE**, then IGMP is not enabled on this interface.

### `bIsEnabled`

Indicates whether or not multicast forwarding is enabled on this interface. If **bIsEnabled** is **TRUE**, multicast forwarding is enabled on this interface. If **bIsEnabled** is **FALSE**, multicast forwarding is disabled on this interface.

## See also

[PMGM_CREATION_ALERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_creation_alert_callback)