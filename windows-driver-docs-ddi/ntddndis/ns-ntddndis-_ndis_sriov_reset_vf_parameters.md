# _NDIS_SRIOV_RESET_VF_PARAMETERS structure

## Description

The **NDIS_SRIOV_RESET_VF_PARAMETERS** structure specifies the parameters for resetting a network adapter's PCI Express (PCIe) Virtual Function (VF).

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_RESET_VF_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_RESET_VF_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_RESET_VF_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_RESET_VF_PARAMETERS_REVISION_1.

### `VFId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the unique identifier of the VF on the network adapter.

**Note** The VF with the specified NDIS_SRIOV_FUNCTION_ID value must have resources that were previously allocated through an OID set request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

## Remarks

The **NDIS_SRIOV_RESET_VF_PARAMETERS** structure is used in OID set requests of [OID_SRIOV_RESET_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-reset-vf).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SRIOV_RESET_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-reset-vf)