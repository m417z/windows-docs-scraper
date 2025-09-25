# IOCTL_DISK_GET_DISK_ATTRIBUTES IOCTL

## Description

Retrieves the attributes of the specified disk device.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_DISK_GET_DISK_ATTRIBUTES,   // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
  (LPVOID) lpOutBuffer,             // output buffer: GET_DISK_ATTRIBUTES
  (DWORD) nOutBufferSize,           // size of output buffer
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

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [GET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-get_disk_attributes)
* [IOCTL_DISK_SET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_disk_attributes)