# FSCTL_SHRINK_VOLUME IOCTL

## Description

Signals that the volume is to be prepared to perform the shrink operation, the shrink operation is to be committed, or the shrink operation is to be terminated.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  FSCTL_SHRINK_VOLUME,          // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  nInBufferSize,                // size of input buffer
  NULL,                         // output buffer
  O,                            // size of output buffer
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

This control code is only supported on NTFS and RAW file systems.

To complete a shrink operation, you must:
1. Call [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) to open a handle to the volume.
1. Call **FSCTL_SHRINK_VOLUME**. Set the **ShrinkRequestType** member of the [SHRINK_VOLUME_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-shrink_volume_information) structure to **ShrinkPrepare**. Set the **NewNumberOfSectors** member of the same structure to zero. If this call succeeds, the filesystem will not allocate clusters beyond the end of the new volume length.
1. Call [FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_move_file) on all files beyond the new number of sectors and move them within the valid range. You are responsible for moving any files that are affected by the shrink operation.
1. Call **FSCTL_SHRINK_VOLUME**. Set the **ShrinkRequestType** member of the [SHRINK_VOLUME_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-shrink_volume_information) structure to **ShrinkCommit**. Set the **NewNumberOfSectors** member of the same structure to zero. If all files beyond the end of the new volume size have not been moved, the call fails with **STATUS_ALREADY_COMMITTED** (**ERROR_ACCESS_DENIED**). Otherwise, the filesystem has now been shrunk.
1. Call [IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_grow_partition). Set the **BytesToGrow** member of the [DISK_GROW_PARTITION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_grow_partition) structure to the negative number that represents the number of bytes to remove.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | See comment

Is supported only on the node that has NTFS mounted.

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_EXTEND_VOLUME](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_extend_volume)
* [IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_grow_partition)
* [SHRINK_VOLUME_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-shrink_volume_information)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)