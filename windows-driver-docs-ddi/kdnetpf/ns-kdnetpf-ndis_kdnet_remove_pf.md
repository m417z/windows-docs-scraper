## Description

The **NDIS_KDNET_REMOVE_PF** structure describes the data required to remove a PF from the BDF port. It is used by OID_KDNET_REMOVE_PF.

## Members

### `Header`

A [NDIS_OBJECT_HEADER structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) used to package the object type, version, and size information that is required in many NDIS 6.0 structures.

### `Bdf`

The PCI location that points to the PF that needs to be removed.

### `FunctionNumber`

The one element containing the removed PF port.

## Remarks

## See also

[kdnetpf.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/)

[Debugger 2PF KDNET Support](https://learn.microsoft.com/windows-hardware/drivers/network/debugger-2pf-kdnet-support)