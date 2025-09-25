# _NDIS_NIC_SWITCH_VF_PARAMETERS structure

## Description

The **NDIS_NIC_SWITCH_VF_PARAMETERS** specifies the resource parameters of a PCI Express (PCIe) Virtual Function (VF) on a network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_VF_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_VF_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_VF_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_VF_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that specifies a switch identifier. This value identifies the network adapter switch on which the VF is allocated.

The switch identifier is an integer between zero and the number of switches that the network adapter supports. An NDIS_DEFAULT_SWITCH_ID value indicates the default network adapter switch.

**Note** Starting with Windows Server 2012, the single root I/O virtualization (SR-IOV) interface only supports the default network adapter switch on the network adapter. The value of this member must be set to NDIS_DEFAULT_SWITCH_ID.

### `VMName`

An NDIS_VM_NAME value that specifies the internal name of the Hyper-V child partition that is attached to the VF.

**Note** The Hyper-V child partition is also known as a virtual machine (VM).

### `VMFriendlyName`

An NDIS_VM_FRIENDLYNAME value that specifies the external name of the Hyper-V child partition that is attached to the VF. This member contains the user-friendly description of the partition.

### `NicName`

An NDIS_SWITCH_NIC_NAME value that specifies the name of the virtual machine (VM) network adapter. This member contains the user-friendly description of the network adapter.

The VM network adapter is a virtual device that is exposed in the guest operating system that runs in a Hyper-V child partition. The VM network adapter teams with the VF network adapter to provide the hardware-based VF data path over the SR-IOV interface.

For more information about the VF data path, see [SR-IOV VF Data Path](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-vf-data-path).

### `MacAddressLength`

A USHORT value that specifies the length of the **PermanentMacAddress** and **CurrentMacAddress** members.

### `PermanentMacAddress`

The permanent MAC address of the VF. This is the permanent MAC address for the VF network adapter that is exposed in the guest operating system.

### `CurrentMacAddress`

The current MAC address of the VF. This is the current MAC address for the VF network adapter that is exposed in the guest operating system.

### `VFId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the unique identifier of the VF on the network adapter.

### `RequestorId`

An NDIS_VF_RID that specifies the PCI Express (PCIe) Requestor ID (RID) of the VF.

## Remarks

The **NDIS_NIC_SWITCH_VF_PARAMETERS** structure is used in OID method requests of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf) and [OID_NIC_SWITCH_VF_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vf-parameters).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)

[OID_NIC_SWITCH_VF_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vf-parameters)