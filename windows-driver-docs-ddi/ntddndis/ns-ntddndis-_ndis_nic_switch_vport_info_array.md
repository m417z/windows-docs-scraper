# _NDIS_NIC_SWITCH_VPORT_INFO_ARRAY structure

## Description

The **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure specifies an array. Each element in the array specifies the attributes of a virtual port (VPort) that has been created on a network adapter's network adapter switch.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

NDIS sets the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure, NDIS sets the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_VPORT_INFO_ARRAY_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of the following flags:

#### NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_ENUM_ON_SPECIFIC_FUNCTION

This flag specifies to enumerate the VPorts attached to a specific PCI Express (PCIe) function. The function is specified in the **AttachedFunctionId** member. This flag can be used to enumerate the VPorts attached to the PCIe Physical Function (PF) or a specified PCIe Virtual Function (VF).

#### NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_ENUM_ON_SPECIFIC_SWITCH

This flag specifies to enumerate the VPorts created on a specific switch, specified by the SwitchId. This enumerates all the VPorts created on the switch.

**Note** These flags are mutually exclusive. Only one flag can be set in the **Flags** member.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that specifies a switch identifier. The switch identifier is an integer between zero and the number of switches that the network adapter supports. An NDIS_DEFAULT_SWITCH_ID value indicates the default network adapter switch.

The **SwitchId** member is only valid if NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_ENUM_ON_SPECIFIC_SWITCH is specified in the **Flags** member.

**Note** Starting with Windows Server 2012, the single root I/O virtualization (SR-IOV) interface only supports the default network adapter switch on the network adapter. The value of this member must be set to NDIS_DEFAULT_SWITCH_ID.

### `AttachedFunctionId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the identifier of the PF or a VF on the network adapter.

**Note** If this value is NDIS_PF_FUNCTION_ID, the VPort is attached to the PF.

The **AttachedFunctionId** member is only valid if NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_ENUM_ON_SPECIFIC_FUNCTION is specified in the **Flags** member.

### `FirstElementOffset`

A ULONG value that specifies the offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure up to the beginning of the first element. Each element in the array is an [NDIS_NIC_SWITCH_VPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info) structure.

**Note** If **NumElements** is set to zero, this member is ignored.

### `NumElements`

A ULONG value that specifies the number of elements that follow the **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure.

### `ElementSize`

A ULONG value that specifies the size, in bytes, of each element that follows the **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure.

## Remarks

NDIS returns an **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure when NDIS handles an OID method request of [OID_NIC_SWITCH_ENUM_VPORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-vports). Each
element in the array that follows the **NDIS_NIC_SWITCH_VPORT_INFO_ARRAY** structure is an
[NDIS_NIC_SWITCH_VPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info) structure.

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

## See also

[NDIS_NIC_SWITCH_VPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_info)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_ENUM_VPORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-vports)