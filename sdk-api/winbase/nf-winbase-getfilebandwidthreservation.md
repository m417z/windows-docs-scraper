# GetFileBandwidthReservation function

## Description

Retrieves the bandwidth reservation properties of the volume on which the specified file resides.

## Parameters

### `hFile` [in]

A handle to the file.

### `lpPeriodMilliseconds` [out]

A pointer to a variable that receives the period of the reservation, in milliseconds. The period is the
time from which the I/O is issued to the kernel until the time the I/O should be completed. If no bandwidth has
been reserved for this handle, then the value returned is the minimum reservation period supported for this
volume.

### `lpBytesPerPeriod` [out]

A pointer to a variable that receives the maximum number of bytes per period that can be reserved on the
volume. If no bandwidth has been reserved for this handle, then the value returned is the maximum number of
bytes per period supported for the volume.

### `pDiscardable` [out]

**TRUE** if I/O should be completed with an error if a driver is unable to satisfy an
I/O operation before the period expires. **FALSE** if the underlying subsystem does not
support failing in this manner.

### `lpTransferSize` [out]

The minimum size of any individual I/O request that may be issued by the application. All I/O requests
should be multiples of *TransferSize*. If no bandwidth has been reserved for this
handle, then the value returned is the minimum transfer size supported for this volume.

### `lpNumOutstandingRequests` [out]

The number of *TransferSize* chunks allowed to be outstanding with the operating
system.

## Return value

Returns nonzero if successful or zero otherwise.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SetFileBandwidthReservation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilebandwidthreservation)