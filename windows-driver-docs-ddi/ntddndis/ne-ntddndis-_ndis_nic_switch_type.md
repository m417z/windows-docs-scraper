# _NDIS_NIC_SWITCH_TYPE enumeration

## Description

The **NDIS_NIC_SWITCH_TYPE** enumeration specifies the type of the NIC switch on a network adapter.

## Constants

### `NdisNicSwitchTypeUnspecified`

The NIC switch type is not specified.

### `NdisNicSwitchTypeExternal`

This value specifies an external switch. The single root I/O virtualization (SR-IOV) virtual ports (VPorts) connected to this type of switch, including the default VPort, can access the external network through the physical port on the network adapter.

### `NdisNicSwitchTypeMax`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The **SwitchType** member of the [NDIS_NIC_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_parameters) and [NDIS_NIC_SWITCH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info) structures is an **NDIS_NIC_SWITCH_TYPE** enumeration data type.

For more information about the NIC switch, see [SR-IOV Architecture](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-architecture).

## See also

[NDIS_NIC_SWITCH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info)

[NDIS_NIC_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_parameters)