# IOCTL_CHANGER_GET_ELEMENT_STATUS IOCTL

## Description

Retrieves the status of all elements or a specified number of elements of a particular type.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_CHANGER_GET_ELEMENT_STATUS, // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  (LPVOID) lpOutBuffer,             // output buffer
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

* [CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_element_status)
* [CHANGER_ELEMENT_STATUS_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_element_status_ex)
* [CHANGER_READ_ELEMENT_STATUS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_read_element_status)
* [Device Management Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-management-control-codes)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)