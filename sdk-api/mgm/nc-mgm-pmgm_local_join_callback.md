# PMGM_LOCAL_JOIN_CALLBACK callback function

## Description

The
**PMGM_LOCAL_JOIN_CALLBACK** callback is a call into a routing protocol to notify the protocol that IGMP has detected new receivers for a group on an interface that is currently owned by the routing protocol.

This callback is invoked when the
[MgmAddGroupMembershipEntry](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmaddgroupmembershipentry) function is called by IGMP.

## Parameters

### `dwSourceAddr` [in]

Specifies the source address from which the multicast data was received. Zero indicates that data is received from all sources (a wildcard receiver for a group); otherwise, the value of *dwSourceAddr* is the IP address of the source or source network.

To specify a range of source addresses, the multicast group manager specifies the source network using *dwSourceAddr*, and specifies a subnet mask using *dwSourceMask*.

### `dwSourceMask` [in]

Specifies the subnet mask that corresponds to *dwSourceAddr*. The *dwSourceAddr* and *dwSourceMask* parameters are used together to define a range of sources from which to receive multicast data.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwSourceAddr* (a wildcard receiver).

### `dwGroupAddr` [in]

Specifies the multicast group for which the data is destined. Zero indicates that all groups are received (a wildcard receiver); otherwise the value of *dwGroupAddr* is the IP address of the group.

To specify a range of group addresses, the multicast group manager specifies the group address using *dwGroupAddr*, and specifies a subnet mask using *dwGroupMask*.

### `dwGroupMask` [in]

Specifies the subnet mask that corresponds to *dwGroupAddr*. The *dwGroupAddr* and *dwGroupMask* parameters are used together to define a range of multicast groups.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwGroupAddr* (a wildcard receiver).

### `dwIfIndex` [in]

Specifies the interface on which the multicast data from the source should arrive.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## Remarks

This version of the Multicast Group Manager API supports only wildcard sources (*, g) or specific sources (s, g), not a range of sources. The same restriction applies to groups (that is, no group ranges are permitted).

## See also

[PMGM_LOCAL_LEAVE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/mgm/nc-mgm-pmgm_local_leave_callback)