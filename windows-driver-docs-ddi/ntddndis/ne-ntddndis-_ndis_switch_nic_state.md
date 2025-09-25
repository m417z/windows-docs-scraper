# _NDIS_SWITCH_NIC_STATE enumeration

## Description

The **NDIS_SWITCH_NIC_STATE** enumeration specifies the current state of the Hyper-V extensible switch network adapter.

## Constants

### `NdisSwitchNicStateUnknown`

 This value specifies an undefined NIC state. This value is unused.

### `NdisSwitchNicStateCreated`

This value specifies that the NIC is in the created state.

### `NdisSwitchNicStateConnected`

This value specifies that the NIC is connected.

### `NdisSwitchNicStateDisconnected`

This value specifies that the NIC is disconnected.

### `NdisSwitchNicStateDeleted`

This value specifies that the NIC is deleted.

## Remarks

The **NicState** member of the [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structure is an **NDIS_SWITCH_NIC_STATE** enumeration data type.

For more information about extensible switch port states, see [Overview of Hyper-V Extensible Switch Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-hyper-v-extensible-switch-network-adapters).

## See also

[NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters)