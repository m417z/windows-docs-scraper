# _NDIS_SWITCH_PORT_TYPE enumeration

## Description

The **NDIS_SWITCH_PORT_TYPE** enumeration specifies the type of a Hyper-V extensible switch port.

## Constants

### `NdisSwitchPortTypeGeneric`

This value specifies a generic port type that was created with an earlier version of the extensible switch WMI management platform.

### `NdisSwitchPortTypeExternal`

This value specifies a port that is connected to an external network adapter. This adapter is exposed in the management operating system that runs in the Hyper-V parent partition.

The external network adapter provides the connection to the physical network interface that is available on the host. This allows processes that run in either the management or guest operating systems to send or receive packets over the extensible switch.

**Note** An extensible switch supports no more than one external network adapter. The external network adapter can be bound to one or more underlying physical network adapters. For more information, see [External Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/external-network-adapters).

### `NdisSwitchPortTypeSynthetic`

This value specifies a port that is connected to a synthetic network adapter. This adapter is exposed in a guest operating system that runs in a Hyper-V child partition.

**Note** A synthetic network adapter is a type of virtual machine (VM) network adapter. This adapter is exposed in a guest operating system that is running Windows Vista or a later version of Windows.

### `NdisSwitchPortTypeEmulated`

This value specifies a port that is connected to an emulated network adapter. This adapter is exposed in a guest operating system.

**Note** An emulated network adapter is a type of VM network adapter. This adapter can be exposed in a guest operating system that is running Windows XP or a non-Windows operating system.

### `NdisSwitchPortTypeInternal`

This value specifies a port that is connected to an internal network adapter. This adapter is exposed in the management operating system that runs in the Hyper-V parent partition.

The internal network adapter provides access to an extensible switch for processes that run in the management operating system. This allows these processes to send or receive packets over the extensible switch.

**Note** An extensible switch supports no more than one internal network adapter. For more information, see [Internal Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/internal-network-adapters).

## Remarks

The **PortType** member of the [NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters) structure is an **NDIS_SWITCH_PORT_TYPE** enumeration data type.

For more information on the extensible switch ports, see [Hyper-V Extensible Switch Ports](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-ports).

## See also

[NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters)