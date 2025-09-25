# FSCTL_REPAIR_COPIES IOCTL

## Description

Repair data corruption by selecting the proper copy to use. This control code was introduced in Windows 8 and Windows Server 2012 for use on Storage Spaces and Streams on NTFS and ReFS and non-integrity streams on ReFS (streams with integrity on ReFS handle this automatically.)

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE)  hDevice,                // handle to file or directory
  FSCTL_REPAIR_COPIES,              // dwIoControlCode
  (LPDWORD) pInBuffer,              // REPAIR_COPIES_INPUT
  (DWORD)   InBufferSize,           // size of input buffer
  (LPDWORD) pOutBuffer,             // REPAIR_COPIES_OUTPUT
  (DWORD)   OutBufferSize,          // size of output buffer
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

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_GET_INTEGRITY_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_integrity_information)
* [REPAIR_COPIES_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-repair_copies_output)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)