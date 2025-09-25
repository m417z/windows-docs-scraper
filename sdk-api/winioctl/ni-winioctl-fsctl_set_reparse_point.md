# FSCTL_SET_REPARSE_POINT IOCTL

## Description

Sets a reparse point on a file or directory.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file or directory
  FSCTL_SET_REPARSE_POINT,          // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  NULL,                             // lpOutBuffer
  0,                                // nOutBufferSize
  NULL,                             // lpBytesReturned
  (LPOVERLAPPED) lpOverlapped       // OVERLAPPED structure
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

For the implications of overlapped I/O on this operation, see the Remarks section of [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol).

Note that the time stamps may not be updated correctly for a remote file. To ensure consistent results, use unbuffered I/O.

The calling process must have the SE_CREATE_SYMBOLIC_LINK_NAME privilege. For more information, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

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

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_delete_reparse_point)
* [FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_reparse_point)
* [REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/ns-ntifs-_reparse_data_buffer)
* [REPARSE_GUID_DATA_BUFFER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-reparse_guid_data_buffer)
* [Reparse Points](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points)