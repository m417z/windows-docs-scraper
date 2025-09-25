# _NDIS_NIC_SWITCH_VF_INFO_ARRAY structure

## Description

The **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure specifies an array. Each element in the array specifies the attributes of a PCI Express (PCIe) virtual functions (VF) that have been enabled and allocated on a network adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

NDIS sets the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure, NDIS sets the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_VF_INFO_ARRAY_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_VF_INFO_ARRAY_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of the following flags:

#### NDIS_NIC_SWITCH_VF_INFO_ARRAY_ENUM_ON_SPECIFIC_SWITCH

If this flag is set, the miniport driver must only return an array of [NDIS_NIC_SWITCH_VF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vf_info) structures for VFs that have been allocated on the network adapter switch specified by the **SwitchId** member. For more information, see the Remarks section.

If the Flags member is set to zero, the miniport driver must return an array of [NDIS_NIC_SWITCH_VF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vf_info) structures for every VF that has been allocated on every network adapter switch of the network adapter.

**Note** Starting with Windows Server 2012, the SR-IOV interface only supports the default network adapter switch on the network adapter. Therefore, the miniport driver must only return an array of [NDIS_NIC_SWITCH_VF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vf_info) structures for each VF that has been allocated on the default network adapter switch.

### `SwitchId`

An NDIS_NIC_SWITCH_ID value that specifies a switch identifier. The switch identifier is an integer between zero and the number of switches that the network adapter supports. An NDIS_DEFAULT_SWITCH_ID value indicates the default network adapter switch.

**Note** Starting with Windows Server 2012, the SR-IOV interface only supports the default network adapter switch that is created on the network adapter. Therefore, this member must always be set to NDIS_DEFAULT_SWITCH_ID.

### `FirstElementOffset`

A ULONG value that specifies the offset, in bytes, to the first element in an array of elements that follow this structure. The offset is measured from the start of the **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure up to the beginning of the first element. Each element in the array is an [NDIS_NIC_SWITCH_VF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vf_info) structure.

**Note** If **NumElements** is set to zero, this member is ignored.

### `NumElements`

A ULONG value that specifies the number of elements that follow the **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure.

### `ElementSize`

A ULONG value that specifies the size, in bytes, of each element that follow the **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure.

## Remarks

NDIS returns an **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure when it handles an OID method request of [OID_NIC_SWITCH_ENUM_VFS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-vfs). Each
element in the array that follows the **NDIS_NIC_SWITCH_VF_INFO_ARRAY** structure is an
[NDIS_NIC_SWITCH_VF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vf_info) structure.

## See also

[NDIS_NIC_SWITCH_VF_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vf_info)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_ENUM_VFS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-enum-vfs)