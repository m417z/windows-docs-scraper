# IOCTL_CHANGER_GET_STATUS IOCTL

## Description

Retrieves the current status of the specified device.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_CHANGER_GET_STATUS,     // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
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

## See also

* [Device Management Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-management-control-codes)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)