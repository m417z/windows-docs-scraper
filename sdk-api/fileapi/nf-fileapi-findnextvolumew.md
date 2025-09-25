# FindNextVolumeW function

## Description

Continues a volume search started by a call to the
[FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) function. **FindNextVolume** finds one volume per call.

## Parameters

### `hFindVolume` [in]

The volume search handle returned by a previous call to the
[FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) function.

### `lpszVolumeName` [out]

A pointer to a string that receives the volume **GUID** path that is found.

### `cchBufferLength` [in]

The length of the buffer that receives the volume **GUID** path, in
**TCHARs**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If no matching files can be found, the
**GetLastError** function returns the
**ERROR_NO_MORE_FILES** error code. In that case, close the search with the
[FindVolumeClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findvolumeclose) function.

## Remarks

After the search handle is established by calling
[FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew), you can use the
**FindNextVolume** function to search for other volumes.

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

[FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew)

[FindVolumeClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findvolumeclose)

[Mounted Folders](https://learn.microsoft.com/windows/desktop/FileIO/volume-mount-points)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)