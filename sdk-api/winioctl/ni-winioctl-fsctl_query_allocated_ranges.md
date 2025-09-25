# FSCTL_QUERY_ALLOCATED_RANGES IOCTL

## Description

Scans a file or alternate stream looking for ranges that may contain nonzero data. Only compressed or sparse files can have zeroed ranges known to the operating system. For other files, the output buffer will contain only a single entry that contains the starting point and the length requested.
To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file
  FSCTL_QUERY_ALLOCATED_RANGES,     // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  (LPVOID) lpOutBuffer,             // output buffer
  (DWORD) nOutBufferSize,           // size of output buffer
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

For the implications of overlapped I/O on this operation, see the Remarks section of [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol).

The NTFS file system rounds the input file offset down to a convenient boundary and the length up to a convenient boundary and then begins to walk through the file.

The operating system does not track every piece of zero (0) or nonzero data. Because zero (0) is often a perfectly legal datum, it would be misleading. Instead, the system tracks ranges where disk space is allocated. Where no disk space is allocated, all data are assumed to be zero (0). Allocated storage can contain zero (0) or nonzero data. So all this operation does is return information about parts of the file where nonzero data may be located. It is up to the application to scan these parts of the file in accordance with the application's data conventions.

Each entry in the output array contains an offset and a length that indicates a range in the file that may contain nonzero data. The actual nonzero data, if any, is somewhere within this range, and the calling program must scan further within the range to locate it and determine if it really is valid data. Multiple instances of valid data may exist within the range.

Allocated ranges are subject to the rule that a memory mapped remote (network) file and an open handle to the file are not necessarily coherent. If you memory mapped a sparse network file and wrote nonzero data to previously unallocated regions of the file, disk space would be allocated for the new data. However, a call to **FSCTL_QUERY_ALLOCATED_RANGES** thereafter would not necessarily return a correct list of allocated regions. To ensure coherency between the view memory and the file handle, flush the data to the file with the [FlushViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-flushviewoffile) function.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | Yes
SMB 3.0 with Scale-out File Shares (SO) | Yes
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | No

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FILE_ALLOCATED_RANGE_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_allocated_range_buffer)
* [FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_sparse)
* [FSCTL_SET_ZERO_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_zero_data)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)
* [Sparse Files](https://learn.microsoft.com/windows/desktop/FileIO/sparse-files)