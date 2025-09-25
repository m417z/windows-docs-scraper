# VDS_VDISK_PROPERTIES structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a virtual disk.

## Members

### `Id`

Unique VDS-specific session identifier of the disk.

### `State`

A [VDS_VDISK_STATE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_vdisk_state) enumeration value that specifies the virtual disk state.

### `VirtualDeviceType`

A pointer to a [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure that specifies the storage device type of the virtual disk.

### `VirtualSize`

The size, in bytes, of the virtual disk.

### `PhysicalSize`

The on-disk size, in bytes, of the virtual disk backing file.

### `pPath`

A **NULL**-terminated wide-character string containing the name and directory path of the backing file for the virtual disk.

### `pDeviceName`

A **NULL**-terminated wide-character string containing the name and device path of the disk device object for the volume where the virtual disk resides.

### `DiskFlag`

A bitmask of [DEPENDENT_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-dependent_disk_flag) enumeration values that specify disk dependency information.

### `bIsChild`

**TRUE** if the virtual disk is a child virtual disk, or **FALSE** otherwise.

### `pParentPath`

A **NULL**-terminated wide-character string that contains an optional path to a parent virtual disk object.

## See also

[IVdsVDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvdisk-getproperties)