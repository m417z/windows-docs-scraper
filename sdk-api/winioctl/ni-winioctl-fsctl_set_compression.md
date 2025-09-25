# FSCTL_SET_COMPRESSION IOCTL

## Description

Sets the compression state of a file or directory on a volume whose file system supports per-file and per-directory compression. You can use **FSCTL_SET_COMPRESSION** to compress or uncompress a file or directory on such a volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file or directory
  FSCTL_SET_COMPRESSION,            // dwIoControlCode
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

The LZNT1 compression algorithm is the only compression algorithm implemented. As a result, the LZNT1 compression algorithm is used as the DEFAULT compression method.

If the file system of the volume containing the specified file or directory does not support per-file or per-directory compression, the operation fails.

The compression state change of the file or directory occurs synchronously with the call to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol).

To retrieve the compression state of a file or directory, use the [FSCTL_GET_COMPRESSION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_compression) control code.

To retrieve the compression attribute of a file or directory, use the [GetFileAttributes](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesa) function. The compression attribute indicates whether a file or directory is compressed. The compression state indicates whether a file or directory is compressed and, if it is, the format of the compressed data.

Directories are not actually compressed by this operation. Rather, the operation sets the default state for files created in the directory to be compressed.

Note that the time stamps may not be updated correctly for a remote file. To ensure consistent results, use unbuffered I/O.

File compression is supported for files of a maximum uncompressed size of 30 gigabytes.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | See comment
Resilient File System (ReFS) | No

CsvFs does not support making a directory compressed. CsvFs allows making file compressed only when the file is opened exclusively by a node. SMB 3.0 Transparent Failover and Scale-Out does not support NTFS compressed files. The FSCTL call is not blocked, but is unsupported."

### Transacted Operations

You cannot change the compression state of a file opened with
[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda).

For more information about transactions, see
[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal).

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_GET_COMPRESSION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_compression)
* [File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)
* [GetFileAttributes](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesa)
* [Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)