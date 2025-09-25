# _NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS structure

## Description

The **NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS** structure specifies the parameters to clear a
receive filter on a network adapter.

NDIS receive filters are used in the following NDIS interfaces:

* [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing). For more information about how to use receive filters in this interface, see [Managing Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-packet-coalescing-receive-filters).
* [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-). For more information about how to use receive filters in this interface, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).
* [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture). For more information about how to use receive filters in this interface, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

To indicate the version of the **NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS** structure, the driver sets the
**Revision** member to one of the following values:

#### NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS_REVISION_1

Original version for NDIS 6.20.

The driver sets the
**Size** member to NDIS_SIZEOF_RECEIVE_FILTER_CLEAR_PARAMETERS_REVISION_1.

### `Flags`

A bitwise OR of flags. This member is reserved for NDIS.

### `QueueId`

A receive queue identifier. This identifier is an
integer between zero and the number of queues that the network adapter supports. A value of NDIS_DEFAULT_RECEIVE_QUEUE_ID specifies
the default receive queue.

**Note** Miniport drivers that support [NDIS packet coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing) or the SR-IOV interface must set the **QueueId** member to NDIS_DEFAULT_RECEIVE_QUEUE_ID.

### `FilterId`

A receive filter identifier. The filter identifier
is an integer from one to the number of receive filters that the network adapter supports. A value of zero is
not valid.

## Remarks

The **NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS** structure is used with OID requests of
[OID_RECEIVE_FILTER_CLEAR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-clear-filter) to specify a filter to clear on a VMQ or SR-IOV VPort receive queue. The filter was
previously set on the queue with the
[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter) OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_RECEIVE_FILTER_CLEAR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-clear-filter)

[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter)