# FSCTL_LOOKUP_STREAM_FROM_CLUSTER IOCTL

## Description

Given a handle to a NTFS volume or a file on a NTFS volume, returns a chain of data structures that describes streams that occupy the specified clusters.

> [!IMPORTANT]
> **FSCTL_LOOKUP_STREAM_FROM_CLUSTER** is a very resource-intensive operation, and typically uses a very large amount of disk bandwidth, memory, and time. It is unlikely that much of this information will remain in cache so a second call to **FSCTL_LOOKUP_STREAM_FROM_CLUSTER** would take nearly as much time as the first call. For doing multiple lookups it's more efficient to use [FSCTL_ENUM_USN_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_enum_usn_data) to enumerate every MFT record and then use [FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers) to gather the data to map between clusters and streams.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE)       hDevice,               // handle to file, directory, or volume
  FSCTL_LOOKUP_STREAM_FROM_CLUSTER,     // dwIoControlCode
  (LPVOID)       lpInBuffer,            // input buffer
  (DWORD)        nInBufferSize,         // size of input buffer
  (LPVOID)       lpOutBuffer,           // output buffer
  (DWORD)        nOutBufferSize,        // size of output buffer
  (LPDWORD)      lpBytesReturned,       // number of bytes returned
  (LPOVERLAPPED) lpOverlapped           // OVERLAPPED structure
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
* [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)
* [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)
* [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)
* [LOOKUP_STREAM_FROM_CLUSTER_ENTRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-lookup_stream_from_cluster_entry)
* [LOOKUP_STREAM_FROM_CLUSTER_INPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-lookup_stream_from_cluster_input)
* [LOOKUP_STREAM_FROM_CLUSTER_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-lookup_stream_from_cluster_output)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)