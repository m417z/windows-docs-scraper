# FSCTL_REQUEST_OPLOCK_LEVEL_2 IOCTL

## Description

Requests a level 2 opportunistic lock on a file.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file
  FSCTL_REQUEST_OPLOCK_LEVEL_2,     // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
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

This operation is used only by client applications requesting an opportunistic lock from a local server. Client applications requesting opportunistic locks from remote servers must not request them directly—the network redirector transparently requests opportunistic locks for the application. An attempt to use this operation to request opportunistic locks from remote servers will result in the request being denied.

If a new oplock type is desired, the handle must be closed and a new handle reopened using [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea), and [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) must be called on the new handle with the desired **FSCTL_REQUEST_OPLOCK**_\_XXX_ control code. To request an oplock on a handle that can have the oplock type changed in place (the handle does not have to be closed and reopened), use the [FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_oplock) control code.

Use **FSCTL_REQUEST_OPLOCK_LEVEL_2** to request a level 2 opportunistic lock on a file. A client file system can cache read data (but not write data) locally as long as the level 2 lock is held.

The file system requires no acknowledgment from the application that requested the level 2 opportunistic lock when the lock is broken. After the lock is broken, the network redirector is notified not to regard as valid any cached data from the file. For more information, see [Breaking Oplocks](https://learn.microsoft.com/windows-hardware/drivers/ifs/breaking-oplocks).

For more information, see [Types of Opportunistic Locks](https://learn.microsoft.com/windows/desktop/FileIO/types-of-opportunistic-locks).

For a comparison of the various oplock control codes, see [FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_oplock).

An **FSCTL_REQUEST_OPLOCK_LEVEL_2** control code fails if the file is opened in nonoverlapped (synchronous) mode.

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
* [FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_oplock)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [Oplock Semantics](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-semantics)
* [Opportunistic Locks](https://learn.microsoft.com/windows/desktop/FileIO/opportunistic-locks)