# VDS_FILE_SYSTEM_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a file system.

## Members

### `type`

The file-system type enumerated by [VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type).

### `volumeId`

The GUID of the volume object containing the file system.

### `ulFlags`

The file-system flags enumerated by [VDS_FILE_SYSTEM_PROP_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_prop_flag).

### `ullTotalAllocationUnits`

The total number of allocation units.

### `ullAvailableAllocationUnits`

The unused allocation units.

### `ulAllocationUnitSize`

The allocation unit size, in bytes, for the file system, which is
usually between 512 and 4096.

### `pwszLabel`

A string containing the file-system label.

## Remarks

The [IVdsVolumeMF::GetFileSystemProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-getfilesystemproperties) method returns this structure to report the property details of a file system.

## See also

[IVdsVolumeMF::GetFileSystemProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-getfilesystemproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_FILE_SYSTEM_PROP_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_prop_flag)

[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type)