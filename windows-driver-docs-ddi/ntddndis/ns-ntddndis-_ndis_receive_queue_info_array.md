# _NDIS_RECEIVE_QUEUE_INFO_ARRAY structure

## Description

The **NDIS_RECEIVE_QUEUE_INFO_ARRAY** structure specifies a list of receive queues on a network adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_QUEUE_INFO_ARRAY** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to **NDIS_RECEIVE_QUEUE_INFO_ARRAY_REVISION_1**, and the
**Size** member to **NDIS_SIZEOF_RECEIVE_QUEUE_INFO_ARRAY_REVISION_1**.

### `FirstElementOffset`

A ULONG value that specifies the offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_RECEIVE_QUEUE_INFO_ARRAY** structure up to the beginning of the first element. Each element in the array is an [NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info) structure.

**Note** If **NumElements** is set to zero, this member is ignored.

### `NumElements`

A **ULONG** value that represents the number of elements in the list of elements that follow the
**NDIS_RECEIVE_QUEUE_INFO_ARRAY** structure.

### `ElementSize`

A **ULONG** value that specifies the size, in bytes, of each element in the array.

## Remarks

The **NDIS_RECEIVE_QUEUE_INFO_ARRAY** structure is used in the
[OID_RECEIVE_FILTER_ENUM_QUEUES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-queues) OID that enumerates receive queues on a network adapter. Each
element in the array is an
[NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info) structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info)

[OID_RECEIVE_FILTER_ENUM_QUEUES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-enum-queues)