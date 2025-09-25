# _NDIS_RECEIVE_FILTER_PARAMETERS structure

## Description

The **NDIS_RECEIVE_FILTER_PARAMETERS** structure specifies the parameters for an NDIS receive filter.

NDIS receive filters are used in the following NDIS interfaces:

* [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing). For more information on how to use receive filters in this technology, see [Managing Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-packet-coalescing-receive-filters).
* [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-). For more information on how to use receive filters in this technology, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).
* [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture). For more information about how to use receive filters in this interface, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_FILTER_PARAMETERS** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

To indicate the version of the **NDIS_RECEIVE_FILTER_PARAMETERS** structure, the driver sets the
**Revision** member to one of the following values:

#### NDIS_RECEIVE_FILTER_PARAMETERS_REVISION_2

Added the
**VPortId** and **MaxCoalescingDelay** members for NDIS 6.30.

The driver sets the
**Size** member to NDIS_SIZEOF_RECEIVE_FILTER_PARAMETERS_REVISION_2.

#### NDIS_RECEIVE_FILTER_PARAMETERS_REVISION_1

Original version for NDIS 6.20.

The driver sets the
**Size** member to NDIS_SIZEOF_RECEIVE_FILTER_PARAMETERS_REVISION_1.

### `Flags`

A bitwise OR of the following flags.

|Version|Value|Meaning|
|--- |--- |--- |
|NDIS 6.50 and later|**NDIS_RECEIVE_FILTER_PACKET_ENCAPSULATION** 0x00000002|If this flag is set on the receive filter, the network adapter must match this MAC address in the inner Ethernet frame in encapsulated packets.|
NDIS 6.20 through NDIS 6.40|**NDIS_RECEIVE_FILTER_PACKET_ENCAPSULATION_GRE** 0x00000002|If this flag is set on the receive filter, the network adapter must match this MAC address in the inner Ethernet frame in GRE encapsulated packets.|

### `FilterType`

The type of the receive filter.

### `QueueId`

A receive queue identifier. This identifier is an
integer between zero and the number of queues that the network adapter supports. A value of NDIS_DEFAULT_RECEIVE_QUEUE_ID specifies
the default receive queue.

**Note** Miniport drivers that support [NDIS packet coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing) or the SR-IOV interface must set the **QueueId** member to NDIS_DEFAULT_RECEIVE_QUEUE_ID.

### `FilterId`

A receive filter identifier. The filter identifier
is an integer from one to the number of receive filters that the network adapter supports. A value of zero is
invalid.

### `FieldParametersArrayOffset`

The offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_RECEIVE_FILTER_PARAMETERS** structure up to the beginning of the first element. Each element in the array is an [NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

**Note** If **FieldParametersArrayNumElements** is set to zero, this member is ignored.

### `FieldParametersArrayNumElements`

The number of elements in the array.

### `FieldParametersArrayElementSize`

The size, in bytes, of each element in the array.

### `RequestedFilterIdBitCount`

The number of bits in a filter identifier. The miniport driver uses
this number of bits for the filter identifier in the
**NetBufferListFilteringInfo** out-of-band (OOB) data in
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. If this member is zero, a miniport driver must not specify the filter identifier
in the OOB
**NetBufferListFilteringInfo** data.

Starting with NDIS 6.20, this member must be set to zero.

### `MaxCoalescingDelay`

The maximum time, in milliseconds, that the first packet that matches this receive filter is saved within the hardware coalescing buffer on the network adapter.

As soon as the first packet that matches the filter is received, the network adapter coalesces the packet. The adapter also starts a hardware timer whose expiration time is set to the value of the **MaxCoalescingDelay** member. Additional packets that match the same filter must be coalesced by the adapter without resetting and restarting the hardware timer.

When the hardware timer expires, the adapter must generate a receive interrupt to signal the host about coalesced packets that match the receive filter.

**Note** Miniport drivers that do not support [NDIS packet coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing) must ignore this member.

### `VPortId`

The VPort identifier on which the receive filter is to be configured. A value of NDIS_DEFAULT_VPORT_ID specifies the default VPort that is attached to the PCI Express (PCIe) physical function (PF) of the network adapter.

**Note** This member is valid only for the SR-IOV interface.

## Remarks

The **NDIS_RECEIVE_FILTER_PARAMETERS** structure is used with OID requests of
[OID_RECEIVE_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-parameters)
and
[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter). These OID
requests specify the configuration parameters of a filter. A filter specification can include tests for
multiple fields in a network packet.

The
**FieldParametersArrayOffset**,
**FieldParametersArrayNumElements**, and
**FieldParametersArrayElementSize** members of the **NDIS_RECEIVE_FILTER_PARAMETERS** structure define an
array of
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structures. Each **NDIS_RECEIVE_FILTER_FIELD_PARAMETERS**
structure in the array sets the filter test criterion for one field in a network header.

The network adapter combines the results from all the field tests with a logical AND operation.
That is, if any field test that is included in the array of [NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)
structures fails, the network packet does not meet the specified filter criterion.

When a network adapter tests a received packet against these filter criteria, it must ignore all
the fields in the packet where no test criterion is specified.

If the packet meets the filter criterion, the network adapter must do one of the following:

* If the network adapter supports NDIS receive packet coalescing, the adapter must coalesce the packet that matches the filter. The adapter must also coalesce received packets that match the same or different receive filters. The adapter must withhold on generating the receive interrupt until another hardware event occurs, such as the following:
  + The expiration of a hardware timer whose expiration time is set to the value of the **MaxCoalescingDelay** member.
  + The available space within the hardware coalescing buffer reaches an adapter-specific low-water mark.

  For more information, see [Handling Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/handling-packet-coalescing-receive-filters).
* If the network adapter supports the SR-IOV interface, the adapter should forward the packet to the receive queue of a default or nondefault VPort. The receive queue is specified by the **QueueId** member and the VPort is specified by the **VPortId** member.

  **Note** Starting with Windows Server 2012, the SR-IOV interface supports only the default receive queue on both default and nondefault VPorts. The default receive queue is specified by setting the **QueueId** member to NDIS_DEFAULT_RECEIVE_QUEUE_ID.
* If the network adapter supports the VMQ interface, the adapter should forward the packet to the receive queue specified by the **QueueId** member.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[OID_RECEIVE_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-parameters)

[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter)