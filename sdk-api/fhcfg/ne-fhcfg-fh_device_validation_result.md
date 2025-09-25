# FH_DEVICE_VALIDATION_RESULT enumeration

## Description

Indicates whether the storage device or network share can be used as a File History backup target.

## Constants

### `FH_ACCESS_DENIED:0`

The storage device or network share cannot be used as a backup target, because it is not accessible.

### `FH_INVALID_DRIVE_TYPE`

The storage device or network share cannot be used as a backup target, because the drive type is not supported. For example, a CD or DVD cannot be used as a File History backup target.

### `FH_READ_ONLY_PERMISSION`

The storage device or network share cannot be used as a backup target, because it is read-only.

### `FH_CURRENT_DEFAULT`

The storage device or network share is already being used as a backup target.

### `FH_NAMESPACE_EXISTS`

The storage device or network share was previously used to back up files from a computer or user that has the same name as the current computer or user. It can be used as a backup target, but if it is used, the operating system will delete the previous backup.

### `FH_TARGET_PART_OF_LIBRARY`

The storage device or network share cannot be used as a backup target, because it is in the File History protection scope.

### `FH_VALID_TARGET`

The storage device or network share can be used as a backup target.

### `MAX_VALIDATION_RESULT`

The maximum enumeration value for this enumeration. This value and all values greater than it are reserved for system use.

## See also

[IFhConfigMgr::ValidateTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-validatetarget)