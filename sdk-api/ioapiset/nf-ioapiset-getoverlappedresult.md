# GetOverlappedResult function

## Description

Retrieves the results of an overlapped operation on the specified file, named pipe, or communications device. To specify a timeout interval or wait on an alertable thread, use [GetOverlappedResultEx](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresultex).

## Parameters

### `hFile` [in]

A handle to the file, named pipe, or communications device. This is the same handle that was specified when the overlapped operation was started by a call to any of the following functions:

- [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile)
- [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile)
- [ConnectNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)
- [TransactNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe)
- [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
- [WaitCommEvent](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-waitcommevent)
- [ReadDirectoryChangesW](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-readdirectorychangesw)
- [LockFileEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-lockfileex)

### `lpOverlapped` [in]

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that was specified when the overlapped operation was started.

### `lpNumberOfBytesTransferred` [out]

A pointer to a variable that receives the number of bytes that were actually transferred by a read or write operation. For a
[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe) operation, this is the number of bytes that were read from the pipe. For a
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) operation, this is the number of bytes of output data returned by the device driver. For a
[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) or
[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent) operation, this value is undefined.

### `bWait` [in]

If this parameter is **TRUE**, and the **Internal** member of the *lpOverlapped* structure is **STATUS_PENDING**, the function does not return until the operation has been completed. If this parameter is **FALSE** and the operation is still pending, the function returns **FALSE** and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_IO_INCOMPLETE**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The results reported by the
**GetOverlappedResult** function are those of the specified handle's last overlapped operation to which the specified
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure was provided, and for which the operation's results were pending. A pending operation is indicated when the function that started the operation returns **FALSE**, and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_IO_PENDING**. When an I/O operation is pending, the function that started the operation resets the **hEvent** member of the
**OVERLAPPED** structure to the nonsignaled state. Then when the pending operation has been completed, the system sets the event object to the signaled state.

If the *bWait* parameter is **TRUE**,
**GetOverlappedResult** determines whether the pending operation has been completed by waiting for the event object to be in the signaled state.

If the **hEvent** member of the
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure is **NULL**, the system uses the state of the *hFile* handle to signal when the operation has been completed. Use of file, named pipe, or communications-device handles for this purpose is discouraged. It is safer to use an event object because of the confusion that can occur when multiple simultaneous overlapped operations are performed on the same file, named pipe, or communications device. In this situation, there is no way to know which operation caused the object's state to be signaled.

#### Examples

For an example that uses **GetOverlappedResult**, see [Testing for the End of a File](https://learn.microsoft.com/windows/win32/fileio/testing-for-the-end-of-a-file)

## See also

[CancelIo](https://learn.microsoft.com/windows/win32/FileIO/cancelio), [CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa), [GetOverlappedResultEx](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresultex), [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped), [Overlapped Input and Output](https://learn.microsoft.com/windows/win32/Sync/synchronization-and-overlapped-input-and-output), [Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)