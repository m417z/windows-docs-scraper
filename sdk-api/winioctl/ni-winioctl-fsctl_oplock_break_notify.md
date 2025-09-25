# FSCTL_OPLOCK_BREAK_NOTIFY IOCTL

## Description

Enables the calling application to wait for completion of an opportunistic lock break.

This operation is not useful to application developers and is documented here only for completeness. [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) handles the problem that this operation was designed to handle.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to file
  FSCTL_OPLOCK_BREAK_NOTIFY,    // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
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

This operation is used only by client applications that have requested an opportunistic lock from a local server. Client applications requesting opportunistic locks from remote servers must not request them directly—the network redirector transparently requests opportunistic locks for the application.

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | Yes

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [Oplock Semantics](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-semantics)
* [Opportunistic Locks](https://learn.microsoft.com/windows/desktop/FileIO/opportunistic-locks)