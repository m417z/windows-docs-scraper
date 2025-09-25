# FSCTL_GET_RETRIEVAL_POINTERS IOCTL

## Description

Given a file handle, retrieves a data structure that describes the allocation and location on disk of a specific file, or, given a volume handle, the locations of bad clusters on a volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file, directory, or volume
  FSCTL_GET_RETRIEVAL_POINTERS,     // dwIoControlCode
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

The **FSCTL_GET_RETRIEVAL_POINTERS** operation retrieves a variably sized data structure that describes the allocation and location on disk of a specific file. The structure describes the mapping between virtual cluster numbers (VCN offsets within the file or stream space) and logical cluster numbers (LCN offsets within the volume space).

The **FSCTL_GET_RETRIEVAL_POINTERS** control code is supported for file or directory operations on NTFS, FAT, exFAT, UDF, and ReFS file systems.

On supported file systems, the **FSCTL_GET_RETRIEVAL_POINTERS** operation returns the extent locations of nonresident data. Resident data never has extent locations.

The **FSCTL_GET_RETRIEVAL_POINTERS** control code also supports the alternate functionality of locating bad clusters. To query for the locations of bad clusters on a volume formatted with NTFS, FAT, or exFAT, use a volume handle as the *hDevice* parameter. This functionality is supported only on NTFS, FAT, and exFAT, and the caller must have **MANAGE_VOLUME_ACCESS** permission to the volume.

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

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
* [FSCTL_GET_RETRIEVAL_POINTER_BASE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointer_base)
* [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)
* [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)
* [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [RETRIEVAL_POINTERS_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-retrieval_pointers_buffer)
* [STARTING_VCN_INPUT_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-starting_vcn_input_buffer)