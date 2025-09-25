# IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD IOCTL

## Description

Windows applications can use this control code to set the temperature threshold of a device (when it's supported by the device). Use [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) to determine if the device supports changing the over and under temperature thresholds.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                         // handle to device
  IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD,  // dwIoControlCode
  (LPDWORD) lpInBuffer,                     // input buffer
  (DWORD) nInBufferSize,                    // size of input buffer
  (LPDWORD) lpOutBuffer,                    // output buffer
  (DWORD) nOutBufferSize,                   // size of output buffer
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

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_property_id)
* [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query)
* [STORAGE_TEMPERATURE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_temperature_info)
* [STORAGE_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_temperature_threshold)