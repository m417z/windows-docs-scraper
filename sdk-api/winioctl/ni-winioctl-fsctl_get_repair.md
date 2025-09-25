# FSCTL_GET_REPAIR IOCTL

## Description

Retrieves information about the NTFS file system's self-healing mechanism.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,              // handle to device
  FSCTL_GET_REPAIR,              // dwIoControlCode
  NULL,                          // lpInBuffer
  0,                             // nInBufferSize
  (ULONG) lpOutBuffer,           // output buffer
  (DWORD) nOutBufferSize,        // size of output buffer
  (LPDWORD) lpBytesReturned,     // number of bytes returned
  (LPOVERLAPPED) lpOverlapped    // OVERLAPPED structure
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

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | No

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_INITIATE_REPAIR](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_initiate_repair)
* [FSCTL_SET_REPAIR](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_repair)
* [FSCTL_WAIT_FOR_REPAIR](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_wait_for_repair)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)