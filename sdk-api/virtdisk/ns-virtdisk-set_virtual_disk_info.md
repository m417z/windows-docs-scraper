# SET_VIRTUAL_DISK_INFO structure

## Description

Contains virtual hard disk (VHD) information to use when you call the [SetVirtualDiskInformation](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-setvirtualdiskinformation) function to set VHD properties.

## Members

### `Version`

A [SET_VIRTUAL_DISK_INFO_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-set_virtual_disk_info_version)
enumeration that specifies the version of the
**SET_VIRTUAL_DISK_INFO** structure being passed to or
from the VHD functions. This determines the type of information set.

### `ParentFilePath`

The path to the parent backing store. Set the **Version** member to
**SET_VIRTUAL_DISK_INFO_PARENT_PATH** (1).

### `UniqueIdentifier`

The unique identifier of the VHD. Set the **Version** member to
**SET_VIRTUAL_DISK_INFO_IDENTIFIER** (2).

### `ParentPathWithDepthInfo`

Sets the parent file path and the child depth. Set the **Version** member to
**SET_VIRTUAL_DISK_INFO_PARENT_PATH_WITH_DEPTH** (3).

**Windows 7 and Windows Server 2008 R2:** This is not supported before Windows 8 and Windows Server 2012.

### `ParentPathWithDepthInfo.ChildDepth`

Specifies the depth to the child from the leaf. The leaf itself is at depth 1.

### `ParentPathWithDepthInfo.ParentFilePath`

Specifies the depth to the parent from the leaf. The leaf itself is at depth 1.

### `VhdPhysicalSectorSize`

Sets the physical sector size reported by the VHD. Set the **Version** member to
**SET_VIRTUAL_DISK_INFO_PHYSICAL_SECTOR_SIZE** (4).**Windows 7 and Windows Server 2008 R2:** This is not supported before Windows 8 and Windows Server 2012.

### `VirtualDiskId`

The identifier that is uniquely created when a user first creates the virtual disk to attempt to uniquely identify that virtual disk. Set the **Version** member to
**SET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID** (5).

**Windows 8 and Windows Server 2012:** This is not supported before Windows 8.1 and Windows Server 2012 R2.

### `ChangeTrackingEnabled`

Turns resilient change tracking (RCT) on or off for the VHD. **TRUE** turns RCT on. **FALSE** turns RCT off. Set the **Version** member to
**SET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE** (6).

**Windows 8.1 and Windows Server 2012 R2:** This member is not supported before Windows 10 and Windows Server 2016.

### `ParentLocator`

Sets the parent linkage information that differencing VHDs store. Parent linkage information is metadata used to locate and correctly identify the next parent in the virtual disk chain. Set the **Version** member to
**SET_VIRTUAL_DISK_INFO_PARENT_LOCATOR** (7).

**Windows 8.1 and Windows Server 2012 R2:** This member is not supported before Windows 10 and Windows Server 2016.

### `ParentLocator.LinkageId`

The unique identifier for the parent linkage information.

### `ParentLocator.ParentFilePath`

The path of the file for the parent VHD.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))