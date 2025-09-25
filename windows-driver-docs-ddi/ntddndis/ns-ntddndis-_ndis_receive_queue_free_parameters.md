# _NDIS_RECEIVE_QUEUE_FREE_PARAMETERS structure

## Description

The **NDIS_RECEIVE_QUEUE_FREE_PARAMETERS** structure identifies a receive queue to free.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_QUEUE_FREE_PARAMETERS** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to **NDIS_RECEIVE_QUEUE_FREE_PARAMETERS_REVISION_1**, and the
**Size** member to **NDIS_SIZEOF_RECEIVE_QUEUE_FREE_PARAMETERS_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `QueueId`

An **NDIS_RECEIVE_QUEUE_ID** type value that contains a receive queue identifier. This identifier is an
integer value between one and the number of queues that the network adapter supports.

**Note** The default receive queue is always allocated and can never be freed. Drivers must not set the **QueueId** member to **NDIS_DEFAULT_RECEIVE_QUEUE_ID**.

## Remarks

The **NDIS_RECEIVE_QUEUE_FREE_PARAMETERS** structure is used in the
[OID_RECEIVE_FILTER_FREE_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-free-queue) OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_RECEIVE_FILTER_FREE_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-free-queue)