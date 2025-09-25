# _NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS structure

## Description

The **NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS** structure contains information about the
allocation status of a receive queue.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to **NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS_REVISION_1**, and the
**Size** member to **NDIS_SIZEOF_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `QueueId`

An **NDIS_RECEIVE_QUEUE_ID** type value that contains a receive queue identifier. This identifier is an integer value between zero and the number of queues that the network adapter supports. A value of **NDIS_DEFAULT_RECEIVE_QUEUE_ID** specifies the default receive queue.

### `CompletionStatus`

An **NDIS_STATUS** value that contains an NDIS_STATUS_*Xxx* completion status code. The miniport driver
provides this status code to indicate the completion status of a queue. The miniport driver can use
**NDIS_STATUS_SUCCESS** if the allocation succeeded. Otherwise the miniport driver can use an appropriate
error status, for example, **NDIS_STATUS_RESOURCES**.

## Remarks

The **NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS** structure is used with the
[NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_allocation_complete_array) structure and the
[OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-queue-allocation-complete) OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_allocation_complete_array)

[OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-queue-allocation-complete)