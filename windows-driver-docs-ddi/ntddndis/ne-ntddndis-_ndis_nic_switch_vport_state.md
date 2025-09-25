# _NDIS_NIC_SWITCH_VPORT_STATE enumeration

## Description

The **NDIS_NIC_SWITCH_VPORT_STATE** enumeration specifies the state of a single root I/O virtualization (SR-IOV) virtual port (VPort) on the NIC switch of a network adapter.

## Constants

### `NdisNicSwitchVPortStateUndefined`

The VPort state is not defined.

### `NdisNicSwitchVPortStateActivated`

The VPort is allocated and in an activated state.

**Note** The default VPort attached to the PCI Express (PCIe) Physical Function (PF) and nondefault VPorts attached to PCIe Virtual Functions (VFs) are created in an activated state. Once created, these VPorts cannot be deactivated.

### `NdisNicSwitchVPortStateDeactivated`

The VPort is allocated and in a deactivated state.

**Note** Nondefault VPorts attached to the PF are created in a deactivated state. These VPorts can be activated by using OID set requests of [OID_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vport-parameters). However, once activated, these VPorts cannot be deactivated.

### `NdisNicSwitchVPortStateMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **VPortState** member of the [NDIS_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_parameters) and [NDIS_NIC_SWITCH_VPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info) structures is an **NDIS_NIC_SWITCH_VPORT_STATE** enumeration data type.

## See also

[NDIS_NIC_SWITCH_VPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info)

[NDIS_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_parameters)

[OID_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vport-parameters)