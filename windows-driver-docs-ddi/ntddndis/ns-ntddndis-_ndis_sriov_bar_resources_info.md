# _NDIS_SRIOV_BAR_RESOURCES_INFO structure

## Description

The **NDIS_SRIOV_BAR_RESOURCES_INFO** structure specifies the PCI Express (PCIe) Base Address Register (BAR) of a network adapter's PCIe Virtual Function (VF).

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_BAR_RESOURCES_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_BAR_RESOURCES_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_BAR_RESOURCES_INFO_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_BAR_RESOURCES_INFO_REVISION_1.

### `VFId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the unique identifier of the VF on the network adapter.

**Note** The VF with the specified NDIS_SRIOV_FUNCTION_ID value must have resources that were previously allocated through an OID set request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

### `BarIndex`

A USHORT value that specifies the BAR index on the VF. This value is the offset of the register within the table of BARs in the PCI configuration space.

### `BarResourcesOffset`

A ULONG value that specifies the offset, in units of bytes, from the beginning of this structure to a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure.

## Remarks

The **NDIS_SRIOV_BAR_RESOURCES_INFO** structure is used in OID method requests of [OID_SRIOV_BAR_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-bar-resources).

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SRIOV_BAR_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-bar-resources)