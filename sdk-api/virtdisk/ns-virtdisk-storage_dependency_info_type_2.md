# STORAGE_DEPENDENCY_INFO_TYPE_2 structure

## Description

Contains VHD or ISO storage dependency information for type 2.

## Members

### `DependencyTypeFlags`

A [DEPENDENT_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-dependent_disk_flag) enumeration.

### `ProviderSpecificFlags`

Flags specific to the VHD provider.

### `VirtualStorageType`

A [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure.

### `AncestorLevel`

The ancestor level.

### `DependencyDeviceName`

The device name of the dependent device. If the device is a virtual hard drive then this will be in the
form \\.\PhysicalDrive*N*. If the device is a virtual CD or DVD drive
(ISO) then this will be in the form \\.\CDRom*N*. In either case
*N* is an integer that represents a unique identifier for the caller's host
system.

### `HostVolumeName`

The host disk volume name in the form \\?\Volume{*GUID*}\ where
*GUID* is the **GUID** that identifies the volume.

### `DependentVolumeName`

The name of the dependent volume, if any, in the form
\\?\Volume{*GUID*}\ where *GUID* is the
**GUID** that identifies the volume.

### `DependentVolumeRelativePath`

The relative path to the dependent volume.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))