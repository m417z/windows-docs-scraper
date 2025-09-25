# PMGM_RPF_CALLBACK callback function

## Description

The
**PMGM_RPF_CALLBACK** callback is a call into a routing protocol to determine if a given packet was received on the correct interface.

This callback is invoked when a packet from a new source or destined for a new group is received. The multicast group manager invokes this callback to the routing protocol that owns the incoming interface towards the source.

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

### `pdwInIfIndex` [in, out]

On input, a pointer to a **DWORD**-sized memory location that specifies the index of the interface on which data from the source is expected to be received, based on the multicast view of the routing table.

On output, *pdwInIfIndex* points to a **DWORD**-sized memory location that contains the index of the interface on which the protocol expects to receive packets. The interface index may differ on output from the index specified on input.

### `pdwInIfNextHopAddr` [in, out]

On input, *pdwInIfNextHopAddr* specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*.

The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

On output, *pdwInIfNextHopAddr* points to the next hop that corresponds to *pdwInIfIndex*.

### `pdwUpStreamNbr` [in, out]

On input, *pdwUpStreamNbr* points to a **DWORD** value specifying the immediate upstream neighbor towards the source (the source is found in the multicast view of the routing table).

On output, *pdwUpStreamNbr* may have been modified by the protocol. This parameter is for informational purposes only.

### `dwHdrSize` [in]

Specifies, in bytes, the size of the buffer pointed to by *pbPacketHdr*.

### `pbPacketHdr` [in]

Pointer to a buffer that contains the IP header of the packet, including the IP options and a fragment of the data. This parameter is used by those protocols that examine the contents of the packet header.

### `pbRoute` [in, out]

On input, *pbRoute* points to a buffer that contains the route towards the source. The buffer contains an
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure.

On output, *pbRoute* points to a buffer that contains the route used by the protocol to determine the interface towards the source.

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## Remarks

This callback is invoked when an MFE is created. MFEs are created when data from a new multicast source, or destined to a new group, is received.

The multicast group manager invokes this callback to the routing protocol that owns the incoming interface towards the source. The multicast group manager determines the interface by looking up the source of the multicast data in the multicast view of the routing table. This interface is not always the same as the interface on which the data was actually received; this condition occurs if multicast data was received on the wrong interface.

When this callback is invoked, the routing protocol can change the incoming interface if the routing protocol behavior requires it to receive the data for the group from another interface.