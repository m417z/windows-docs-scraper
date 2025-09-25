# FSCTL_CSV_CONTROL IOCTL

## Description

Retrieves the results of a CSV control operation.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.
```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  FSCTL_CSV_CONTROL,            // dwIoControlCode
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

## See also

* [CSV_CONTROL_OP](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-csv_control_op)
* [CSV_CONTROL_PARAM](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_control_param)
* [CSV_QUERY_FILE_REVISION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_file_revision)
* [CSV_QUERY_MDS_PATH](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_mds_path)
* [CSV_QUERY_REDIRECT_STATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_query_redirect_state)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)