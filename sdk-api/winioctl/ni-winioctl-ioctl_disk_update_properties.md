# IOCTL_DISK_UPDATE_PROPERTIES IOCTL

## Description

Invalidates the cached partition table and re-enumerates the device.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_UPDATE_PROPERTIES, // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
  NULL,                         // lpOutBuffer
  0,                            // nOutBufferSize
  (LPDWORD)lpBytesReturned,     // lpBytesReturned
  (LPDWORD) lpOverlapped        // lpOverlapped
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

This operation is used in synchronizing the system view of the specified disk device when the partition table of the disk is directly modified. Be sure to perform this operation when you update the usable space for a disk so that the system will update its partition table.

You can update the properties of a live volume, and the volume can be open for sharing during the update operation.

You do not need to lock a volume that you are updating, nor do you need to shut down other applications or services during the update operation.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)