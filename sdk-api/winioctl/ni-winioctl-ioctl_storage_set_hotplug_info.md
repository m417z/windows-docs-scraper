# IOCTL_STORAGE_SET_HOTPLUG_INFO IOCTL

## Description

Sets the hotplug configuration of the specified device.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_STORAGE_SET_HOTPLUG_INFO,   // dwIoControlCode
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

Refer to the Remarks section in the reference page for [STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hotplug_info) for more information about hotplug devices.

This operation sets only the **DeviceHotplug** member of the [STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hotplug_info) structure passed in.

## See also

* [Device Management Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-management-control-codes)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [IOCTL_STORAGE_GET_HOTPLUG_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_get_hotplug_info)
* [STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hotplug_info)