# FSCTL_SET_ZERO_DATA IOCTL

## Description

Fills a specified range of a file with zeros (0). If the file is sparse or compressed, the NTFS file system may deallocate disk space in the file. This sets the range of bytes to zeros (0) without extending the file size.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to a file
  FSCTL_SET_ZERO_DATA,              // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
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

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

If you use the [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile) function to write zeros (0) to a sparse file, the file system allocates disk space for the data that you are writing. If you use the **FSCTL_SET_ZERO_DATA** control code to write zeros (0) to a sparse file and the zero (0) region is large enough, the file system may not allocate disk space.

If you use the **FSCTL_SET_ZERO_DATA** control code to write zeros (0) to a non-sparse file, zeros (0) are written to the file. The system allocates disk storage for all of the zero (0) range, which is equivalent to using the [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile) function to write zeros (0) to a file.

The time stamps may not be updated correctly for a remote file. To ensure consistent results, use unbuffered I/O.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | Yes
SMB 3.0 with Scale-out File Shares (SO) | Yes
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | Yes

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FILE_ZERO_DATA_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_zero_data_information)
* [FSCTL_QUERY_ALLOCATED_RANGES](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_query_allocated_ranges)
* [FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_sparse)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)
* [Sparse Files](https://learn.microsoft.com/windows/desktop/FileIO/sparse-files)