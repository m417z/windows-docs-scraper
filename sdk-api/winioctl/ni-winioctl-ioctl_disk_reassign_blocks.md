# IOCTL_DISK_REASSIGN_BLOCKS IOCTL

## Description

Directs the disk device to map one or more blocks to its spare-block pool.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_REASSIGN_BLOCKS,   // dwIoControlCode
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

The [REASSIGN_BLOCKS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-reassign_blocks) structure that the **IOCTL_DISK_REASSIGN_BLOCKS** control code uses only supports drives where the Logical Block Address (LBA) fits into a 4-byte value (typically up to 2 TB). For larger drives the [REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-reassign_blocks_ex) structure that the [IOCTL_DISK_REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks_ex) control code uses supports 8-byte LBAs. For compatibility, the **IOCTL_DISK_REASSIGN_BLOCKS** control code and **REASSIGN_BLOCKS** structure should be used where possible.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [IOCTL_DISK_REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks_ex)
* [REASSIGN_BLOCKS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-reassign_blocks)
* [REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-reassign_blocks_ex)