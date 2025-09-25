# CancelIo function

## Description

Cancels all pending input and output (I/O) operations that are issued by the calling thread for the specified file. The function does not cancel I/O operations that other threads issue for a file handle.

To cancel I/O operations from another thread, use the [CancelIoEx](https://learn.microsoft.com/windows/desktop/FileIO/cancelioex-func) function.

## Parameters

### `hFile` [in]

A handle to the file.

The function cancels all pending I/O operations for this file handle.

## Return value

If the function succeeds, the return value is nonzero. The cancel operation for all pending I/O operations issued by the calling thread for the specified file handle was successfully requested. The thread can use the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function to determine when the I/O operations themselves have been completed.

If the function fails, the return value is zero (0). To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If there are any pending I/O operations in progress for the specified file handle, and they are issued by the calling thread, the **CancelIo** function cancels them. **CancelIo** cancels only outstanding I/O on the handle, it does not change the state of the handle; this means that you cannot rely on the state of the handle because you cannot know whether the operation was completed successfully or canceled.

The I/O operations must be issued as overlapped I/O. If they are not, the I/O operations do not return to allow the thread to call the
**CancelIo** function. Calling the
**CancelIo** function with a file handle that is not opened with **FILE_FLAG_OVERLAPPED** does nothing.

All I/O operations that are canceled complete with the error **ERROR_OPERATION_ABORTED**, and all completion notifications for the I/O operations occur normally.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[CancelIoEx](https://learn.microsoft.com/windows/desktop/FileIO/cancelioex-func)

[CancelSynchronousIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelsynchronousio-func)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[LockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfileex)

[ReadDirectoryChangesW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readdirectorychangesw)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)