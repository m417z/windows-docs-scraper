# _NDIS_SWITCH_NIC_TYPE enumeration

## Description

The **NDIS_SWITCH_NIC_TYPE** enumeration specifies the type of the virtual network adapter that is attached to a Hyper-V extensible switch port.

## Constants

### `NdisSwitchNicTypeExternal`

This value specifies a virtual network adapter that is exposed in the management operating system that runs in the Hyper-V parent partition. The external network adapter provides the connection to the physical network interface that is available on the host. This allows processes that run in either the management or guest operating systems to send or receive packets over the extensible switch.

**Note** An extensible switch supports no more than one external network adapter. The external network adapter can be bound to one or more underlying physical network adapters. For more information, see [External Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/external-network-adapters).

### `NdisSwitchNicTypeSynthetic`

This value specifies a synthetic network adapter that is exposed in a guest operating system that runs in a Hyper-V child partition.

**Note** A synthetic network adapter is a type of virtual machine (VM) network adapter. This adapter is exposed in a guest operating system that is Windows Vista or a later version of Windows.

### `NdisSwitchNicTypeEmulated`

This value specifies an emulated network adapter that is exposed in a guest operating system.

**Note** An emulated network adapter is a type of VM network adapter. This adapter is exposed in a guest operating system that is Windows XP, Windows Vista, or a later version of Windows. This adapter is also exposed in a guest operating system that is a non-Windows operating system.

### `NdisSwitchNicTypeInternal`

This value specifies a virtual network adapter that is exposed in the management operating system that runs in the Hyper-V parent partition. The internal network adapter provides access to an extensible switch for processes that run in the management operating system. This allows these processes to send or receive packets over the extensible switch.

**Note** An extensible switch supports no more than one internal network adapter. For more information, see [Internal Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/internal-network-adapters).

## Remarks

The **NicType** member of the [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structure is an **NDIS_SWITCH_NIC_TYPE** enumeration data type.

For more information on the types of network adapters that connect to extensible switch ports, see [Hyper-V Extensible Switch Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-network-adapters).

## See also

[NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters)