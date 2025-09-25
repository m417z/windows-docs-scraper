# VDS_STORAGE_DEVICE_ID_DESCRIPTOR structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines one or more storage identifiers for a storage device (typically an instance, as opposed to a
class, of device).

## Members

### `m_version`

The version of this structure.

### `m_cIdentifiers`

The number of identifiers specified in **m_rgIdentifiers**.

### `m_rgIdentifiers`

Pointer to [VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier) structure.

## Remarks

Storage devices can have multiple identifiers, and each of these identifiers can have a different code set and
type. The [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure includes
this structure as a member to specify the storage device identifiers of a LUN.

## See also

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)

[VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)