# VDS_STORAGE_IDENTIFIER structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines a
storage device using a particular code set and type.

## Members

### `m_CodeSet`

The encoding type of **m_rgbIdentifier** enumerated by
[VDS_STORAGE_IDENTIFIER_CODE_SET](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_identifier_code_set).

### `m_Type`

The type of **m_rgbIdentifier** enumerated by
[VDS_STORAGE_IDENTIFIER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_identifier_type).

### `m_cbIdentifier`

The size of the **m_rgbIdentifier** array, in bytes.

### `m_rgbIdentifier`

Pointer to the identifier data.

## Remarks

The [VDS_STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_device_id_descriptor)
structure includes this structure as a member to specify a particular storage device identifier for a LUN.

## See also

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_device_id_descriptor)

[VDS_STORAGE_IDENTIFIER_CODE_SET](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_identifier_code_set)

[VDS_STORAGE_IDENTIFIER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_identifier_type)