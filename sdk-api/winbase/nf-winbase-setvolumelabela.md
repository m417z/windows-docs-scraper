# SetVolumeLabelA function

## Description

Sets the label of a file system volume.

## Parameters

### `lpRootPathName` [in, optional]

A pointer to a string that contains the volume's drive letter (for example, X:\) or the path
of a mounted folder that is associated with the volume (for example, Y:\MountX\). The string must
end with a trailing backslash ('\'). If this parameter is **NULL**, the root of the
current directory is used.

### `lpVolumeName` [in, optional]

A pointer to a string that contains the new label for the volume. If this parameter is
**NULL**, the function deletes any existing label from the specified volume and does not
assign a new label.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The maximum volume label length is 32 characters.

**FAT filesystems:** The maximum volume label length is 11 characters.

A label is a user-friendly name that a user assigns to a volume to make it easier to recognize. A volume can
have a label, a drive letter, both, or neither. For more information, see
[Naming a Volume](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-volume).

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
> The winbase.h header defines SetVolumeLabel as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)