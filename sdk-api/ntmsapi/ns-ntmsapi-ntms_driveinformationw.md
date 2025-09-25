# NTMS_DRIVEINFORMATIONW structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_DRIVEINFORMATION** structure defines properties specific to a drive object.

## Members

### `Number`

Number of the drive in the library. This is set zero or one relative the value based on the drive numbering system of the device. Some changers number drives beginning with zero, and some changers begin with one.

### `State`

State of the drive. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_DRIVESTATE_BEING_CLEANED** | The drive is being cleaned and is unavailable. |
| **NTMS_DRIVESTATE_DISMOUNTABLE** | If a library is set for lazy dismounts, the medium might be left in the library's drive on a dismount. RSM can satisfy mount requests for loaded and dismounted drives. |
| **NTMS_DRIVESTATE_DISMOUNTED** | No medium in the drive. |
| **NTMS_DRIVESTATE_LOADED** | The medium is mounted in the drive and is loaded for read and write access. |
| **NTMS_DRIVESTATE_MOUNTED** | The medium is mounted in the drive but is not ready for read and write access. This is a temporary state that is used while a drive is waiting for spindle synchronization or loading tape media into the head mechanism. |
| **NTMS_DRIVESTATE_UNLOADED** | The medium has been dismounted by the drive and is ready to be opened. This state indicates that the spindle has stopped or a tape media has been returned to the tape cartridge. |

### `DriveType`

Unique identifier of the drive type object containing the attributes for the drive.

### `szDeviceName`

Name of the device used to access the drive. For a tape drive this contains the device name \\.\tape0 or \\.\tape1. Other devices provide the name of a SCSI disk drive or the root of a file system that currently has the device mounted (raw, NTFS, FAT and so forth).

### `szSerialNumber`

Serial number for the drive represented as a string. Devices that do not support serial numbers report NULL for this member.

### `szRevision`

Revision for the drive represented as a string.

### `ScsiPort`

SCSI host adapter to which the drive is connected.

### `ScsiBus`

SCSI bus to which the drive is connected.

### `ScsiTarget`

SCSI target ID for the drive.

### `ScsiLun`

SCSI logical unit ID for the drive.

### `dwMountCount`

Number of times the drive has had a medium mounted to it. If the drive supports the reporting of a unique serial number, this value is the number of times the drive has been mounted since it was installed. If the drive does not support the reporting of serial numbers, this member reflects the number of mounts to all of the drives at that location.

### `LastCleanedTs`

Last time the drive was cleaned.

### `SavedPartitionId`

Partition identifier of the medium that is in the drive. If this value is NULL and the drive is found to be full, the media was loaded by a user and needs to be classified.

### `Library`

Unique identifier of the library that contains the drive.

### `Reserved`

Reserved.

### `dwDeferDismountDelay`

Minimum number of seconds a medium will remain in a drive of a library after a deferred dismount has been performed. The default is 5 minutes. This member does not apply to stand-alone libraries. This member is writable.

## Remarks

The
**NTMS_DRIVEINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

> [!NOTE]
> The ntmsapi.h header defines NTMS_DRIVEINFORMATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)