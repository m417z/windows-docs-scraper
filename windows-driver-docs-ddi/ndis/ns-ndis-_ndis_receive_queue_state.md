# _NDIS_RECEIVE_QUEUE_STATE structure

## Description

The **NDIS_RECEIVE_QUEUE_STATE** structure contains information about the operational state of a receive
queue.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_QUEUE_STATE** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to **NDIS_RECEIVE_QUEUE_STATE_REVISION_1**, and the
**Size** member to **NDIS_SIZEOF_NDIS_RECEIVE_QUEUE_STATE_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `QueueId`

An **NDIS_RECEIVE_QUEUE_ID** type value that contains a queue identifier. The queue identifier is an
integer value between zero and the number of queues that the network adapter supports. A value of **NDIS_DEFAULT_RECEIVE_QUEUE_ID** specifies
the default receive queue.

### `QueueState`

An
[NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_receive_queue_operational_state) enumeration value that specifies the operational state of the
receive queue.

## Remarks

The **NDIS_RECEIVE_QUEUE_STATE** structure is used in the
[NDIS_STATUS_RECEIVE_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_queue_state) status indication.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_receive_queue_operational_state)

[NDIS_STATUS_RECEIVE_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_queue_state)