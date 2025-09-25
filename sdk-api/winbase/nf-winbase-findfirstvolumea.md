# FindFirstVolumeA function

## Description

Retrieves the name of a volume on a computer. **FindFirstVolume** is used to begin scanning the volumes of a computer.

## Parameters

### `lpszVolumeName` [out]

A pointer to a buffer that receives a null-terminated string that specifies a volume
**GUID** path for the first volume that is found.

### `cchBufferLength` [in]

The length of the buffer to receive the volume **GUID** path, in
**TCHARs**.

## Return value

If the function succeeds, the return value is a search handle used in a subsequent call to the
[FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew) and
[FindVolumeClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findvolumeclose) functions.

If the function fails to find any volumes, the return value is the
**INVALID_HANDLE_VALUE** error code. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **FindFirstVolume** function opens a volume search handle and returns
information about the first volume found on a computer. After the search handle is established, you can use the
[FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew) function to search for other volumes. When
the search handle is no longer needed, close it by using the
[FindVolumeClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findvolumeclose) function.

You should not assume any correlation between the order of the volumes that are returned by these functions
and the order of the volumes that are on the computer. In particular, do not assume any correlation between volume
order and drive letters as assigned by the BIOS (if any) or the Disk Administrator.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB does not support volume management functions.

#### Examples

For an example, see
[Displaying Volume Paths](https://learn.microsoft.com/windows/desktop/FileIO/displaying-volume-paths).

## See also

[FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew)

[FindVolumeClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findvolumeclose)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)