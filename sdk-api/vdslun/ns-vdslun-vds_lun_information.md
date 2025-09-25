# VDS_LUN_INFORMATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
information about a LUN or disk. Applications can use this structure to uniquely identify a LUN at all times.

## Members

### `m_version`

The version of this structure. The current value is the constant
**VER_VDS_LUN_INFORMATION**.

### `m_DeviceType`

The SCSI-2 device type of the LUN.

### `m_DeviceTypeModifier`

The SCSI-2 device type modifier of the LUN. For LUNs that have no device type modifier, the value is
zero.

### `m_bCommandQueueing`

If **TRUE**, the LUN supports multiple outstanding commands; otherwise,
**FALSE**. The synchronization of the queue is the responsibility of the port
driver.

### `m_BusType`

The bus type of the LUN enumerated by
[VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type).

### `m_szVendorId`

Pointer to the LUN vendor identifier; a zero-terminated, human-readable string. For devices that have no
vendor identifier, the value is zero.

### `m_szProductId`

Pointer to the LUN product identifier, typically a model number; a zero-terminated, human-readable string.
For devices that have no product identifier, the value is zero.

### `m_szProductRevision`

Pointer to the LUN product revision; a zero-terminated, human-readable string. For devices that have no
product revision, the value is zero.

### `m_szSerialNumber`

Pointer to the LUN serial number; a zero-terminated, human-readable string. For devices that have no serial
number, the value is zero.

### `m_diskSignature`

The signature of the LUN. For disks that use the Master Boot Record (MBR) partitioning structure, the first
32 bits of the GUID comprise the disk signature, and the remaining bits are zeros. For disks that use the GUID
Partition Table (GPT) partitioning structure, the GUID consists of the GPT disk identifier. If this value is
zero, the disk is uninitialized or the hardware provider was unable to retrieve the signature.

### `m_deviceIdDescriptor`

Array containing the LUN descriptor in various formats, such as "VDSStorageIdTypeFCPHName"
and "VDSStorageIdTypeVendorSpecific". Providers can use
"VDSStorageIdTypeVendorSpecific" to store an arbitrary byte string of the vendor's choosing to
uniquely identify the LUN. See the
[VDS_STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_device_id_descriptor)
structure and the
[VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)
structure.

### `m_cInterconnects`

The number of interconnect ports specified in **m_rgInterconnects**.

### `m_rgInterconnects`

Pointer to an array of the interconnect ports by which the LUN can be accessed. See the
[VDS_INTERCONNECT](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_interconnect) structure.

## Remarks

The **VDS_LUN_INFORMATION** structure includes
fields from the SCSI Inquiry Data and Vital Product Data pages 0x80 and 0x83. The
**GetIdentificationData** method on both the
[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun) and
[IVdsDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk) interfaces return this structure. It is also
passed as an argument in the
[IVdsHwProviderPrivate::QueryIfCreatedLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwproviderprivate-queryifcreatedlun)
method to determine whether a given provider owns a specified LUN.

To get the LUN object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties) method to get the LUN properties.

## See also

[IVdsDisk::GetIdentificationData](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getidentificationdata)

[IVdsHwProviderPrivate::QueryIfCreatedLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwproviderprivate-queryifcreatedlun)

[IVdsLun::GetIdentificationData](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getidentificationdata)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_INTERCONNECT](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_interconnect)

[VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type)

[VDS_STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_device_id_descriptor)

[VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)