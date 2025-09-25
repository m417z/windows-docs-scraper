# _IPSEC_OFFLOAD_V2_UPDATE_SA structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The IPSEC_OFFLOAD_V2_UPDATE_SA structure updates information about security associations (SAs) that a
miniport driver previously added to a NIC and a pointer to the next IPSEC_OFFLOAD_V2_UPDATE_SA structure in
a linked list.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
IPSEC_OFFLOAD_V2_UPDATE_SA structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_IPSEC_OFFLOAD_V2_UPDATE_SA_REVISION_1, and the
**Size** member to NDIS_SIZEOF_IPSEC_OFFLOAD_V2_UPDATE_SA_REVISION_1.

### `OffloadHandle`

An NDIS handle that identifies the SA. The miniport driver provided this handle in response to an
OID set request of [OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa).

### `Operation`

The IPsec operation for which the SA is to be used. The
[IPSEC_OFFLOAD_V2_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ipsec_offload_v2_operation) enumeration defines the supported operations.

### `Spi`

A 32 bit security parameters index (SPI) for the SA.

### `SequenceNumberHighOrder`

The high-order bit of an IPsec sequence number. This bit is not included in the IPsec
header.

## Remarks

The IPSEC_OFFLOAD_V2_UPDATE_SA structure specifies updates for a SA and a pointer to the next
IPSEC_OFFLOAD_V2_UPDATE_SA structure in a linked list. The IPSEC_OFFLOAD_V2_UPDATE_SA structure is used
with the
[OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-update-sa) OID.

## See also

[IPSEC_OFFLOAD_V2_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ipsec_offload_v2_operation)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-add-sa)

[OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-task-ipsec-offload-v2-update-sa)