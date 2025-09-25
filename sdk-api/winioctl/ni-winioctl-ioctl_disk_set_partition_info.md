# IOCTL_DISK_SET_PARTITION_INFO IOCTL

## Description

> [!NOTE]
> **IOCTL_DISK_SET_PARTITION_INFO** has been superseded by [**IOCTL_DISK_SET_PARTITION_INFO_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex), which retrieves layout information for AT and EFI (Extensible Firmware Interface) partitions.

Sets partition information for the specified disk partition.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_DISK_SET_PARTITION_INFO,    // dwIoControlCode
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

If the partition is on a disk formatted as type master boot record (MBR), partition size totals are limited. For more information, see the Remarks section of [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout).

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [IOCTL_DISK_GET_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info)
* [IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex)
* [SET_PARTITION_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-set_partition_information)