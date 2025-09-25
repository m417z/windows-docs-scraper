# _NDIS_NIC_SWITCH_FREE_VF_PARAMETERS structure

## Description

The **NDIS_NIC_SWITCH_FREE_VF_PARAMETERS** specifies a PCI Express (PCIe) Virtual Function (VF) whose resources will be freed.

## Members

### `Header`

The type, revision, and size of the **NDIS_NIC_SWITCH_FREE_VF_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_NIC_SWITCH_FREE_VF_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_NIC_SWITCH_FREE_VF_PARAMETERS_REVISION_1

Original version for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_NIC_SWITCH_FREE_VF_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise OR of flags. This member is reserved for NDIS.

### `VFId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the unique identifier of the VF on the network adapter.

**Note** Resources for the VF with the specified NDIS_SRIOV_FUNCTION_ID value must have previously been allocated through an OID method request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

## Remarks

 The **NDIS_NIC_SWITCH_FREE_VF_PARAMETERS** structure is used in OID set requests of [OID_NIC_SWITCH_FREE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-free-vf).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)

[OID_NIC_SWITCH_FREE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-free-vf)