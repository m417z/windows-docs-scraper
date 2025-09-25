# FSCTL_OPBATCH_ACK_CLOSE_PENDING IOCTL

## Description

Notifies a server that a client application is ready to close a file. Use this operation after notification that an opportunistic lock on a file is ready to be broken.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function by using the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to file
  FSCTL_OPBATCH_ACK_CLOSE_PENDING,  // dwIoControlCode
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

Before you call this function do not make assumptions about the number of available virtual channels, because the system and other plug-ins might have reserved virtual channels. Always check for a **CHANNEL_RC_TOO_MANY_CHANNELS** return code after calling this function.

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

Use the **FSCTL_OPBATCH_ACK_CLOSE_PENDING** control code when you are notified that an opportunistic lock on a file is ready to be broken, and you intend to close the file soon. This operation does not request a new opportunistic lock.

If you do not intend to close a file, you can use the [FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_oplock_break_acknowledge) or [FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_oplock_break_ack_no_2) control code to respond to the notification. The former, used if the lock being broken is an exclusive opportunistic lock, indicates the file should receive a level 2 opportunistic lock instead. The latter requests the file be kept open but loses all locking.

Applications are notified that an opportunistic lock is broken by using the **hEvent** member of the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure that is associated with a file on which an opportunistic lock is broken. Applications can also use functions such as [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) and [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-hasoverlappediocompleted).

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
* [FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_oplock_break_acknowledge)
* [FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_oplock_break_ack_no_2)
* [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)
* [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-hasoverlappediocompleted)
* [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)
* [Opportunistic Locks](https://learn.microsoft.com/windows/desktop/FileIO/opportunistic-locks)