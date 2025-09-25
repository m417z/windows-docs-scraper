# FindVolumeClose function

## Description

Closes the specified volume search handle. The [FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) and
[FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew) functions use this search handle to locate volumes.

## Parameters

### `hFindVolume` [in]

The volume search handle to be closed. This handle must have been previously opened by the
[FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After the
**FindVolumeClose** function is called, the handle *hFindVolume* cannot be used in subsequent calls to either
[FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew) or
**FindVolumeClose**.

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

[FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew)

[FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)