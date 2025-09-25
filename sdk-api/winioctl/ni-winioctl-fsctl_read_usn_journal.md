# FSCTL_READ_USN_JOURNAL IOCTL

## Description

Retrieves the set of update sequence number (USN) change journal records between two specified USN
values.

| C++ |
| --- |
| ``` BOOL  WINAPI  DeviceIoControl( (HANDLE)       hDevice,         // handle to volume                  (DWORD) FSCTL_READ_USN_JOURNAL, // dwIoControlCode                  (LPVOID)       lpInBuffer,      // input buffer                  (DWORD)        nInBufferSize,   // size of input buffer                  (LPVOID)       lpOutBuffer,     // output buffer                  (DWORD)        nOutBufferSize,  // size of output buffer                  (LPDWORD)      lpBytesReturned, // number of bytes returned                  (LPOVERLAPPED) lpOverlapped );  // OVERLAPPED structure ``` |

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

There are two [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) control codes that
return USN records, **FSCTL_READ_USN_JOURNAL** and
[FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data). Use the latter when you want a
listing (enumeration) of the USN records between two USNs. Use the former when you want to select by USN.

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

To retrieve a handle to a volume, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string in the following form:

\\.\*X*:

In the preceding string, *X* is the letter identifying the drive on which the volume
appears. The volume must be NTFS.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | See comment |

An application may experience false positives on CsvFs pause/resume.

#### Examples

For an example, see
[Walking a Buffer of Change Journal Records](https://learn.microsoft.com/windows/desktop/FileIO/walking-a-buffer-of-change-journal-records).

## See also

[Change Journals](https://learn.microsoft.com/windows/desktop/FileIO/change-journals)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_enum_usn_data)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[READ_USN_JOURNAL_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-read_usn_journal_data_v0)

[USN_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)