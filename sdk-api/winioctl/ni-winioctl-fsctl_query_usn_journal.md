# FSCTL_QUERY_USN_JOURNAL IOCTL

## Description

Queries for information on the current update sequence number (USN) change journal, its records, and
its capacity.

| C++ |
| --- |
| ``` BOOL  WINAPI  DeviceIoControl( (HANDLE)       Device,          // handle to volume                  (DWORD) FSCTL_QUERY_USN_JOURNAL,// dwIoControlCode                  (LPVOID)       NULL,            // lpInBuffer                  (DWORD)        0,               // nInBufferSize                  (LPVOID)       lpOutBuffer,     // output buffer                  (DWORD)        nOutBufferSize,  // size of output buffer                  (LPDWORD)      lpBytesReturned, // number of bytes returned                  (LPOVERLAPPED) lpOverlapped );  // OVERLAPPED structure ``` |

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following
parameters.

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For the implications of overlapped I/O on this operation, see the Remarks section of the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

To retrieve a handle to a volume, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string in the following form:

\\.\*X*:

In the preceding string, *X* is the letter identifying the drive on which the volume
appears. The volume must be formatted with the NTFS filesystem.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |

An application may experience false positives on CsvFs pause/resume.

## See also

[Change Journals](https://learn.microsoft.com/windows/desktop/FileIO/change-journals)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[USN_JOURNAL_DATA_V0](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_journal_data_v0)

[USN_JOURNAL_DATA_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh802707(v=vs.85))

[USN_JOURNAL_DATA_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_journal_data_v2)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)