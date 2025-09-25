# FSCTL_WRITE_USN_CLOSE_RECORD IOCTL

## Description

Generates a record in the update sequence number (USN) change journal stream for the input
file. This record will have the **USN_REASON_CLOSE** flag.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following
parameters.

| C++ |
| --- |
| ``` BOOL  WINAPI DeviceIoControl( (HANDLE) hDevice,              // handle to volume                  FSCTL_WRITE_USN_CLOSE_RECORD,  // dwIoControlCodeNULL,                          // lpInBuffer0,                             // nInBufferSize(LPVOID) lpOutBuffer,          // output buffer                  (DWORD) nOutBufferSize,        // size of output buffer                  (LPDWORD) lpBytesReturned,     // number of bytes returned                  (LPOVERLAPPED) lpOverlapped ); // OVERLAPPED structure ``` |

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

For the implications of overlapped I/O on this operation, see the Remarks section for
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol).

You can use **FSCTL_WRITE_USN_CLOSE_RECORD**
to force a close record into the change journal for the input handle. The close record will contain any current
USN reasons for this file as well. The output buffer will return the USN value associated with this
operation.

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

To retrieve a handle to a volume, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string in the following form:

\\.\*X*:

In the preceding string, *X* is the letter identifying the drive on which the volume
appears. The volume must be NTFS 3.0 or later. To obtain the NTFS version of a volume, open a command prompt with
Administrator access rights and execute the following command:

**fsutil fsinfo ntfsinfo** *X***:**

where *X* is the drive letter of the volume.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |

### Transacted Operations

If **FSCTL_WRITE_USN_CLOSE_RECORD** is called
with a handle that is locked by a transaction, it always fails.

## See also

[Change Journals](https://learn.microsoft.com/windows/desktop/FileIO/change-journals)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)