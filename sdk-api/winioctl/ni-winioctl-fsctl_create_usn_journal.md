# FSCTL_CREATE_USN_JOURNAL IOCTL

## Description

Creates an update sequence number (USN) change journal stream on a target volume, or modifies an existing change journal
stream.

| C++ |
| --- |
| ``` BOOL  WINAPI  DeviceIoControl( (HANDLE) hDevice,              // handle to volume                  FSCTL_CREATE_USN_JOURNAL,      // dwIoControlCode(LPVOID) lpInBuffer,           // input buffer                  (DWORD) nInBufferSize,         // size of input buffer                  NULL,                          // lpOutBuffer                  0,                             // nOutBufferSize(LPDWORD) lpBytesReturned,     // number of bytes returned                  (LPOVERLAPPED) lpOverlapped ); // OVERLAPPED structure ``` |

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

You can use **FSCTL_CREATE_USN_JOURNAL** to create
a new change journal stream for a volume. After the creation of the stream, the NTFS file system maintains a
change journal for that volume.

You can also use **FSCTL_CREATE_USN_JOURNAL** to
modify an existing change journal stream. If a change journal stream already exists,
**FSCTL_CREATE_USN_JOURNAL** sets it to the
characteristics provided in the
[CREATE_USN_JOURNAL_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_usn_journal_data)
structure. The change journal stream eventually gets larger or is trimmed to the new size limit that
[CREATE_USN_JOURNAL_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_usn_journal_data)
imposes.

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

To retrieve a handle to a volume, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string in the following form:

\\.\*X*:

In the preceding string, *X* is the letter identifying the drive on which the
volume appears. The volume must be NTFS 3.0 or later. To obtain the NTFS version of a volume, open a command
prompt with Administrator access rights and execute the following command:

**fsutil fsinfo ntfsinfo** *X***:**

where *X* is the drive letter of the volume.

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |

## See also

[CREATE_USN_JOURNAL_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-create_usn_journal_data)

[Change Journals](https://learn.microsoft.com/windows/desktop/FileIO/change-journals)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)