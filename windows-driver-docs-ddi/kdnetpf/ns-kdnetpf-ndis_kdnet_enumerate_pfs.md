## Description

The **NDIS_KDNET_ENUMERATE_PFS** structure describes the data required to enumerate the list of PF. It is used by OID_KDNET_ENUMERATE_PFS.

## Members

### `Header`

A [NDIS_OBJECT_HEADER structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) used to package the object type, version, and size information that is required in many NDIS 6.0 structures.

### `ElementSize`

The size of each element is the sizeof(NDIS_KDNET_PF_ENUM_ELEMENT).

### `NumberOfElements`

The number of elements in the returned array.

### `OffsetToFirstElement`

Offset value to the first element of the returned array. Each array element is defined by [NDIS_KDNET_PF_ENUM_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/ns-kdnetpf-ndis_kdnet_pf_enum_element).

## Remarks

## See also

[kdnetpf.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/)

[Debugger 2PF KDNET Support](https://learn.microsoft.com/windows-hardware/drivers/network/debugger-2pf-kdnet-support)