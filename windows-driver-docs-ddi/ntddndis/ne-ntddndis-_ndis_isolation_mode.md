# _NDIS_ISOLATION_MODE enumeration

## Description

The **NDIS_ISOLATION_MODE** enumeration defines the network isolation modes that can be specified for a VM network adapter.

## Constants

### `NdisIsolationModeNone`

Network isolation is not supported.

### `NdisIsolationModeNativeVirtualSubnet`

Native **VirtualSubnetId**-based isolation provided by Hyper-V Network Virtualization.

### `NdisIsolationModeExternalVirtualSubnet`

External **VirtualSubnetId**-based isolation provided by a Hyper-V Extensible Switch extension.

### `NdisIsolationModeVlan`

Virtual local area network (VLAN)-based isolation.

## Remarks

**NDIS_ISOLATION_MODE** enumeration values are used in the **IsolationMode** member of the [NDIS_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters) and [NDIS_SWITCH_PORT_PROPERTY_ISOLATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_isolation) structures.

## See also

[NDIS_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters)

[NDIS_SWITCH_PORT_PROPERTY_ISOLATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_isolation)