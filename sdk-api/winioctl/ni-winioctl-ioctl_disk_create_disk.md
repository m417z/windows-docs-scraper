# IOCTL_DISK_CREATE_DISK IOCTL

## Description

Initializes the specified disk and disk partition table using the information in the [CREATE_DISK](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-create_disk) structure.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_CREATE_DISK,       // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
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

When specifying a GUID partition table (GPT) as the [PARTITION_STYLE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-partition_style) of the [CREATE_DISK](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-create_disk) structure, an application should wait for the MSR partition arrival before sending the [IOCTL_DISK_SET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout_ex) control code. For more information about device notification, see [RegisterDeviceNotification](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerdevicenotificationa).

## See also

* [CREATE_DISK](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-create_disk)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)