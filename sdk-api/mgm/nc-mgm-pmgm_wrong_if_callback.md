# PMGM_WRONG_IF_CALLBACK callback function

## Description

The
**PMGM_WRONG_IF_CALLBACK** is a call into a routing protocol to notify the protocol that a packet has been received from the specified source and for the specified group on the wrong interface.

## Parameters

### `dwSourceAddr` [in]

Specifies the source address from which the multicast data was received. Zero indicates that data is received from all sources (a wildcard receiver for a group); otherwise, the value of *dwSourceAddr* is the IP address of the source or source network.

### `dwGroupAddr` [in]

Specifies the multicast group for which the data is destined. Zero indicates that all groups are received (a wildcard receiver); otherwise, the value of *dwGroupAddr* is the IP address of the group.

### `dwIfIndex` [in]

Specifies the interface on which the packet arrived.

### `dwIfNextHopAddr` [in]

Specifies the address of the next hop that corresponds to the index specified by *dwIfIndex*. The *dwIfIndex* and *dwIfNextHopIPAddr* parameters uniquely identify a next hop on point-to-multipoint interfaces. A point-to-multipoint interface is a connection where one interface connects to multiple networks. Examples of point-to-multipoint interfaces include non-broadcast multiple access (NBMA) interfaces and the internal interface on which all dial-up clients connect.

For broadcast interfaces (such as Ethernet interfaces) or point-to-point interfaces, which are identified by only the value of *dwIfIndex*, specify zero.

### `dwHdrSize` [in]

Specifies, in bytes, the size of the buffer pointed to by *pbPacketHdr*.

### `pbPacketHdr` [in]

Pointer to a buffer that contains the IP header of the packet, including the IP options and a fragment of the data. This parameter is used by those protocols that examine the contents of the packet header.

## Return value

RRAS does not expect the application to return any specific value; any value returned is ignored by RRAS.

## Remarks

This callback is not currently available.