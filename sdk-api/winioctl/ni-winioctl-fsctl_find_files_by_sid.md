# FSCTL_FIND_FILES_BY_SID IOCTL

## Description

Searches a directory for a file whose creator owner matches the specified SID.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to volume
  FSCTL_FIND_FILES_BY_SID,      // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
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

This control code requires the use of [disk quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas) on the volume.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | Yes
SMB 3.0 with Scale-out File Shares (SO) | Yes
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | No

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FIND_BY_SID_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-find_by_sid_data)
* [FIND_BY_SID_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-find_by_sid_output)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)