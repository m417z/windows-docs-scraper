# IOCTL_DISK_RESET_SNAPSHOT_INFO IOCTL

## Description

Clears all Volume Shadow Copy Service (VSS) hardware-based shadow copy (also called "snapshot") information from the disk.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_DISK_RESET_SNAPSHOT_INFO,   // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
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

The disk whose handle is used when this IOCTL is issued might be in the offline state when the IOCTL is issued. If the disk is put in the offline state by using the disk management Microsoft Management Console (MMC) snap-in, the disk will have its read-only attribute set, which will cause this IOCTL to fail. However, if the disk partition utility (Diskpart.exe) is used to put the disk in the offline state, the read-only attribute for the disk is not set. For this reason, it is best to use the disk partition utility to put a disk in the offline state.

> [!NOTE]
> One side effect of using this IOCTL is that Disk Management tools will now report an additional partition on GPT disks of the type "UNKNOWN." This 256KB partition is created by using the IOCTL and is the shadow copy partition that is used in the restore process. The partition is expected and can be ignored by system administrators.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)