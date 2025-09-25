# FSCTL_IS_FILE_ON_CSV_VOLUME IOCTL

## Description

Determines whether a file is stored on a CSVFS volume, or retrieves namespace information.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  FSCTL_IS_FILE_ON_CSV_VOLUME,  // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
  (LPVOID) lpOutBuffer,         // lpOutBuffer
  (DWORD) nOutBufferSize,       // nOutBufferSize
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

To determine whether a file is stored on a CSVFS volume, simply leave the *lpInBuffer* parameter empty. If the file is on a CSVFS volume, the *lpOutBuffer* parameter will contain **ERROR_SUCCESS**.

To retrieve namespace information, specify a pointer to the same [CSV_NAMESPACE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_namespace_info) structure that is initially empty (except for the **Version** member) in both the *lpInBuffer* and *lpOutBuffer* parameters. The information in that structure is filled in by the function call.

## See also

* [CSV_NAMESPACE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_namespace_info)
* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)