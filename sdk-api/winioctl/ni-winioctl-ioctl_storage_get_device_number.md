# IOCTL_STORAGE_GET_DEVICE_NUMBER IOCTL

## Description

Retrieves the device type, device number, and, for a partitionable device, the partition number of a device.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_STORAGE_GET_DEVICE_NUMBER,  // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
  (LPVOID), lpOutBuffer,            // output buffer
  (DWORD), nOutBufferSize,          // size of output buffer
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

The values in the [STORAGE_DEVICE_NUMBER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_device_number) structure are guaranteed to remain unchanged until the device is removed or the system is restarted. It is not guaranteed to be persistent across device restarts or system restarts.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [STORAGE_DEVICE_NUMBER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_device_number)