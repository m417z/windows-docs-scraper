# FSCTL_CSV_QUERY_DOWN_LEVEL_FILE_SYSTEM_CHARACTERISTICS IOCTL

## Description

Retrieves information about a file system for which CSVFS is a proxy.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                                       // handle to device
  FSCTL_CSV_QUERY_DOWN_LEVEL_FILE_SYSTEM_CHARACTERISTICS, // dwIoControlCode
  NULL,                                                   // input buffer
  0,                                                      // size of input buffer
  (LPVOID) lpOutBuffer,                                   // lpOutBuffer
  (DWORD) nOutBufferSize,                                 // nOutBufferSize
  (LPDWORD) lpBytesReturned,                              // number of bytes returned
  (LPOVERLAPPED) lpOverlapped                             // OVERLAPPED structure
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

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FILE_FS_ATTRIBUTE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/ns-ntifs-_file_fs_attribute_information)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)