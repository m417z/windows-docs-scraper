# _NDIS_SWITCH_PORT_STATE enumeration

## Description

The **NDIS_SWITCH_PORT_STATE** enumeration specifies the current state of the Hyper-V extensible switch port.

## Constants

### `NdisSwitchPortStateUnknown`

This value specifies an undefined port state. This value is unused.

### `NdisSwitchPortStateCreated`

This value specifies that the port is in the created state.

### `NdisSwitchPortStateTeardown`

This value specifies that the port is being torn down.

### `NdisSwitchPortStateDeleted`

This value specifies that the port has been deleted.

## Remarks

The **PortState** member of the [NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters) structure is an **NDIS_SWITCH_PORT_STATE** enumeration data type.

For more information about extensible switch port states, see [Overview of Hyper-V Extensible Switch Ports](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-hyper-v-extensible-switch-ports).

## See also

[NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters)