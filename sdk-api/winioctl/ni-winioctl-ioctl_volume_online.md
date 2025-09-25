# IOCTL_VOLUME_ONLINE IOCTL

## Description

Brings a volume online.

**Windows Server 2003 and Windows XP:** This control code is not supported for dynamic disks.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_VOLUME_ONLINE,          // dwIoControlCode
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

When a volume is offline, all read, write, and IOCTL requests fail with **ERROR_NOT_READY**. You cannot take the system or boot volume offline.

When a volume is online, all requests sent to the volume are honored.

When a volume that is online is dismounted, the next call to open the volume causes it to be mounted. Taking the volume offline prevents the dismounted volume from being mounted again.

To take a volume offline, use the [IOCTL_VOLUME_OFFLINE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_volume_offline) control code.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | No

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [IOCTL_VOLUME_OFFLINE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_volume_offline)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)