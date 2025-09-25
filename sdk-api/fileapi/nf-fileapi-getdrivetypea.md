# GetDriveTypeA function

## Description

Determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network
drive.

To determine whether a drive is a USB-type drive, call
[SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)
and specify the **SPDRP_REMOVAL_POLICY** property.

## Parameters

### `lpRootPathName` [in, optional]

The root directory for the drive.

A trailing backslash is required. If this parameter is **NULL**, the function uses the
root of the current directory.

## Return value

The return value specifies the type of drive, which can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **DRIVE_UNKNOWN**<br><br>0 | The drive type cannot be determined. |
| **DRIVE_NO_ROOT_DIR**<br><br>1 | The root path is invalid; for example, there is no volume mounted at the specified path. |
| **DRIVE_REMOVABLE**<br><br>2 | The drive has removable media; for example, a floppy drive, thumb drive, or flash card reader. |
| **DRIVE_FIXED**<br><br>3 | The drive has fixed media; for example, a hard disk drive or flash drive. |
| **DRIVE_REMOTE**<br><br>4 | The drive is a remote (network) drive. |
| **DRIVE_CDROM**<br><br>5 | The drive is a CD-ROM drive. |
| **DRIVE_RAMDISK**<br><br>6 | The drive is a RAM disk. |

## Remarks

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB does not support volume management functions.

> [!NOTE]
> The fileapi.h header defines GetDriveType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)