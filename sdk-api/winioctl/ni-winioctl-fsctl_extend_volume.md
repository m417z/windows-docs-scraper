# FSCTL_EXTEND_VOLUME IOCTL

## Description

Increases the size of a mounted volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  FSCTL_EXTEND_VOLUME,          // dwIoControlCode
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

This control code is supported on NTFS, RAW, and ReFS file systems.

This control code cannot be used to reduce the size of a volume. The new volume size must be at least one cluster larger than the previous volume size. The underlying partition must have enough sectors to contain the extended volume. If not, [IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_grow_partition) can be used if the underlying device has enough space available.

You can extend a live volume, and the volume can be open for sharing during the extend operation.

You do not need to lock a volume that you are extending, nor do you need to shut down other applications or services during the extend operation.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | Yes

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_SHRINK_VOLUME](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_shrink_volume)
* [IOCTL_DISK_GROW_PARTITION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_grow_partition)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)