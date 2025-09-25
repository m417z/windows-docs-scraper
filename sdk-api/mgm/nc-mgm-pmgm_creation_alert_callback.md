# PMGM_CREATION_ALERT_CALLBACK callback function

## Description

The
**PMGM_CREATION_ALERT_CALLBACK** callback is a call into a routing protocol. This call determines the subset of interfaces owned by the routing protocol on which a multicast packet from a new source should be forwarded.

When a packet sent from a new source, or destined for a new group, arrives on an interface, the multicast group manager creates a new MFE. The multicast group manager then invokes this callback to those routing protocols that have outgoing interfaces in this new MFE. A routing protocol can choose to disable the forwarding of data from the source to the group on specific interfaces.

## Parameters

### `dwSourceAddr` [in]

Specifies the source address from which the multicast data was received. Zero indicates that data is received from all sources (a wildcard receiver for a group); otherwise, the value of *dwSourceAddr* is the IP address of the source or source network.

To specify a range of source addresses, the multicast group manager specifies the source network using *dwSourceAddr*, and specifies a subnet mask using *dwSourceMask*.

### `dwSourceMask` [in]

Specifies the subnet mask that corresponds to *dwSourceAddr*. The *dwSourceAddr* and *dwSourceMask* parameters are used together to define a range of sources from which to receive multicast data.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwSourceAddr* (a wildcard receiver).

### `dwGroupAddr` [in]

Specifies the multicast group for which the data is destined. Zero indicates that all groups are received (a wildcard receiver); otherwise, the value of *dwGroupAddr* is the IP address of the group.

To specify a range of group addresses, the multicast group manager specifies the group address using *dwGroupAddr*, and specifies a subnet mask using *dwGroupMask*.

### `dwGroupMask` [in]

Specifies the subnet mask that corresponds to *dwGroupAddr*. The *dwGroupAddr* and *dwGroupMask* parameters are used together to define a range of multicast groups.

The multicast group manager specifies zero for this parameter if it also specified zero for *dwGroupAddr* (a wildcard receiver).

### `dwInIfIndex` [in]

Specifies the interface on which the multicast data from the source should arrive.

### `dwInIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

### `dwIfCount` [in]

Specifies the number of interfaces in the buffer pointed to by *pmieOutIfList*.

### `pmieOutIfList` [in, out]

On input, a pointer to a buffer that contains the set of interfaces owned by the protocol on which data will be forwarded.

On output, the client can set the **bIsEnabled** member of the corresponding
[MGM_IF_ENTRY](https://learn.microsoft.com/windows/desktop/api/mgm/ns-mgm-mgm_if_entry) structure to **FALSE** to prevent forwarding on any of its interfaces. A client may not be required to prevent forwarding; such a client would accept the default value of **bIsEnabled**.

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## See also

[MGM_IF_ENTRY](https://learn.microsoft.com/windows/desktop/api/mgm/ns-mgm-mgm_if_entry)