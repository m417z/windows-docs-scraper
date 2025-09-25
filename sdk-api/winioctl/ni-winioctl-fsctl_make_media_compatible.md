# FSCTL_MAKE_MEDIA_COMPATIBLE IOCTL

## Description

Closes an open UDF session on write-once media to make the media ROM compatible. Used in conjunction with **FILE_SEQUENTIAL_WRITE_ONCE** volume flag. This call must be issued on the volume handle.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,              // handle to device
  FSCTL_MAKE_MEDIA_COMPATIBLE,   // dwIoControlCode
  (LPVOID) lpInBuffer,           // input buffer
  (DWORD) nInBufferSize,         // size of input buffer
  NULL,                          // output buffer
  0,                             // size of output buffer
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
Cluster Shared Volume File System (CsvFS) | No
Resilient File System (ReFS) | No

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FILE_MAKE_COMPATIBLE_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_make_compatible_buffer)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)