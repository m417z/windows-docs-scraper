# SetFileBandwidthReservation function

## Description

Requests that bandwidth for the specified file stream be reserved. The reservation is specified as a
number of bytes in a period of milliseconds for I/O requests on the specified file handle.

## Parameters

### `hFile` [in]

A handle to the file.

### `nPeriodMilliseconds` [in]

The period of the reservation, in milliseconds. The period is the time from which the I/O is issued to the
kernel until the time the I/O should be completed. The minimum supported value for the file
stream can be determined by looking at the value returned through the
*lpPeriodMilliseconds* parameter to the
[GetFileBandwidthReservation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilebandwidthreservation) function,
on a handle that has not had a bandwidth reservation set.

### `nBytesPerPeriod` [in]

The bandwidth to reserve, in bytes per period. The maximum supported value for the file
stream can be determined by looking at the value returned through the
*lpBytesPerPeriod* parameter to the
[GetFileBandwidthReservation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilebandwidthreservation) function,
on a handle that has not had a bandwidth reservation set.

### `bDiscardable` [in]

Indicates whether I/O should be completed with an error if a driver is unable to satisfy an I/O operation
before the period expires. If one of the drivers for the specified file stream does not support this
functionality, this function may return success and ignore the flag. To verify whether the setting will be
honored, call the
[GetFileBandwidthReservation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilebandwidthreservation) function
using the same *hFile* handle and examine the **pDiscardable*
return value.

### `lpTransferSize` [out]

A pointer to a variable that receives the minimum size of any individual I/O request that may be issued by
the application. All I/O requests should be multiples of *TransferSize*.

### `lpNumOutstandingRequests` [out]

A pointer to a variable that receives the number of *TransferSize* chunks the
application should allow to be outstanding with the operating system. This allows the storage stack to keep the
device busy and allows maximum throughput.

## Return value

Returns nonzero if successful or zero otherwise.

A reservation can fail if there is not enough bandwidth available on the volume because of existing
reservations; in this case **ERROR_NO_SYSTEM_RESOURCES** is returned.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The requested bandwidth reservation must be greater than or equal to one packet per period. The minimum period,
in milliseconds, maximum bytes per period, and minimum transfer size, in bytes, for a specific volume are
returned through the *lpPeriodMilliseconds*, *lpBytesPerPeriod*,
and *lpTransferSize* parameters to
[GetFileBandwidthReservation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilebandwidthreservation) on a
handle that has not been used in a call to
**SetFileBandwidthReservation**. In other
words:

1 ≤ (*nBytesPerPeriod*)×(**lpPeriodMilliseconds*)/(**lpTransferSize*)/(*nPeriodMilliseconds*)

IIn Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFileBandwidthReservation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilebandwidthreservation)