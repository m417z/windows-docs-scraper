# _NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO structure

## Description

The **NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO** structure specifies the PCI Express (PCIe) vendor and device identifiers (IDs) for a PCIe Virtual Function (VF) network adapter. This virtual adapter is exposed within the guest operating system that runs in a Hyper-V child partition.

The **NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO** structure contains information that is used for PnP device enumeration in the guest operating system.

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_VF_VENDOR_DEVICE_ID_INFO_REVISION_1.

### `VFId`

An NDIS_SRIOV_FUNCTION_ID value that specifies the unique identifier of the VF network adapter.

**Note** The VF with the specified NDIS_SRIOV_FUNCTION_ID value must have resources that were previously allocated through an OID set request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf).

### `VendorId`

A USHORT value that uniquely identifies the vendor of the VF network adapter.

### `DeviceId`

A USHORT value that uniquely identifies the device type of the VF network adapter.

## Remarks

 The **NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO** structure is used in the OID method requests of [OID_SRIOV_VF_VENDOR_DEVICE_ID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-vendor-device-id).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)

[OID_SRIOV_VF_VENDOR_DEVICE_ID](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-vendor-device-id)