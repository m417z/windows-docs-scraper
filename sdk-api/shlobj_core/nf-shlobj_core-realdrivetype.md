# RealDriveType function

## Description

[**RealDriveType** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines the drive type based on the drive number.

## Parameters

### `iDrive` [in]

Type: **int**

The number of the drive that you want to test. "A:" corresponds to 0, "B:" to 1, and so on.

### `fOKToHitNet` [in]

Type: **BOOL**

Reserved. Must be set to 0.

## Return value

Type: **int**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **DRIVE_UNKNOWN** | The drive type cannot be determined. |
| **DRIVE_NO_ROOT_DIR** | The root path is invalid. For example, no volume is mounted at the path. |
| **DRIVE_REMOVABLE** | The disk can be removed from the drive. |
| **DRIVE_FIXED** | The disk cannot be removed from the drive. |
| **DRIVE_REMOTE** | The drive is a remote (network) drive. |
| **DRIVE_CDROM** | The drive is a CD-ROM drive. |
| **DRIVE_RAMDISK** | The drive is a RAM disk. |

## See also

[DriveType](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-drivetype)

[GetDriveType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdrivetypea)