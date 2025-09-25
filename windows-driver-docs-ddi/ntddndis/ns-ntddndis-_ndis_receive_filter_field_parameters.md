# _NDIS_RECEIVE_FILTER_FIELD_PARAMETERS structure

## Description

The **NDIS_RECEIVE_FILTER_FIELD_PARAMETERS** structure specifies the filter test criterion for a field
in a network packet header.

NDIS receive filters are used in the following NDIS interfaces:

* [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing). For more information about how to use receive filters in this interface, see [Managing Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-packet-coalescing-receive-filters).
* [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-). For more information about how to use receive filters in this interface, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).
* [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture). For more information about how to use receive filters in this interface, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_FILTER_FIELD_PARAMETERS** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

To indicate the version of the **NDIS_RECEIVE_FILTER_FIELD_PARAMETERS** structure, the driver sets the
**Revision** member to one of the following values:

| Value | Meaning |
| --- | --- |
| **NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_2**<br><br>2 | Added additional members to the **HeaderField** union for NDIS 6.30.<br><br>The driver sets the **Size** member to **NDIS_SIZEOF_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_2**. |
| **NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_1**<br><br>1 | Original version for NDIS 6.20.<br><br>The driver sets the **Size** member to **NDIS_SIZEOF_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_1**. |

### `Flags`

A bitwise OR of flags. The following flags are valid for the
[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter) OID.

| Value | Meaning |
| --- | --- |
| **NDIS_RECEIVE_FILTER_FIELD_MAC_HEADER_VLAN_UNTAGGED_OR_ZERO**<br><br>0x00000001 | If this flag is set, the network adapter must only indicate received packets that pass the following criteria:<br><br>* The packet's media access control (MAC) address matches the specified MAC header field test.<br>* The packet either does not contain a VLAN tag or has a VLAN tag with an ID of zero.<br><br>For more information about this flag, see the Remarks section.<br><br>**Note** If an overlying driver sets a MAC address filter and a VLAN identifier filter with an OID request of [OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter), it does not set this flag in either of the filter fields. In this case, the miniport driver should indicate packets that match both the specified MAC address and the VLAN identifier. That is, the miniport driver should not indicate packets with a matching MAC address that have a zero VLAN identifier or are untagged packets. |

### `FrameHeader`

The type of header in the network data frame.

### `ReceiveFilterTest`

The type of test to perform for the receive filter.

### `HeaderField`

The type of field in a header. The field type (for example,
[NDIS_MAC_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_mac_header_field)) corresponds to the type of header that is specified in the
**FrameHeader** member.

This union contains the following members:

### `HeaderField.MacHeaderField`

The type of field in a MAC header.

### `HeaderField.ArpHeaderField`

The type of field in an Address Resolution Protocol (ARP) header.

### `HeaderField.IPv4HeaderField`

An
[NDIS_IPV4_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_ipv4_header_field) enumeration
value that specifies the type of field in an IP version 4 (IPv4) header.

### `HeaderField.IPv6HeaderField`

An
[NDIS_IPV6_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_ipv6_header_field) enumeration
value that specifies the type of field in an IP version 6 (IPv6) header.

### `HeaderField.UdpHeaderField`

The type of field in a User Datagram Protocol
(UDP) header.

### `_HEADER_FIELD`

### `FieldValue`

The value that the miniport adapter compares to the corresponding header field value in incoming packets. The location of the header field value is determined by the field type that is specified in the **HeaderField** member.

For more information, see the Remarks section.

This union contains the following members:

### `FieldValue.FieldByteValue`

A **UCHAR** value to compare with a field in a network packet.

**Note** If the **MacHeaderField** member specifies an **NdisMacHeaderFieldPacketType** enumeration value, this member contains an [NDIS_MAC_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_mac_packet_type) enumeration value.

### `FieldValue.FieldShortValue`

A **USHORT** value to compare with a field in a network packet.

### `FieldValue.FieldLongValue`

A **ULONG** value to compare with a field in a network packet.

### `FieldValue.FieldLong64Value`

A **ULONG64** value to compare with a field in a network packet.

### `FieldValue.FieldByteArrayValue`

A **UCHAR** array to compare with a field in a network packet.

### `_FIELD_VALUE`

### `ResultValue`

A union that contains a test result value.

If the **ReceiveFilterTest** member is set to **NdisReceiveFilterTestMaskEqual**, the network adapter first calculates a result from the value in the **FieldValue** member and the header field value as specified by the **HeaderField** member. The adapter then compares the calculated result with **ResultValue**.

For more information, see the Remarks section.

This union contains the following members:

### `ResultValue.ResultByteValue`

A **UCHAR** value to compare with a test result.

### `ResultValue.ResultShortValue`

A **USHORT** value to compare with a test result.

### `ResultValue.ResultLongValue`

A **ULONG** value to compare with a test result.

### `ResultValue.ResultLong64Value`

A **ULONG64** value to compare with a test result.

### `ResultValue.ResultByteArrayValue`

A **UCHAR** array to compare with a test result.

### `_RESULT_VALUE`

## Remarks

The **NDIS_RECEIVE_FILTER_FIELD_PARAMETERS** structure specifies the filter test criterion for one field
in a possible array of field tests that can be specified with the
[NDIS_RECEIVE_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_parameters) structure.

The following table describes how the network adapter uses the **ReceiveFilterTest**, **FieldValue**, and **ResultValue** members to perform a filter test on the specified header field value of a received packet.

| **ReceiveFilterTest** value | Filter test performed by network adapter |
| --- | --- |
| NdisReceiveFilterTestEqual | (<*header field value*> == **FieldValue**) |
| NdisReceiveFilterTestMaskEqual | ((<*header field value*> & **FieldValue**) == **ResultValue**) |
| NdisReceiveFilterTestNotEqual | (<*header field value*> != **FieldValue**) |

**Note** All the multibyte field and result values, such as the **FieldShortValue** and **ResultLong64Value** members, must be specified in network byte order (*big-endian*) format.

If the **NDIS_RECEIVE_FILTER_FIELD_MAC_HEADER_VLAN_UNTAGGED_OR_ZERO** flag is not set and there is no VLAN identifier filter that was configured by an OID set request of
[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter), the miniport driver must do one of the following:

* For NDIS 6.20, the miniport driver must return a failed status for the
  OID request of [OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter).
* Starting with NDIS 6.30, if the **NDIS_RECEIVE_FILTER_FIELD_MAC_HEADER_VLAN_UNTAGGED_OR_ZERO** flag is not set and there is no VLAN identifier filter configured by the [OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter) method request, the miniport driver must do either one of the following:

  + The miniport driver must return a failed status for the
    [OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter) method request.
  + The miniport driver must configure the network adapter to inspect and filter the specified MAC address fields. If a VLAN tag is present in the received packet, the network adapter must remove it from the packet data. The miniport driver must put the VLAN tag in an [NDIS_NET_BUFFER_LIST_8021Q_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_8021q_info) that is associated with the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

Starting with NDIS 6.30, if the **NDIS_RECEIVE_FILTER_FIELD_MAC_HEADER_VLAN_UNTAGGED_OR_ZERO** flag is not set and there is a non-zero VLAN identifier filter that was configured by an OID set request of
[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter), the miniport driver must do the following:

* The miniport driver must configure the network adapter to inspect and filter the specified MAC address and VLAN identifier fields.

  If a VLAN tag is present in the received packet, the network adapter must remove it from the packet data. The miniport driver must put the VLAN tag in an [NDIS_NET_BUFFER_LIST_8021Q_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_8021q_info) that is associated with the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## See also

[NDIS_ARP_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_arp_header_field)

[NDIS_FRAME_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_frame_header)

[NDIS_IPV4_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_ipv4_header_field)

[NDIS_IPV6_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_ipv6_header_field)

[NDIS_MAC_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_mac_header_field)

[NDIS_MAC_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_mac_packet_type)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_parameters)

[NDIS_RECEIVE_FILTER_TEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_receive_filter_test)

[NDIS_UDP_HEADER_FIELD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_udp_header_field)

[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter)