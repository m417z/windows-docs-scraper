# IOCTL_STORAGE_EJECT_MEDIA IOCTL

## Description

Ejects media from a SCSI device.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_STORAGE_EJECT_MEDIA,    // dwIoControlCode
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

## Remarks

**IOCTL_STORAGE_EJECT_MEDIA** may or may not be supported on SCSI devices that support removable media.

## See also

* [Device Management Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-management-control-codes)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [IOCTL_STORAGE_LOAD_MEDIA](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_load_media)
* [IOCTL_STORAGE_MEDIA_REMOVAL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_media_removal)