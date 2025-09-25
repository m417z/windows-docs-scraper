# _NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY structure

## Description

The **NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY** structure contains information about the allocation
status of a batch of receive queues.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to **NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY_REVISION_1**, and the
**Size** member to **NDIS_SIZEOF_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `FirstElementOffset`

A ULONG value that specifies the offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY** structure up to the beginning of the first element. Each element in the array is an [NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_allocation_complete_parameters) structure.

**Note** If **NumElements** is set to zero, this member is ignored.

### `NumElements`

A **ULONG** value for the number of elements in the list of elements that follow the
**NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY** structure.

### `ElementSize`

A **ULONG** value that specifies the size, in bytes, of each element in the array.

## Remarks

The **NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY** structure is used in the
[OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-queue-allocation-complete) OID.

Each element in the array that follows this structure is an
[NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_allocation_complete_parameters) structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_allocation_complete_parameters)

[OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-queue-allocation-complete)