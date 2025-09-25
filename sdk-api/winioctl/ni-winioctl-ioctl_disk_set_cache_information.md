# IOCTL_DISK_SET_CACHE_INFORMATION IOCTL

## Description

Sets the disk configuration data.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_DISK_SET_CACHE_INFORMATION, // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  NULL,                             // lpOutBuffer
  0,                                // nOutBufferSize
  (LPDWORD) lpBytesReturned,        // number of bytes returned
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

To retrieve the cache information, use the [IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_cache_information) control code.

## See also

* [DISK_CACHE_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_cache_information)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [IOCTL_DISK_GET_CACHE_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_cache_information)