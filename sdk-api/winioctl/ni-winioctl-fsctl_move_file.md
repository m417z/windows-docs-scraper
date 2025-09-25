# FSCTL_MOVE_FILE IOCTL

## Description

Relocates one or more virtual clusters of a file from one logical cluster to another within the same volume. This operation is used during [defragmentation](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files).

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to volume
  FSCTL_MOVE_FILE,              // dwIoControlCode
  (LPVOID) lpInBuffer,          // MOVE_FILE_DATA structure
  (DWORD) nInBufferSize,        // size of input buffer
  NULL,                         // lpOutBuffer
  0,                            // nOutBufferSize
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

The **FSCTL_MOVE_FILE** control code relocates one or more virtual clusters of a file from one logical cluster to another within the same volume. If the file to be moved is a sparse or compressed file, the granularity of the move is 16 clusters; otherwise, the granularity is one cluster.

To mark an open file so that it is not defragmented, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_MARK_HANDLE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_mark_handle) control code with **MARK_HANDLE_PROTECT_CLUSTERS** in the **HandleInfo** member of the [MARK_HANDLE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-mark_handle_info) structure passed in the *lpInBuffer* parameter.

Note that the bitmap returned by the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the [FSCTL_GET_VOLUME_BITMAP](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_volume_bitmap) control code represents a point in time, and can be incorrect as soon as it has been read if the volume has write activity. Thus, it is possible to attempt to move a cluster onto an allocated cluster in spite of a recent bitmap indicating that the cluster is unallocated. Programs using **FSCTL_MOVE_FILE** must be prepared for this possibility.

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

For a list of files, streams, and stream types supported by the **FSCTL_MOVE_FILE** control code, see the [Files, streams, and stream types supported for defragmentation](https://learn.microsoft.com/windows/win32/fileio/defragmenting-files#files-streams-and-stream-types-supported-for-defragmentation) section of the [Defragmenting Files](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files) topic.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [Defragmenting Files](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [FSCTL_GET_VOLUME_BITMAP](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_volume_bitmap)
* [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)
* [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)
* [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)
* [MOVE_FILE_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-move_file_data)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)