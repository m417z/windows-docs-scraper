# CREATE_VIRTUAL_DISK_VERSION enumeration

## Description

Contains the version of the virtual disk
[CREATE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-create_virtual_disk_parameters)
structure to use in calls to virtual disk functions.

## Constants

### `CREATE_VIRTUAL_DISK_VERSION_UNSPECIFIED:0`

Not supported.

### `CREATE_VIRTUAL_DISK_VERSION_1:1`

The **Version1** member structure will be used.

### `CREATE_VIRTUAL_DISK_VERSION_2:2`

The **Version2** member structure will be used.

**Windows 7 and Windows Server 2008 R2:** This value is not supported until Windows 8 and Windows Server 2012.

### `CREATE_VIRTUAL_DISK_VERSION_3:3`

### `CREATE_VIRTUAL_DISK_VERSION_4:4`

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))