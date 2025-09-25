# _NDIS_PORT_ARRAY structure

## Description

The NDIS_PORT_ARRAY structure specifies a list of NDIS ports and their associated
characteristics.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_PORT_ARRAY structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_PORT_ARRAY_REVISION_1, and the
**Size** member to NDIS_SIZEOF_PORT_ARRAY_REVISION_1.

### `NumberOfPorts`

The number of NDIS ports that have characteristics that are listed in the
**Ports** member.

### `OffsetFirstPort`

The offset, in bytes, from the beginning of the NDIS_PORT_ARRAY structure to the start of the
first port characteristics data.

### `ElementSize`

The size, in bytes, of each element in the array that the
**Ports** member specifies.

### `Ports`

An array that contains the port characteristics for each active NDIS port on a miniport adapter.
The
**ElementSize** member specifies the size of each element in the array. The
**NumberOfPorts** member specifies the number of elements in the array. Each
element in the array is an
[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics) structure.

## Remarks

The NDIS_PORT_ARRAY structure specifies characteristics, of all of the active NDIS ports on the
miniport adapter, for the
[OID_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-enumerate-ports) OID.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics)

[OID_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-enumerate-ports)