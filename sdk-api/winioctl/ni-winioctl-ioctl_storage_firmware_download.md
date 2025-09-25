# IOCTL_STORAGE_FIRMWARE_DOWNLOAD IOCTL

## Description

Windows applications can use this control code to download a firmware image to the target device, but not activate it. If the image to be downloaded is larger than the controller’s maximum data transfer size, this IOCTL will have to be called multiple times until the entire image is downloaded.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_STORAGE_FIRMWARE_DOWNLOAD,  // dwIoControlCode
  (LPDWORD) lpInBuffer,             // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  (LPDWORD) lpOutBuffer,            // output buffer
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
* [IOCTL_STORAGE_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_firmware_activate)
* [IOCTL_STORAGE_FIRMWARE_GET_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_firmware_get_info)
* [STORAGE_HW_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_firmware_activate)
* [STORAGE_HW_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_firmware_download)
* [STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info)
* [STORAGE_HW_FIRMWARE_INFO_QUERY](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info-query)
* [STORAGE_HW_FIRMWARE_SLOT_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-slot-info)