# _IPSEC_OFFLOAD_V2_DELETE_SA structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The IPSEC_OFFLOAD_V2_DELETE_SA structure specifies a security association (SA) that should be deleted
from a NIC and a pointer to the next IPSEC_OFFLOAD_V2_DELETE_SA structure in a linked list.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
IPSEC_OFFLOAD_V2_DELETE_SA structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_IPSEC_OFFLOAD_V2_DELETE_SA_REVISION_1, and the
**Size** member to NDIS_SIZEOF_IPSEC_OFFLOAD_V2_DELETE_SA_REVISION_1.

### `Next`

A pointer to an IPSEC_OFFLOAD_V2_DELETE_SA structure that is the next structure in a linked list.
If the pointer is **NULL**, the current structure is the last structure in the list.

### `OffloadHandle`

An NDIS handle that identifies the SA. The miniport driver provided this handle in response to an
OID set request of [OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa).

## Remarks

The IPSEC_OFFLOAD_V2_DELETE_SA structure defines a handle for a SA that should be deleted and a
pointer to the next IPSEC_OFFLOAD_V2_DELETE_SA structure in a linked list. The IPSEC_OFFLOAD_V2_DELETE_SA
structure is used with the
[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa) OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-delete-sa)