# SET_VIRTUAL_DISK_INFO_VERSION enumeration

## Description

Contains the version of the virtual disk
[SET_VIRTUAL_DISK_INFO](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-set_virtual_disk_info) structure to use in calls to
VHD functions. Use the different versions of the structure to set different kinds of information for the VHD.

## Constants

### `SET_VIRTUAL_DISK_INFO_UNSPECIFIED:0`

Not used. Will fail the operation.

### `SET_VIRTUAL_DISK_INFO_PARENT_PATH:1`

Parent information is being set.

### `SET_VIRTUAL_DISK_INFO_IDENTIFIER:2`

A unique identifier is being set.

**Note** If the VHD's unique identifier changes as a result of the
**SET_VIRTUAL_DISK_INFO_IDENTIFIER** operation, it will break any existing differencing
chains on the VHD.

### `SET_VIRTUAL_DISK_INFO_PARENT_PATH_WITH_DEPTH:3`

Sets the parent file path and the child depth.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `SET_VIRTUAL_DISK_INFO_PHYSICAL_SECTOR_SIZE:4`

Sets the physical sector size reported by the VHD.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `SET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID:5`

The identifier that is uniquely created when a user first creates the virtual disk to attempt to uniquely identify that virtual disk.

**Windows 8 and Windows Server 2012:** This value is not supported before Windows 8.1 and Windows Server 2012 R2.

### `SET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE:6`

Whether resilient change tracking (RCT) is turned on for the virtual disk.

**Windows 8.1 and Windows Server 2012 R2:** This value is not supported before Windows 10 and Windows Server 2016.

### `SET_VIRTUAL_DISK_INFO_PARENT_LOCATOR:7`

The parent linkage information that differencing VHDs store. Parent linkage information is metadata used to locate and correctly identify the next parent in the virtual disk chain.

**Windows 8.1 and Windows Server 2012 R2:** This value is not supported before Windows 10 and Windows Server 2016.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))