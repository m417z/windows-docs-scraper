# FSCTL_READ_FILE_USN_DATA IOCTL

## Description

Retrieves the update sequence number (USN) change-journal information for the specified file or
directory.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following
parameters.

| C++ |
| --- |
| ``` BOOL  WINAPI  DeviceIoControl( (HANDLE)       hDevice,         // handle to device                  (DWORD) FSCTL_READ_FILE_USN_DATA, // dwIoControlCode                  (LPVOID)       lpInBuffer,      // input buffer                  (DWORD)        nInBufferSize,   // size of input buffer                  (LPVOID)       lpOutBuffer,     // output buffer                  (DWORD)        nOutBufferSize,  // size of output buffer                  (LPDWORD)      lpBytesReturned, // number of bytes returned                  (LPOVERLAPPED) lpOverlapped );  // OVERLAPPED structure ``` |

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

If the call succeeds, the members of the returned
[USN_RECORD_V2](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2) or
[USN_RECORD_V3](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v3) structure are valid except for the following
members: **TimeStamp**, **Reason**, and
**SourceInfo**. The **Usn** member represents the last USN written
to the journal for this file or directory.

For more information, see
[Creating, Modifying, and Deleting a Change Journal](https://learn.microsoft.com/windows/desktop/FileIO/creating-modifying-and-deleting-a-change-journal).

To retrieve a handle to a volume, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string in the following form:

\\.\*X*:

In the preceding string, *X* is the letter identifying the drive on which the volume
appears. The volume must be ReFS or NTFS 3.0 or later. To obtain the NTFS version of a volume, open a command prompt with
Administrator access rights and execute the following command:

**FSUtil.exe FSInfo NTFSInfo** *X***:**

where *X* is the drive letter of the volume.

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

[USN_RECORD](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-usn_record_v2)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)