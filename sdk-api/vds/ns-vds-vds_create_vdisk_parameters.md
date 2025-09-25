# VDS_CREATE_VDISK_PARAMETERS structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Contains the parameters to be used when a virtual disk is created.

## Members

### `UniqueId`

A unique GUID value to be assigned to the virtual disk.

### `MaximumSize`

The maximum virtual size, in bytes, of the virtual disk object.

### `BlockSizeInBytes`

The internal block size, in bytes, of the virtual disk object.

### `SectorSizeInBytes`

Internal sector size, in bytes, of the virtual disk object.

### `pParentPath`

A **NULL**-terminated wide-character string that contains an optional path to a parent virtual disk object. This member associates the new virtual disk with an existing virtual disk.

### `pSourcePath`

A **NULL**-terminated wide-character string that contains an optional path to a source of data to be copied to the new virtual disk.

## See also

[IVdsVdProvider::CreateVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvdprovider-createvdisk)