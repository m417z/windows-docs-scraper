# FSCTL_OPLOCK_BREAK_ACK_NO_2 IOCTL

## Description

Responds to notification that an opportunistic lock on a file is about to be broken. Use this operation to unlock all opportunistic locks on the file but keep the file open.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file
  FSCTL_OPLOCK_BREAK_ACK_NO_2,      // dwIoControlCode
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

This operation is used only by client applications that have requested an opportunistic lock from a local server. Client applications requesting opportunistic locks from remote servers must not request them directly—the network redirector transparently requests opportunistic locks for the application.

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

When you receive notification that an opportunistic lock on a file is about to be broken, use the **FSCTL_OPLOCK_BREAK_ACK_NO_2** control code to indicate to the server that you want to relinquish any opportunistic locks but plan to keep the file open. If the operation returns the error code **ERROR_IO_PENDING**, the server has granted a level 2 lock on the file.

One alternative to using **FSCTL_OPLOCK_BREAK_ACK_NO_2** is to indicate that the application is about to close the file anyway. Use the [FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_opbatch_ack_close_pending) control code for this response.

Another alternative, used if the lock being broken is an exclusive opportunistic lock, is to indicate the file should receive a level 2 opportunistic lock instead. Use the [FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_oplock_break_acknowledge) control code for this response.

Applications are notified that an opportunistic lock is broken by using the **hEvent** member of the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure associated with the file on which the opportunistic lock is broken. Applications may also use functions such as [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) and [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-hasoverlappediocompleted).

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
* [FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_opbatch_ack_close_pending)
* [FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_oplock_break_acknowledge)
* [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)
* [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-hasoverlappediocompleted)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [Oplock Semantics](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-semantics)
* [Opportunistic Locks](https://learn.microsoft.com/windows/desktop/FileIO/opportunistic-locks)