# _NDIS_RECEIVE_QUEUE_INFO structure

## Description

The **NDIS_RECEIVE_QUEUE_INFO** structure contains information about a receive queue on a network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_RECEIVE_QUEUE_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_RECEIVE_QUEUE_INFO** structure, the driver must set the **Revision** member of **Header** to one of the following values:

#### NDIS_RECEIVE_QUEUE_INFO_REVISION_2

Added additional members for NDIS 6.30.

**Note** Revision 2 of this structure is supported only on Windows Server 2012 and later versions of Windows Server.

Set the **Size** member to **NDIS_SIZEOF_RECEIVE_QUEUE_INFO_REVISION_2**.

#### NDIS_RECEIVE_QUEUE_INFO_REVISION_1

Original version for NDIS 6.20.

Set the **Size** member to **NDIS_SIZEOF_RECEIVE_QUEUE_INFO_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `QueueType`

An [NDIS_RECEIVE_QUEUE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_receive_queue_type) enumeration
value that specifies the type of the receive queue.

### `QueueId`

An **NDIS_RECEIVE_QUEUE_ID** type value that contains a receive queue identifier. This identifier is an
integer value between zero and the number of queues that the network adapter supports. A value of **NDIS_DEFAULT_RECEIVE_QUEUE_ID** specifies
the default receive queue.

### `QueueGroupId`

This member is reserved for NDIS.

### `QueueState`

An [NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_receive_queue_operational_state) enumeration value that specifies the operational state of the
receive queue.

### `ProcessorAffinity`

A **GROUP_AFFINITY** bitmap that specifies the CPU that the queue has affinity with. For example,
setting bit 0 indicates that CPU 0 is used, setting bit 1 indicates that CPU 1 is used, and so on. Because a VM queue is associated with one CPU, all receive indications for the queue are handled on that processor.

### `NumSuggestedReceiveBuffers`

A **ULONG** value that contains a suggested value for the number of receive buffers that the network adapter should use to support the queue. This number can be adjusted relative to the resources that the
miniport driver has available or in proportion to the number that the network adapter uses for other
queues. For example, the actual number of receive buffers could be double or half of this suggested
value.

### `MSIXTableEntry`

A **ULONG** value that contains the MSI-X table entry index for the queue.

### `LookaheadSize`

A **ULONG** value for the size, in bytes, of the lookahead size requirement for this queue. A network adapter that supports lookahead in VM queues splits a received packet at an offset that is equal to or
greater than the requested lookahead size and uses DMA to transfer the lookahead data and the
post-lookahead data to separate shared memory segments.

**Note** Starting with NDIS 6.30, splitting packet data into separate lookahead buffers is no longer supported. The value of this member must be set to zero.

### `VmName`

An **NDIS_VM_NAME** value that contains the user-friendly description of the virtual machine.

### `QueueName`

An **NDIS_QUEUE_NAME** value that contains the user-friendly description of the queue.

### `NumFilters`

A ULONG value that specifies the number of receive filters that have been configured on the network adapter.

**Note** Starting with NDIS 6.30, the miniport driver must maintain a counter for the current number of receive filters that are set on the network adapter. The driver must increment the counter each time a receive filter is set through an OID set request of [OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter). The driver must also decrement the counter each time a receive filter is cleared through an OID set request of [OID_RECEIVE_FILTER_CLEAR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-clear-filter).

### `InterruptCoalescingDomainId`

A ULONG value that is reserved for use by NDIS. This value is used for informational purposes by the miniport driver.

## Remarks

The **NDIS_RECEIVE_QUEUE_INFO** structure is used with the
[NDIS_RECEIVE_QUEUE_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info_array) structure for the
[OID_RECEIVE_FILTER_ENUM_QUEUES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-queues) OID that enumerates receive queues on a network adapter.

With a successful return from the [OID_RECEIVE_FILTER_ENUM_QUEUES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-queues), NDIS provides an
[NDIS_RECEIVE_QUEUE_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info_array) structure that defines the properties of the receive queue array. Each
element in the array is an **NDIS_RECEIVE_QUEUE_INFO** structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_QUEUE_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info_array)

[NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_receive_queue_operational_state)

[NDIS_RECEIVE_QUEUE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_receive_queue_type)

[OID_RECEIVE_FILTER_CLEAR_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-clear-filter)

[OID_RECEIVE_FILTER_ENUM_QUEUES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-queues)

[OID_RECEIVE_FILTER_SET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-set-filter)