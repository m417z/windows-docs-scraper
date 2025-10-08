# CancelIo function

Cancels all pending input and output (I/O) operations that are issued by the calling thread for the specified file. The function does not cancel I/O operations that other threads issue for a file handle.

To cancel I/O operations from another thread, use the [**CancelIoEx**](https://learn.microsoft.com/windows/win32/fileio/cancelioex-func) function.

## Parameters

*hFile* \[in\]

A handle to the file.

The function cancels all pending I/O operations for this file handle.

## Return value

If the function succeeds, the return value is nonzero. The cancel operation for all pending I/O operations issued by the calling thread for the specified file handle was successfully requested. The thread can use the [**GetOverlappedResult**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function to determine when the I/O operations themselves have been completed.

If the function fails, the return value is zero (0). To get extended error information, call the [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If there are any pending I/O operations in progress for the specified file handle, and they are issued by the calling thread, the **CancelIo** function cancels them. **CancelIo** cancels only outstanding I/O on the handle, it does not change the state of the handle; this means that you cannot rely on the state of the handle because you cannot know whether the operation was completed successfully or canceled.

The I/O operations must be issued as overlapped I/O. If they are not, the I/O operations do not return to allow the thread to call the **CancelIo** function. Calling the **CancelIo** function with a file handle that is not opened with **FILE\_FLAG\_OVERLAPPED** does nothing.

All I/O operations that are canceled complete with the error **ERROR\_OPERATION\_ABORTED**, and all completion notifications for the I/O operations occur normally.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
|------------------------------------------------------|----------------|
| Server Message Block (SMB) 3.0 protocol<br> | Yes<br> |
| SMB 3.0 Transparent Failover (TFO)<br> | Yes<br> |
| SMB 3.0 with Scale-out File Shares (SO)<br> | Yes<br> |
| Cluster Shared Volume File System (CsvFS)<br> | Yes<br> |
| Resilient File System (ReFS)<br> | Yes<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps \| UWP apps\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps \| UWP apps\]<br> |
| Header<br> | IoAPI.h (include Windows.h); <br>WinBase.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP (include Windows.h) |
| Library<br> | Kernel32.lib |
| DLL<br> | Kernel32.dll |

## See also

[**CancelIoEx**](https://learn.microsoft.com/windows/win32/fileio/cancelioex-func)

[**CancelSynchronousIo**](https://learn.microsoft.com/windows/win32/fileio/cancelsynchronousio-func)

[**CreateFile**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-createfilea)

[**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[File Management Functions](https://learn.microsoft.com/windows/win32/fileio/file-management-functions)

[**LockFileEx**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-lockfileex)

[**ReadDirectoryChangesW**](https://learn.microsoft.com/windows/desktop/api/WinBase/nf-winbase-readdirectorychangesw)

[**ReadFile**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-readfile)

[**ReadFileEx**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-readfileex)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/win32/fileio/synchronous-and-asynchronous-i-o)

[**WriteFile**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-writefile)

[**WriteFileEx**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-writefileex)

