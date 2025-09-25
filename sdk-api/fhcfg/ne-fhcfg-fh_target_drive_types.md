# FH_TARGET_DRIVE_TYPES enumeration

## Description

Specifies the type of a File History backup target.

## Constants

### `FH_DRIVE_UNKNOWN:0`

The type of the backup target is unknown.

### `FH_DRIVE_REMOVABLE:2`

The backup target is a locally attached removable storage device, such as a USB thumb drive.

### `FH_DRIVE_FIXED:3`

The backup target is a locally attached nonremovable storage device, such as an internal hard drive.

### `FH_DRIVE_REMOTE:4`

The backup target is a storage device that is accessible over network, such as a computer that is running Windows Home Server.

## See also

[IFhTarget::GetNumericalProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getnumericalproperty)