# FSCTL_GET_RETRIEVAL_POINTER_BASE IOCTL

## Description

Returns the sector offset to the first logical cluster number (LCN) of the file system relative to the start of the volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.
```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                    // handle to volume
  FSCTL_GET_RETRIEVAL_POINTER_BASE,    // dwIoControlCode
  (LPVOID) NULL,                       // input buffer
  (DWORD) 0,                           // size of input buffer
  (LPVOID) lpOutBuffer,                // output buffer
  (DWORD) nOutBufferSize,              // size of output buffer
  (LPDWORD) lpBytesReturned,           // number of bytes returned
  (LPOVERLAPPED) lpOverlapped          // OVERLAPPED structure
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

Adding the value retrieved by **FSCTL_GET_RETRIEVAL_POINTER_BASE** to the value retrieved by the [FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers) control code results in a volume-relative file extent offset.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes

## See also

* [Clusters and Extents](https://learn.microsoft.com/windows/desktop/FileIO/clusters-and-extents)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)