# FSCTL_DUPLICATE_EXTENTS_TO_FILE IOCTL

## Description

Instructs the file system to copy a range of file bytes on behalf of an application. The destination file may be the same as, or different from, the source file. See [Block Cloning](https://learn.microsoft.com/windows/desktop/FileIO/block-cloning) for more information.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE)       hDevice,           // handle to device
  FSCTL_DUPLICATE_EXTENTS_TO_FILE,  // dwIoControlCode
  (LPVOID)       lpInBuffer,        // input buffer
  (DWORD)        nInBufferSize,     // size of input buffer
  NULL,                             // lpOutBuffer
  0,                                // nOutBufferSize
  (LPDWORD)      lpBytesReturned,   // number of bytes returned
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

See [Block Cloning](https://learn.microsoft.com/windows/desktop/FileIO/block-cloning) for more information on this operation.

In Windows Server 2016, this function is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.1.1 protocol | Yes
SMB 3.1.1 Transparent Failover (TFO) | Yes
SMB 3.1.1 with Scale-out File Shares (SoFS) | Yes
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | Yes

## See also

* [Block Cloning](https://learn.microsoft.com/windows/desktop/FileIO/block-cloning)
* [DUPLICATE_EXTENTS_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-duplicate_extents_data)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)