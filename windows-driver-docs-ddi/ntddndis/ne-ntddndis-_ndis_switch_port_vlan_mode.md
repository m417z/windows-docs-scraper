# _NDIS_SWITCH_PORT_VLAN_MODE enumeration

## Description

The **NDIS_SWITCH_PORT_VLAN_MODE** enumeration specifies the operation mode of the virtual local area network (VLAN) policy property of a Hyper-V extensible switch port.

## Constants

### `NdisSwitchPortVlanModeUnknown`

This value specifies an undefined VLAN operation mode.

### `NdisSwitchPortVlanModeAccess`

This value specifies an operation mode in which packets from a single VLAN can be sent or received over the port. These packets can be forwarded from other ports on the extensible switch.

### `NdisSwitchPortVlanModeTrunk`

This value specifies an operation mode where the port acts as a VLAN trunk. In this mode, packets from multiple VLANs as well as non-VLAN packets can be sent or received over the port. These packets can be forwarded from other ports on the extensible switch.

### `NdisSwitchPortVlanModePrivate`

This value specifies an operation mode where packets from a single VLAN can be sent or received over the port. These packets cannot be forwarded from other ports on the extensible switch.

### `NdisSwitchPortVlanModeMax`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **OperationMode** member of the [NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan) structure is an **NDIS_SWITCH_PORT_VLAN_MODE** enumeration data type.

For more information about extensible switch port policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array)

[NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan)