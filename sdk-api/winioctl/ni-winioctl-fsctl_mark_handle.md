# FSCTL_MARK_HANDLE IOCTL

## Description

Marks a specified file or directory and its change journal record with information about changes to that file or directory.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to file or directory
  FSCTL_MARK_HANDLE,            // dwIoControlCode
  (LPVOID)lpInBuffer,           // input buffer
  (DWORD)nInBufferSize,         // size of input buffer
  NULL,                         // lpOutBuffer
  0,                            // nOutBufferSize
  (LPDWORD) lpBytesReturned,    // number of bytes returned
  (LPOVERLAPPED) lpOverlapped   // OVERLAPPED structure
);
```

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

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

**FSCTL_MARK_HANDLE** is the only change journal operation that operates on an individual file or directory. It does not affect anything the user can do with the item. Instead, it adds information to the file or directory, either providing information on how the operating system changed the item or adding a private data stream to the item.

If there are any changes to the file or directory, then the information added with **FSCTL_MARK_HANDLE** is also copied into the USN record created for the file or directory. Note that these two operations can occur independently of each other—for example, it is not necessary for a USN record to exist to be able to mark a file as unable to be defragmented and it is not necessary to mark a file or directory to update the contents of the corresponding USN record. For details on the information with which **FSCTL_MARK_HANDLE** can mark an item (see [MARK_HANDLE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-mark_handle_info) for more information).

It is not an error to use **FSCTL_MARK_HANDLE** while the volume's change journal is being deleted or is inactive. The appropriate information is applied to the file or directory regardless of the state of the change journal, as long as the change journal exists.

Note that the time stamps may not be updated correctly for a remote file. To ensure consistent results, use unbuffered I/O.

The volume must be NTFS.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes

CsvFs always issues **USN_SOURCE_REPLICATION_MANAGEMENT** and **MARK_HANDLE_PROTECT_CLUSTERS** for the files eligible for direct IO.

## See also

* [Change Journals](https://learn.microsoft.com/windows/desktop/FileIO/change-journals)
* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [MARK_HANDLE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-mark_handle_info)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)