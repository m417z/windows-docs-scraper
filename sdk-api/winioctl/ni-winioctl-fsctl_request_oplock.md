# FSCTL_REQUEST_OPLOCK IOCTL

## Description

Requests an opportunistic lock (oplock) on a file and acknowledges that an oplock break has occurred.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file
  FSCTL_REQUEST_OPLOCK,             // dwIoControlCode
  (LPVOID) lpInBuffer,              // pointer to REQUEST_OPLOCK_INPUT_BUFFER
  (DWORD) nInBufferSize,            // size of input buffer
  (LPVOID) lpOutBuffer,             // pointer to REQUEST_OPLOCK_OUTPUT_BUFFER
  (DWORD) nOutBufferSize,           // size of output buffer
  NULL,                             // number of bytes returned
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

## Remarks

This operation is used by client applications to request an opportunistic lock (oplock) from a local server. Client applications must not request opportunistic locks from remote servers directly—the network redirector transparently requests opportunistic locks for the application. Using this operation to request opportunistic locks from remote servers will result in the request being denied.

If the **DeviceIoControl** operation returns the error code **ERROR_IO_PENDING**, the oplock request has been granted. If it returns any other error code, the oplock has not been granted. If the error code is a warning value such as ERROR_CANNOT_GRANT_REQUESTED_OPLOCK, extended information may be available in the [REQUEST_OPLOCK_OUTPUT_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-request_oplock_output_buffer) structure.

When a granted oplock breaks, the event object in the [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure will be signaled, and information will be returned in the [REQUEST_OPLOCK_OUTPUT_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-request_oplock_output_buffer) structure. The **Internal** member of the **OVERLAPPED** structure will be set to an NTSTATUS value that provides extended information about how the oplock broke.

OVERLAPPED.Internal value | Meaning |
--------------------------|---------|
STATUS_SUCCESS\
0x0 | The oplock was broken by another file system operation. |
STATUS_OPLOCK_HANDLE_CLOSED\
0x00000216 | The oplock is no longer in force because the file handle used to request it was closed. Note that if an oplock breaks because the handle that was used to request it was closed, there is no need to acknowledge the break, regardless of the oplock type. |
STATUS_OPLOCK_SWITCHED_TO_NEW_HANDLE\
0x00000215 | The oplock is still in force, however it is no longer associated with the file handle that was used to request it. A caller used a different handle to the file to request a new oplock, and that handle now owns the oplock. |

The **FSCTL_REQUEST_OPLOCK** control code provides more efficient functionality than the following related control codes: [FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_oplock_level_1), [FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_oplock_level_2), [FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_filter_oplock), and [FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_batch_oplock). Requesting different oplock levels can be performed repeatedly on the same handle without closing and reopening the handle when using **FSCTL_REQUEST_OPLOCK**; the other control codes require that the handle be closed and then reopened with [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) to make such a change. This is accomplished by manipulating the **RequestedOplockLevel** member of the [REQUEST_OPLOCK_INPUT_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-request_oplock_input_buffer) structure when re-issuing the **FSCTL_REQUEST_OPLOCK** control code.

The following table summarizes how the caching ability of oplock types available from **FSCTL_REQUEST_OPLOCK** correspond to the level 2, level 1, and batch oplocks.

Alternative control code | Equivalent **RequestedOplockLevel** flags value | Oplock type
-------------------------|-------------------------------------------------|------------
[FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_batch_oplock) | `OPLOCK_LEVEL_CACHE_READ \| OPLOCK_LEVEL_CACHE_WRITE \| OPLOCK_LEVEL_CACHE_HANDLE` | RWH
[FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_oplock_level_1) | `OPLOCK_LEVEL_CACHE_READ \| OPLOCK_LEVEL_CACHE_WRITE` | RW
[FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_oplock_level_2) | `OPLOCK_LEVEL_CACHE_READ` | R

Using the **FSCTL_REQUEST_OPLOCK** control code with the **RequestedOplockLevel** member set to `OPLOCK_LEVEL_CACHE_READ | OPLOCK_LEVEL_CACHE_HANDLE` grants an oplock of type *RH*. An RH oplock is similar to the filter oplock granted by the [FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_request_filter_oplock) control code. However, note that the filter oplock allows only one client to hold an oplock on a file at a time; **FSCTL_REQUEST_OPLOCK** allows multiple clients at a time to have the *RH* lock on a file. Another difference is that **FSCTL_REQUEST_FILTER_OPLOCK** requires an oplock break acknowledgment before writes can occur, where **FSCTL_REQUEST_OPLOCK** does not because the oplock break notification is advisory-only and writes are allowed to go ahead without acknowledgment. For more information, see [Breaking Oplocks](https://learn.microsoft.com/windows-hardware/drivers/ifs/breaking-oplocks).

An **FSCTL_REQUEST_OPLOCK** control code fails if the file is opened in non-overlapped (synchronous) mode.

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | Yes

Also, beginning in Windows 8 and Windows Server 2012, the **FSCTL_REQUEST_OPLOCK** control code can be used to request an oplock on a directory as well as a file. An oplock request on a directory may specify either `OPLOCK_LEVEL_CACHE_READ` or `OPLOCK_LEVEL_CACHE_READ | OPLOCK_LEVEL_CACHE_HANDLE` in the RequestedOplockLevel member.

An R or RH oplock on a directory breaks to None when the contents of an enumeration of the directory would change. For example, adding/deleting a file in the directory, changing the size of a file in the directory, modifying the timestamp of a file in the directory, etc., would all break the oplock on the directory. This oplock break does not require an acknowledgment before the changes in the directory may occur; it is advisory-only.

An RH oplock on a directory breaks to R when the directory itself is renamed or deleted. This oplock break does require an acknowledgment before the change to the directory can occur.

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [Oplock Semantics](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-semantics)
* [Opportunistic Locks](https://learn.microsoft.com/windows/desktop/FileIO/opportunistic-locks)