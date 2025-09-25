# FSCTL_FILE_LEVEL_TRIM IOCTL

## Description

Indicates ranges within the specified file that do not need to be stored by the storage system.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // Handle to a file
  FSCTL_FILE_LEVEL_TRIM,            // dwIoControlCode
  (LPVOID) lpInBuffer,              // Input buffer
  (DWORD) nInBufferSize,            // Size of input buffer
  (LPVOID) lpOutBuffer,             // Output buffer
  (DWORD) nOutBufferSize,           // Size of output buffer
  (LPDWORD) lpBytesReturned,        // Number of bytes returned
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

The **FSCTL_FILE_LEVEL_TRIM** control code is a hint to the underlying storage system. When a range of bytes has been trimmed, if that range is later read again, the data returned may be the original data before the trim operation—all zeros (0x00 bytes), all ones (0xff bytes), or a combination of these. Before the trim operation is passed to the underlying storage system, the input ranges are reduced to align with page boundaries (4,096 bytes on 32-bit and x64-based editions of Windows, 8,192 bytes on Itanium-Based editions of Windows).

If an error occurs while processing the [FILE_LEVEL_TRIM_RANGE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_level_trim_range) entries that follow the [FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_level_trim) structure in the input buffer pointed to by the *lpInBuffer* parameter, processing stops and the **NumRangesProcessed** member of the [FILE_LEVEL_TRIM_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_level_trim_output) structure pointed to by the *lpOutBuffer* parameter will indicate the ranges that were successfully processed. Any ranges between **NumRangesProcessed** and the **NumRanges** member of the **FILE_LEVEL_TRIM** structure were not processed.

The **FSCTL_FILE_LEVEL_TRIM** control code is not compatible with encrypted or compressed files ([GetFileAttributes](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesa) returns **FILE_ATTRIBUTE_ENCRYPTED** or **FILE_ATTRIBUTE_COMPRESSED**) and will fail with **ERROR_INVALID_PARAMETER**. Sparse files (indicated by **FILE_ATTRIBUTE_SPARSE_FILE**) are supported, but only ranges that have been allocated can be trimmed. Files on volumes encrypted by BitLocker technology are supported, while individually encrypted files are not.

The **FSCTL_FILE_LEVEL_TRIM** control code does not participate in transactions. If a **FSCTL_FILE_LEVEL_TRIM** control code is processed during a transaction, and the transaction is aborted, the trim will not be rolled back with the transaction.

Ranges that are successfully trimmed will be removed from the filesystem cache.

Ranges that are trimmed can be beyond the valid data length (VDL) up to the end-of-file (EOF).

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | Yes
SMB 3.0 with Scale-out File Shares (SO) | Yes
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | No

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_level_trim)
* [FILE_LEVEL_TRIM_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_level_trim_output)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)