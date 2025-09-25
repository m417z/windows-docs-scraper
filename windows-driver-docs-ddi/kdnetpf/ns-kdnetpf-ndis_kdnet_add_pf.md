## Description

The **NDIS_KDNET_ADD_PF** structure describes the data required to add a PF to the BDF port. It is used by OID_KDNET_ADD_PF.

## Members

### `Header`

A [NDIS_OBJECT_HEADER structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) used to package the object type, version, and size information that is required in many NDIS 6.0 structures.

### `AddedFunctionNumber`

One element containing the added PF port number.

## Remarks

## See also

[kdnetpf.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/)

[Debugger 2PF KDNET Support](https://learn.microsoft.com/windows-hardware/drivers/network/debugger-2pf-kdnet-support)