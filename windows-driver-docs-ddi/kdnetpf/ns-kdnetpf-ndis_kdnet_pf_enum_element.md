## Description

The **NDIS_KDNET_PF_ENUM_ELEMENT** is a PF element array structure.

## Members

### `Header`

A [NDIS_OBJECT_HEADER structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) used to package the object type, version, and size information that is required in many NDIS 6.0 structures.

### `PfNumber`

The PF value (e.g. if ``, then PF value = fun).

### `PfState`

The PF state value defined by [NDIS_KDNET_PF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/ne-kdnetpf-ndis_kdnet_pf_state).

## Remarks

## See also

[kdnetpf.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/)

[Debugger 2PF KDNET Support](https://learn.microsoft.com/windows-hardware/drivers/network/debugger-2pf-kdnet-support)