# IOCTL_DISK_GET_PARTITION_INFO IOCTL

## Description

Retrieves information about the type, size, and nature of a disk partition.

> [!NOTE]
> **IOCTL_DISK_GET_PARTITION_INFO** is superseded by [IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex), which retrieves partition information for AT and Extensible Firmware Interface (EFI) partitions.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to a partition
  IOCTL_DISK_GET_PARTITION_INFO,    // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
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

## Remarks

The **IOCTL_DISK_GET_PARTITION_INFO** control code is only supported on MBR-formatted disks.

The disk support can be summarized as follows.

Disk type | IOCTL_DISK_GET_PARTITION_INFO | IOCTL_DISK_GET_PARTITION_INFO_EX
----------|-------------------------------|---------------------------------
Basic master boot record (MBR) | Yes | Yes
Basic GUID partition table (GPT) | No | Yes
Dynamic MBR boot/system | Yes | Yes
Dynamic MBR data | Yes | No
Dynamic GPT boot/system | No | Yes
Dynamic GPT data | No | No

Currently, GPT is supported only on 64-bit systems.

If the partition is on a disk formatted as type master boot record (MBR), partition size totals are limited. For more information, see the Remarks section of [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout).

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [File System Recognition](https://learn.microsoft.com/windows/desktop/FileIO/file-system-recognition)
* [IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex)
* [IOCTL_DISK_SET_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info)
* [PARTITION_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-partition_information)