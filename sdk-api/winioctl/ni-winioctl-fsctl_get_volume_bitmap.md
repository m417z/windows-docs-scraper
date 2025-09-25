# FSCTL_GET_VOLUME_BITMAP IOCTL

## Description

Retrieves a bitmap of occupied and available clusters on a volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to volume
  FSCTL_GET_VOLUME_BITMAP,      // dwIoControlCode
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

## Remarks

The **FSCTL_GET_VOLUME_BITMAP** control code retrieves a data structure that describes the allocation state of each cluster in the file system from the requested starting LCN to the last cluster on the volume. The bitmap uses one bit to represent each cluster:
* The value 1 indicates that the cluster is allocated (in use).
* The value 0 indicates that the cluster is not allocated (free).

Note that the bitmap represents a point in time, and can be incorrect as soon as it has been read if the volume has write activity. Thus, it is possible to attempt to move a cluster onto an allocated cluster in spite of a recent bitmap indicating that the cluster is unallocated. Programs using the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_move_file) control code must be prepared for this possibility.

The handle used here must be a Volume handle and have been opened with any access. Note that only Administrators can open Volume handles.

The starting LCN in the input buffer may be rounded down before the bitmap is calculated. The rounding limit is file system dependent.

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

This operation aligns the bitmap it returns on a page boundary.

**Windows Server 2003 and Windows XP:** This operation aligns the bitmap it returns on a byte boundary.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [Defragmentation](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_move_file)
* [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)
* [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)
* [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [STARTING_LCN_INPUT_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-starting_lcn_input_buffer)
* [VOLUME_BITMAP_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-volume_bitmap_buffer)