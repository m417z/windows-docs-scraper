# IOCTL_DISK_GET_LENGTH_INFO IOCTL

## Description

Retrieves the length of the specified disk, volume, or partition.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_GET_LENGTH_INFO,   // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
  (LPVOID) lpOutBuffer,         // output buffer
  (DWORD) nOutBufferSize,       // size of output buffer
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

Volume handles do not have access to the full volume. To read or write to the last few sectors of a volume, you must call [FSCTL_ALLOW_EXTENDED_DASD_IO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_allow_extended_dasd_io), which instructs the file system to not perform any boundary checks.

This operation should be used instead of [IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex) for volumes that do not have partition info—such as partition type or number of hidden sectors.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [GET_LENGTH_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-get_length_information)