# FSCTL_GET_COMPRESSION IOCTL

## Description

Retrieves the current compression state of a file or directory on a volume whose file system supports per-stream compression.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to file
  FSCTL_GET_COMPRESSION,        // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
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

The LZNT1 compression algorithm is the only compression algorithm implemented.

COMPRESSION_FORMAT_DEFAULT is not a compression state so it is not included in the table under the *lpOutBuffer* parameter. This value is only used with the [FSCTL_SET_COMPRESSION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_compression) control code.

If the file system of the volume containing the specified file or directory does not support per-file or per-directory compression, the operation fails.

You can set the compression state of a file or directory by using the [FSCTL_SET_COMPRESSION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_compression) control code. You can also compress or uncompress a file using this control code.

You can retrieve the compression attribute of a file or directory by calling the [GetFileAttributes](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesa) function. The compression attribute indicates whether a file or directory is compressed. The compression state indicates whether a file or directory is compressed, and, if it is, the format of the compressed data.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | No

SMB 3.0 Transparent Failover and Scale-Out do not support NTFS compressed files. The FSCTL call is not blocked, but unsupported.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_SET_COMPRESSION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_compression)
* [File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)
* [GetFileAttributes](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesa)