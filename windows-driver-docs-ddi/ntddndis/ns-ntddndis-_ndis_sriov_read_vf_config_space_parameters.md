# _NDIS_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS structure

## Description

The **NDIS_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS** structure specifies the parameters for a read operation on the PCI Express (PCIe) configuration space of a network adapter's Virtual Function (VF).

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS_REVISION_1.

### `VFId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the unique identifier of the VF on the network adapter.

**Note** The VF with the specified NDIS_SRIOV_FUNCTION_ID value must have resources that were previously allocated through an OID set request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

### `Offset`

A ULONG value that specifies the offset within the PCI configuration space of the VF in which data will be read.

### `Length`

A ULONG value that specifies the length, in units of bytes, of the read operation.

### `BufferOffset`

A ULONG value that specifies the offset, in units of bytes, from the beginning of this structure to a buffer that contains the data that is read from the PCI configuration space of the VF.

## Remarks

 The **NDIS_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS** structure is used in OID method requests of [OID_SRIOV_READ_VF_CONFIG_SPACE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-read-vf-config-space).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SRIOV_READ_VF_CONFIG_SPACE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-read-vf-config-space)