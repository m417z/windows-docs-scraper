# FSCTL_ENUM_USN_DATA IOCTL

## Description

Enumerates the update sequence number (USN) data between two specified boundaries to obtain master
file table (MFT) records.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following
parameters.

| C++ |
| --- |
| ``` BOOL  WINAPI  DeviceIoControl( (HANDLE) hDevice,              // handle to volume                  (DWORD) FSCTL_ENUM_USN_DATA,   // dwIoControlCode(LPVOID) lpInBuffer,           // input buffer                  (DWORD) nInBufferSize,         // size of input buffer                  (LPVOID) lpOutBuffer,          // output buffer                  (DWORD) nOutBufferSize,        // size of output buffer                  (LPDWORD) lpBytesReturned,     // number of bytes returned                  (LPOVERLAPPED) lpOverlapped ); // OVERLAPPED structure); ``` |

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

To enumerate files on a volume, use the
**FSCTL_ENUM_USN_DATA** operation one or more times. On the
first call, set the starting point, the **StartFileReferenceNumber** member of the
[MFT_ENUM_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-mft_enum_data_v0) structure, to
`(DWORDLONG)0`. Each call to
**FSCTL_ENUM_USN_DATA** retrieves the starting point for
the subsequent call as the first entry in the output buffer.

By comparing To identify recent changes to a volume, use the
[FSCTL_READ_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_read_usn_journal) control code.

To retrieve a handle to a volume, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string in the following form:

\\\\.\*X*:

In the preceding string, *X* is the letter identifying the drive on which the volume
appears. The volume must be NTFS.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_READ_USN_JOURNAL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_read_usn_journal)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[MFT_ENUM_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-mft_enum_data_v0)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[USN_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)