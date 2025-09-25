# _NDIS_RECEIVE_FILTER_INFO_ARRAY structure

## Description

The **NDIS_RECEIVE_FILTER_INFO_ARRAY** structure specifies a list of receive filters that are currently configured on a miniport driver.

NDIS receive filters are used in the following NDIS interfaces:

* [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing). For more information about how to use receive filters in this interface, see [Managing Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-packet-coalescing-receive-filters).
* [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-). For more information about how to use receive filters in this interface, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).
* [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture). For more information about how to use receive filters in this interface, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

## Members

### `Header`

The type, revision, and size of the **NDIS_RECEIVE_FILTER_INFO_ARRAY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_RECEIVE_FILTER_INFO_ARRAY** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SIZEOF_RECEIVE_FILTER_INFO_ARRAY_REVISION_2

Added members for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_RECEIVE_FILTER_INFO_ARRAY_REVISION_2.

#### NDIS_SIZEOF_RECEIVE_FILTER_INFO_ARRAY_REVISION_1

Original version for NDIS 6.20.

Set the **Size** member to NDIS_SIZEOF_RECEIVE_FILTER_INFO_ARRAY_REVISION_1.

### `QueueId`

A receive queue identifier. This identifier is an
integer between zero and the number of queues that the network adapter supports. A value of NDIS_DEFAULT_RECEIVE_QUEUE_ID specifies
the default receive queue.

**Note** Miniport drivers that support [NDIS packet coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing) or SR-IOV interface must set the **QueueId** member to NDIS_DEFAULT_RECEIVE_QUEUE_ID.

### `FirstElementOffset`

The offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_RECEIVE_FILTER_INFO_ARRAY** structure up to the beginning of the first element. Each element in the array is an [NDIS_RECEIVE_FILTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_info) structure.

**Note** If **NumElements** is set to zero, this member is ignored.

### `NumElements`

The number of elements in the array.

### `ElementSize`

The size, in bytes, of each element in the array.

### `Flags`

A bitwise OR of the following flags:

#### NDIS_RECEIVE_FILTER_INFO_ARRAY_VPORT_ID_SPECIFIED

If this flag is set, information is requested about receive filters that are configured on the virtual port (VPort) specified by the **VPortId** member.

**Note** This flag is only valid for the SR-IOV interface.

### `VPortId`

The virtual port (VPort) identifier on which receive filters are being queried. The VPort identifier must be one of the following values:

* The identifier of a VPort that was previously allocated through an OID method request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).
* A value of NDIS_DEFAULT_VPORT_ID that specifies the default VPort on the NIC switch.

A NIC switch is supported by network adapters for the SR-IOV interface. The NIC switch can be configured to have one or more VPorts.

**Note** The **VPortId** member is only valid if the NDIS_RECEIVE_FILTER_INFO_ARRAY_VPORT_ID_SPECIFIED flag is set in **Flags**.

## Remarks

The **NDIS_RECEIVE_FILTER_INFO_ARRAY** structure is used in the
OID request of [OID_RECEIVE_FILTER_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-filters). This OID request enumerates the receive filters on a VMQ or SR-IOV receive queue. Each
element in the array that follows the **NDIS_RECEIVE_FILTER_INFO_ARRAY** structure is an
[NDIS_RECEIVE_FILTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_info) structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_FILTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_info)

[OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport)

[OID_RECEIVE_FILTER_ENUM_FILTERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-filters)