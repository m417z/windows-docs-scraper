# IOCTL_DISK_FORMAT_TRACKS_EX IOCTL

## Description

Formats a specified, contiguous set of tracks on a floppy disk.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_FORMAT_TRACKS_EX,  // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
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

This device I/O control operation is for floppy disk devices only.

It is impossible to determine how many bad track numbers will be returned by this control code, so you should set the size of the array pointed to by the *lpOutBuffer* parameter to the following:

`(total number of tracks on the floppy disk) * sizeof(BAD_TRACK_NUMBER)`

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [FORMAT_EX_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-format_ex_parameters)