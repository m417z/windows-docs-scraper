# IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS IOCTL

## Description

Initializes the status of all elements or the specified elements of a particular type.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                         // handle to device
  IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS,  // dwIoControlCode
  (LPVOID) lpInBuffer,                      // input buffer
  (DWORD) nInBufferSize,                    // size of input buffer
  NULL,                                     // lpOutBuffer
  0,                                        // nOutBufferSize
  (LPDWORD) lpBytesReturned,                // number of bytes returned
  (LPOVERLAPPED) lpOverlapped               // OVERLAPPED structure
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

* [CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_initialize_element_status)
* [Device Management Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-management-control-codes)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)