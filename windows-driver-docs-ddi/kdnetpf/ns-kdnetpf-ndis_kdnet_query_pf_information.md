## Description

The **NDIS_KDNET_QUERY_PF_INFORMATION** structure describes the data required to query the PF management data.

It is used by OID_KDNET_QUERY_PF_INFORMATION.

## Members

### `Header`

A [NDIS_OBJECT_HEADER structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) used to package the object type, version, and size information that is required in many NDIS 6.0 structures.

### `Bdf`

The PF PCI location to query for.

### `NetworkAdddress[6]`

The PF assigned MAC address.

### `UsageTag`

The PF Usage tag described by [NDIS_KDNET_PF_USAGE_TAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/ne-kdnetpf-ndis_kdnet_pf_usage_tag).

### `MaximumNumberOfSupportedPfs`

The maximum number of Pfs that can be associated to the Primary BDF.
### `DeviceId`

The KDNET PF device ID. It is used if there is a new added PF and the FW assigns a new DeviceID to the added KDNET PF.

## Remarks

## See also

[kdnetpf.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/)

[Debugger 2PF KDNET Support](https://learn.microsoft.com/windows-hardware/drivers/network/debugger-2pf-kdnet-support)