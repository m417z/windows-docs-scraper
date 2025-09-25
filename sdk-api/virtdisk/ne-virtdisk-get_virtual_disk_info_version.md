# GET_VIRTUAL_DISK_INFO_VERSION enumeration

## Description

Contains the kinds of virtual hard disk (VHD) information that you can retrieve. For more information,
see [GET_VIRTUAL_DISK_INFO](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-get_virtual_disk_info).

## Constants

### `GET_VIRTUAL_DISK_INFO_UNSPECIFIED:0`

Reserved. This value should not be used.

### `GET_VIRTUAL_DISK_INFO_SIZE:1`

Information related to the virtual disk size, including total size, physical allocation used, block size,
and sector size.

### `GET_VIRTUAL_DISK_INFO_IDENTIFIER:2`

The unique identifier. This identifier is persistently stored in the virtual disk and will not change even
if the virtual disk file is copied to another file.

### `GET_VIRTUAL_DISK_INFO_PARENT_LOCATION:3`

The paths to parent virtual disks. Valid only for differencing virtual disks.

### `GET_VIRTUAL_DISK_INFO_PARENT_IDENTIFIER:4`

The unique identifier of the parent virtual disk. Valid only for differencing virtual disks.

### `GET_VIRTUAL_DISK_INFO_PARENT_TIMESTAMP:5`

The time stamp of the parent when the child virtual disk was created. Valid only for differencing virtual
disks.

### `GET_VIRTUAL_DISK_INFO_VIRTUAL_STORAGE_TYPE:6`

The device identifier and vendor identifier that identify the type of virtual disk.

### `GET_VIRTUAL_DISK_INFO_PROVIDER_SUBTYPE:7`

The type of virtual disk.

### `GET_VIRTUAL_DISK_INFO_IS_4K_ALIGNED:8`

Indicates whether the virtual disk is 4 KB aligned.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `GET_VIRTUAL_DISK_INFO_PHYSICAL_DISK:9`

Details about the physical disk on which the virtual disk resides.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `GET_VIRTUAL_DISK_INFO_VHD_PHYSICAL_SECTOR_SIZE:10`

The physical sector size of the virtual disk.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `GET_VIRTUAL_DISK_INFO_SMALLEST_SAFE_VIRTUAL_SIZE:11`

The smallest safe minimum size of the virtual disk.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `GET_VIRTUAL_DISK_INFO_FRAGMENTATION:12`

The fragmentation level of the virtual disk.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `GET_VIRTUAL_DISK_INFO_IS_LOADED:13`

Whether the virtual disk is currently mounted and in use.

**Windows 8 and Windows Server 2012:** This value is not supported before Windows 8.1 and Windows Server 2012 R2.

### `GET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID:14`

The identifier that is uniquely created when a user first creates the virtual disk to attempt to uniquely identify that virtual disk.

**Windows 8 and Windows Server 2012:** This value is not supported before Windows 8.1 and Windows Server 2012 R2.

### `GET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE:15`

The state of resilient change tracking (RCT) for the virtual disk.

**Windows 8.1 and Windows Server 2012 R2:** This value is not supported before Windows 10 and Windows Server 2016.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[GET_VIRTUAL_DISK_INFO](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-get_virtual_disk_info)

[GetVirtualDiskInformation](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getvirtualdiskinformation)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))