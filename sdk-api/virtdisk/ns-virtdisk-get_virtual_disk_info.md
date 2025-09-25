# GET_VIRTUAL_DISK_INFO structure

## Description

Contains virtual hard disk (VHD) information.

## Members

### `Version`

A value of the
[GET_VIRTUAL_DISK_INFO_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-get_virtual_disk_info_version) enumeration
that specifies the version of the
**GET_VIRTUAL_DISK_INFO** structure being passed to
or from the virtual disk functions. This determines what parts of this structure will be used.

### `Size`

A structure with the following members. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_SIZE**.

### `Size.VirtualSize`

Virtual size of the virtual disk, in bytes.

### `Size.PhysicalSize`

Physical size of the virtual disk on physical disk, in bytes.

### `Size.BlockSize`

Block size of the virtual disk, in bytes.

### `Size.SectorSize`

Sector size of the virtual disk, in bytes.

### `Identifier`

Unique identifier of the virtual disk. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_IDENTIFIER**.

### `ParentLocation`

A structure with the following members. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_PARENT_LOCATION**.

### `ParentLocation.ParentResolved`

Parent resolution. **TRUE** if the parent backing store was successfully resolved,
**FALSE** if not.

### `ParentLocation.ParentLocationBuffer`

If the **ParentResolved** member is **TRUE**, contains the
path of the parent backing store.

If the **ParentResolved** member is **FALSE**, contains all of
the parent paths present in the search list.

### `ParentIdentifier`

Unique identifier of the parent disk backing store. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_PARENT_IDENTIFIER**.

### `ParentTimestamp`

Internal time stamp of the parent disk backing store. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_PARENT_TIMESTAMP**.

### `VirtualStorageType`

[VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure containing
information about the type of virtual disk. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_VIRTUAL_STORAGE_TYPE**.

### `ProviderSubtype`

Provider-specific subtype. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_PROVIDER_SUBTYPE**.

| Value | Meaning |
| --- | --- |
| 2 | Fixed. |
| 3 | Dynamically expandable (sparse). |
| 4 | Differencing. |

### `Is4kAligned`

Indicates whether the virtual disk is 4 KB aligned. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_IS_4K_ALIGNED**.

**Windows 7 and Windows Server 2008 R2:** This is not supported before Windows 8 and Windows Server 2012.

### `IsLoaded`

Indicates whether the virtual disk is currently mounted and in use. **TRUE** if the virtual disk is currently mounted and in use; otherwise **FALSE**. Set the **Version** member to **GET_VIRTUAL_DISK_INFO_IS_LOADED**.

**Windows 8 and Windows Server 2012:** This is not supported before Windows 8.1 and Windows Server 2012 R2.

### `PhysicalDisk`

Details about the physical disk on which the virtual disk resides. Set the
**Version** member to
**GET_VIRTUAL_DISK_INFO_PHYSICAL_DISK**.

**Windows 7 and Windows Server 2008 R2:** This is not supported before Windows 8 and Windows Server 2012.

### `PhysicalDisk.LogicalSectorSize`

The logical sector size of the physical disk.

### `PhysicalDisk.PhysicalSectorSize`

The physical sector size of the physical disk.

### `PhysicalDisk.IsRemote`

Indicates whether the physical disk is remote.

### `VhdPhysicalSectorSize`

The physical sector size of the virtual disk. Set the **Version** member to
**GET_VIRTUAL_DISK_INFO_VHD_PHYSICAL_SECTOR_SIZE**.

**Windows 7 and Windows Server 2008 R2:** This is not supported before Windows 8 and Windows Server 2012.

### `SmallestSafeVirtualSize`

The smallest safe minimum size of the virtual disk. Set the
**Version** member to
**GET_VIRTUAL_DISK_INFO_SMALLEST_SAFE_VIRTUAL_SIZE**.

**Windows 7 and Windows Server 2008 R2:** This is not supported before Windows 8 and Windows Server 2012.

### `FragmentationPercentage`

The fragmentation level of the virtual disk. Set the
**Version** member to
**GET_VIRTUAL_DISK_INFO_FRAGMENTATION**.

**Windows 7 and Windows Server 2008 R2:** This is not supported before Windows 8 and Windows Server 2012.

### `VirtualDiskId`

The identifier that is uniquely created when a user first creates the virtual disk to attempt to uniquely identify that virtual disk. Set the **Version** member to **GET_VIRTUAL_DISK_INFO_VIRTUAL_DISK_ID**.

**Windows 8 and Windows Server 2012:** This is not supported before Windows 8.1 and Windows Server 2012 R2.

### `ChangeTrackingState`

The state of resilient change tracking (RCT) for the virtual disk. Set the **Version** member to **GET_VIRTUAL_DISK_INFO_CHANGE_TRACKING_STATE**.

**Windows 8.1 and Windows Server 2012 R2:** This member is not supported before Windows 10 and Windows Server 2016.

### `ChangeTrackingState.Enabled`

Whether RCT is turned on. **TRUE** if RCT is turned on; otherwise **FALSE**.

### `ChangeTrackingState.NewerChanges`

Whether the virtual disk has changed since the change identified by the **MostRecentId** member occurred. **TRUE** if the virtual disk has changed since the change identified by the **MostRecentId** member occurred; otherwise **FALSE**.

### `ChangeTrackingState.MostRecentId`

The change tracking identifier for the change that identifies the state of the virtual disk that you want to use as the basis of comparison to determine whether the **NewerChanges** member reports new changes.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[GET_VIRTUAL_DISK_INFO_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-get_virtual_disk_info_version)

[GetVirtualDiskInformation](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getvirtualdiskinformation)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))