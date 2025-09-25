# FSCTL_GET_REPARSE_POINT IOCTL

## Description

Retrieves the reparse point data associated with the file or directory identified by the specified handle.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to file or directory
  FSCTL_GET_REPARSE_POINT,      // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
  (LPVOID) lpOutBuffer,         // output buffer
  (DWORD) nOutBufferSize,       // size of output buffer
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

Otherwise, Status is set to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For the implications of overlapped I/O on this operation, see the Remarks section of
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol).

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | Yes
SMB 3.0 with Scale-out File Shares (SO) | Yes
Cluster Shared Volume File System (CsvFS) | No
Resilient File System (ReFS) | Yes

CsvFs does not support reparse points.

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_delete_reparse_point)
* [FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_reparse_point)
* [REPARSE_GUID_DATA_BUFFER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-reparse_guid_data_buffer)
* [Reparse Points](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points)