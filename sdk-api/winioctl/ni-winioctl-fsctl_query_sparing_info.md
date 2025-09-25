# FSCTL_QUERY_SPARING_INFO IOCTL

## Description

Retrieves the defect management properties of the volume. Used for UDF file systems.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  FSCTL_QUERY_SPARING_INFO,     // dwIoControlCode
  NULL,                         // input buffer
  0,                            // size of input buffer
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

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

One scenario this control code can be used for is by an application that reports volume statistics to the user and warns if the volume is running out of free storage space.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | Yes
SMB 3.0 with Scale-out File Shares (SO) | Yes
Cluster Shared Volume File System (CsvFS) | No
Resilient File System (ReFS) | Yes

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FILE_QUERY_SPARING_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_query_sparing_buffer)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)