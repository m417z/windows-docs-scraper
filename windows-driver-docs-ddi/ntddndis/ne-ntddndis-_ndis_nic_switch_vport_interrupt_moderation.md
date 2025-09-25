# _NDIS_NIC_SWITCH_VPORT_INTERRUPT_MODERATION enumeration

## Description

The **NDIS_NIC_SWITCH_VPORT_INTERRUPT_MODERATION** enumeration specifies the interrupt moderation setting of a single root I/O virtualization (SR-IOV) virtual port (VPort) on the NIC switch.

## Constants

### `NdisNicSwitchVPortInterruptModerationUndefined`

Interrupt moderation for the VPort is not defined.

### `NdisNicSwitchVPortInterruptModerationAdaptive`

Interrupt moderation for the VPort is adaptive. This state enables the network adapter to adjust the interrupt moderation rate for the VPort based on the pattern of network traffic.

### `NdisNicSwitchVPortInterruptModerationOff`

Interrupt moderation for the VPort is disabled.

### `NdisNicSwitchVPortInterruptModerationLow`

Interrupt moderation for the VPort is low.

### `NdisNicSwitchVPortInterruptModerationMedium`

Interrupt moderation for the VPort is medium.

### `NdisNicSwitchVPortInterruptModerationHigh`

Interrupt moderation for the VPort is high.

## Remarks

The determination of low, medium, and high interrupt moderation levels is determined by the miniport driver based on a hardware algorithm that is based on the network adapter.

The **InterruptModeration** member of the [NDIS_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_parameters) and [NDIS_NIC_SWITCH_VPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info) structures is an NDIS_NIC_SWITCH_VPORT_INTERRUPT_MODERATION enumeration data type.

## See also

[NDIS_NIC_SWITCH_VPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info)

[NDIS_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_parameters)