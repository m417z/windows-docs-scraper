# _NDIS_SWITCH_PORT_PVLAN_MODE enumeration

## Description

The **NDIS_SWITCH_PORT_PVLAN_MODE** enumeration specifies the operation mode of a private virtual local area network (PVLAN) policy property. This property is specified for a port on the Hyper-V extensible switch.

## Constants

### `NdisSwitchPortPvlanModeUndefined`

This value specifies an undefined PVLAN operation mode.

### `NdisSwitchPortPvlanModeIsolated`

This value specifies a port that operates in PVLAN isolated mode. In isolated mode, the port can receive traffic only on the primary VLAN. It sends traffic on the secondary VLAN.

### `NdisSwitchPortPvlanModeCommunity`

This value specifies a port that operates in PVLAN community mode. In community mode, the port can receive traffic on the primary and secondary VLAN. However, the port can send traffic only on its secondary VLAN.

### `NdisSwitchPortPvlanModePromiscuous`

This value specifies a port that operates in PVLAN promiscuous mode. In promiscuous mode, the port can receive traffic on a defined set of primary and secondary VLANs. However, the port can send traffic only on its primary VLAN.

## Remarks

The **PvlanMode** member of the [NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan) structure is an [NDIS_SWITCH_PORT_VLAN_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_vlan_mode) enumeration data type.

For more information about extensible switch port policies, see [Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-policies).

## See also

[NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array)

[NDIS_SWITCH_PORT_PROPERTY_VLAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_vlan)