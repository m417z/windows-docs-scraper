# IOCTL_DISK_GROW_PARTITION IOCTL

## Description

Enlarges the specified partition.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_GROW_PARTITION,    // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of the input buffer
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

You can extend or shrink a live partition, and the partition can be open for sharing during the extend or shrink operation.

You do not need to lock a partition that you are extending, nor do you need to shut down other applications or services during the extend operation.

For more information, see [DISK_GROW_PARTITION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_grow_partition).

## See also

* [DISK_GROW_PARTITION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_grow_partition)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)