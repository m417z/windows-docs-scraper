# _NDIS_SWITCH_PORT_DESTINATION structure

## Description

The **NDIS_SWITCH_PORT_DESTINATION** structure specifies the Hyper-V extensible switch destination port to which a packet will be delivered.

## Members

### `PortId`

An NDIS_SWITCH_PORT_ID value that specifies the unique identifier of the destination port on the extensible switch.

### `NicIndex`

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the network adapter that is connected to the extensible switch port specified by the **PortId** member.

For more information on NDIS_SWITCH_NIC_INDEX values, see [Network Adapter Index Values](https://learn.microsoft.com/windows-hardware/drivers/network/network-adapter-index-values).

**Note** This member must specify the index value of a network adapter that is in a connected state. Index values for network adapters that are in a created or disconnected state cannot be specified. For more information about network connection states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

### `IsExcluded`

If this member is set to TRUE, the packet will not be delivered to the
destination port.

### `PreserveVLAN`

If this member is set to TRUE, the 802.1Q virtual local area network (VLAN) information will be preserved when the packet is delivered to the destination port.

### `PreservePriority`

If this member is set to TRUE, the 802.1Q priority information will be preserved when the packet is delivered to the destination port.

### `Reserved`

This member is reserved for future use by NDIS.

## Remarks

The [NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array) contains one or more elements. Each element is formatted as an **NDIS_SWITCH_PORT_DESTINATION** structure.

**Note** The **NicIndex** member must specify the index value of a network adapter that is in a connected state. Index values for network adapters that are in a created or disconnected state cannot be specified. For more information about network connection states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

For more information on destination ports, see [Managing Hyper-V Extensible Switch Destination Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-destination-port-data).

## See also

[NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array)