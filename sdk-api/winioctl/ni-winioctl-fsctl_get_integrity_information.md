# FSCTL_GET_INTEGRITY_INFORMATION IOCTL

## Description

Retrieves the integrity status of a file or directory on a ReFS volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file or directory
  FSCTL_GET_INTEGRITY_INFORMATION,  // dwIoControlCode
  (LPDWORD) NULL,                   // pInBuffer
  (DWORD) 0,                        // InBufferSize
  (LPDWORD) pOutBuffer,             // FSCTL_GET_INTEGRITY_INFORMATION_BUFFER
  (DWORD) OutBufferSize,            // size of output buffer
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
* [FSCTL_GET_INTEGRITY_INFORMATION_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-fsctl_get_integrity_information_buffer)
* [FSCTL_SET_INTEGRITY_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_integrity_information)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)