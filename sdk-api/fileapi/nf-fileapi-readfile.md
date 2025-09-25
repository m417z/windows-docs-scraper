# ReadFile function

## Description

Reads data from the specified file or input/output (I/O) device. Reads occur at the position specified by the file pointer if supported by the device.

This function is designed for both synchronous and asynchronous operations. For a similar function designed solely for asynchronous operation, see [ReadFileEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfileex).

## Parameters

### `hFile` [in]

A handle to the device (for example, a file, file stream, physical disk, volume, console buffer, tape drive, socket, communications resource, mailslot, or pipe).

The *hFile* parameter must have been created with read access. For more information, see [Generic Access Rights](https://learn.microsoft.com/windows/win32/SecAuthZ/generic-access-rights) and [File Security and Access Rights](https://learn.microsoft.com/windows/win32/FileIO/file-security-and-access-rights).

For asynchronous read operations, *hFile* can be any handle that is opened with the **FILE_FLAG_OVERLAPPED** flag by the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function, or a socket handle returned by the [socket](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-socket) or [accept](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-accept) function.

### `lpBuffer` [out]

A pointer to the buffer that receives the data read from a file or device.

This buffer must remain valid for the duration of the read operation. The caller must not use this buffer until the read operation is completed.

### `nNumberOfBytesToRead` [in]

The maximum number of bytes to be read.

### `lpNumberOfBytesRead` [out, optional]

A pointer to the variable that receives the number of bytes read when using a synchronous *hFile* parameter. **ReadFile** sets this value to zero before doing any work or error checking. Use **NULL** for this parameter if this is an asynchronous operation to avoid potentially erroneous results.

This parameter can be **NULL** only when the *lpOverlapped* parameter is not **NULL**.

**Windows 7:** This parameter can not be **NULL**.

For more information, see the Remarks section.

### `lpOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure is required if the *hFile* parameter was opened with **FILE_FLAG_OVERLAPPED**, otherwise it can be **NULL**.

If *hFile* is opened with **FILE_FLAG_OVERLAPPED**, the *lpOverlapped* parameter must point to a valid and unique [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure, otherwise the function can incorrectly report that the read operation is complete.

For an *hFile* that supports byte offsets, if you use this parameter you must specify a byte offset at which to start reading from the file or device. This offset is specified by setting the **Offset** and **OffsetHigh** members of the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. For an **hFile** that does not support byte offsets, **Offset** and **OffsetHigh** are ignored.

For more information about different combinations of *lpOverlapped* and **FILE_FLAG_OVERLAPPED**, see the Remarks section and the **Synchronization and File Position** section.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, or is completing asynchronously, the return value is zero (**FALSE**). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

> [!NOTE]
> The [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) code **ERROR_IO_PENDING** is not a failure; it designates the read operation is pending completion asynchronously. For more information, see Remarks.

## Remarks

The **ReadFile** function returns when one of the following conditions occur:

- The number of bytes requested is read.
- A write operation completes on the write end of the pipe.
- An asynchronous handle is being used and the read is occurring asynchronously.
- An error occurs.

The **ReadFile** function may fail with **ERROR_INVALID_USER_BUFFER** or **ERROR_NOT_ENOUGH_MEMORY** whenever there are too many outstanding asynchronous I/O requests.

To cancel all pending asynchronous I/O operations, use either:

- [CancelIo](https://learn.microsoft.com/windows/win32/FileIO/cancelio): This function only cancels operations issued by the calling thread for the specified file handle.
- [CancelIoEx](https://learn.microsoft.com/windows/win32/FileIO/cancelioex-func): This function cancels all operations issued by the threads for the specified file handle.

Use [CancelSynchronousIo](https://learn.microsoft.com/windows/win32/FileIO/cancelsynchronousio-func) to cancel pending synchronous I/O operations.

I/O operations that are canceled complete with the error **ERROR_OPERATION_ABORTED**.

The **ReadFile** function may fail with **ERROR_NOT_ENOUGH_QUOTA**, which means the calling process's buffer could not be page-locked. For additional information, see [SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize).

If part of a file is locked by another process and the read operation overlaps the locked portion, this function fails.

Accessing the input buffer while a read operation is using the buffer may lead to corruption of the data read into that buffer. Applications must not read from, write to, reallocate, or free the input buffer that a read operation is using until the read operation completes. This can be particularly problematic when using an asynchronous file handle. Additional information regarding synchronous versus asynchronous file handles can be found in the [Synchronization and File Position](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile#synchronization-and-file-position) section and in the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) reference topic.

Characters can be read from the console input buffer by using **ReadFile** with a handle to console input. The console mode determines the exact behavior of the **ReadFile** function. By default, the console mode is **ENABLE_LINE_INPUT**, which indicates that **ReadFile** should read until it reaches a carriage return. If you press Ctrl+C, the call succeeds, but [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_OPERATION_ABORTED**. For more information, see [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea).

When reading from a communications device, the behavior of **ReadFile** is determined by the current communication time-out as set and retrieved by using the [SetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setcommtimeouts) and [GetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getcommtimeouts) functions. Unpredictable results can occur if you fail to set the time-out values. For more information about communication time-outs, see [COMMTIMEOUTS](https://learn.microsoft.com/windows/win32/api/winbase/ns-winbase-commtimeouts).

If **ReadFile** attempts to read from a mailslot that has a buffer that is too small, the function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**.

There are strict requirements for successfully working with files opened with [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) using the **FILE_FLAG_NO_BUFFERING** flag. For details see [File Buffering](https://learn.microsoft.com/windows/win32/FileIO/file-buffering).

If **hFile** was opened with **FILE_FLAG_OVERLAPPED**, the following conditions are in effect:

- The *lpOverlapped* parameter must point to a valid and unique [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure, otherwise the function can incorrectly report that the read operation is complete.
- The *lpNumberOfBytesRead* parameter should be set to **NULL**. Use the [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) function to get the actual number of bytes read. If the **hFile** parameter is associated with an I/O completion port, you can also get the number of bytes read by calling the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

If a read operation on a file begins at or beyond the end of the file, then the read operation fails with the error **ERROR_HANDLE_EOF**. If a read operation on a file begins before the end of the file, but the read operation extends past the end of the file, then the read operation succeeds, and the number of bytes read is the number of bytes that were read before the end of file was reached.

#### Synchronization and File Position

If **hFile** is opened with **FILE_FLAG_OVERLAPPED**, it is an asynchronous file handle; otherwise it is synchronous. The rules for using the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure are slightly different for each, as previously noted.

> [!NOTE]
> If a file or device is opened for asynchronous I/O, subsequent calls to functions such as **ReadFile** using that handle generally return immediately, but can also behave synchronously with respect to blocked execution. For more information see [Asynchronous disk I/O appears as synchronous on Windows](https://learn.microsoft.com/previous-versions/troubleshoot/windows/win32/asynchronous-disk-io-synchronous).

Considerations for working with asynchronous file handles:

- **ReadFile** may return before the read operation is complete. In this scenario, **ReadFile** returns **FALSE** and the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_IO_PENDING**, which allows the calling process to continue while the system completes the read operation.
- The *lpOverlapped* parameter must not be **NULL** and should be used with the following facts in mind:
  - Although the event specified in the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure is set and reset automatically by the system, the offset that is specified in the **OVERLAPPED** structure is not automatically updated.
  - **ReadFile** resets the event to a nonsignaled state when it begins the I/O operation.
  - The event specified in the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure is set to a signaled state when the read operation is complete; until that time, the read operation is considered pending.
  - Because the read operation starts at the offset that is specified in the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure, and **ReadFile** may return before the system-level read operation is complete (read pending), neither the offset nor any other part of the structure should be modified, freed, or reused by the application until the event is signaled (that is, the read completes).

Considerations for working with synchronous file handles:

- If *lpOverlapped* is **NULL**, the read operation starts at the current file position and **ReadFile** does not return until the operation is complete, and the system updates the file pointer before **ReadFile** returns.
- If *lpOverlapped* is not **NULL**, the read operation starts at the offset that is specified in the [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure and **ReadFile** does not return until the read operation is complete. The system updates the **OVERLAPPED** offset and the file pointer before **ReadFile** returns.

For more information, see [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) and [Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/win32/FileIO/synchronous-and-asynchronous-i-o).

#### Pipes

If an anonymous pipe is being used and the write handle has been closed, when **ReadFile** attempts to read using the pipe's corresponding read handle, the function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_BROKEN_PIPE**.

If a named pipe is being read in message mode and the next message is longer than the *nNumberOfBytesToRead* parameter specifies, **ReadFile** returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_MORE_DATA**. The remainder of the message can be read by a subsequent call to the **ReadFile** or [PeekNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-peeknamedpipe) function.

If the *lpNumberOfBytesRead* parameter is zero when **ReadFile** returns **TRUE** on a pipe, the other end of the pipe called the [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile) function with *nNumberOfBytesToWrite* set to zero.

For more information about pipes, see [Pipes](https://learn.microsoft.com/windows/desktop/ipc/pipes).

#### Transacted Operations

If there is a transaction bound to the file handle, then the function returns data from the transacted view of the file. A transacted read handle is guaranteed to show the same view of a file for the duration of the handle. For more information, see [About Transactional NTFS](https://learn.microsoft.com/windows/win32/FileIO/about-transactional-ntfs).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
|------------|-----------|
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For a code example that shows you how to test for end-of-file, see [Testing for the End of a File](https://learn.microsoft.com/windows/win32/FileIO/testing-for-the-end-of-a-file). For other examples, see [Creating and Using a Temporary File](https://learn.microsoft.com/windows/win32/FileIO/creating-and-using-a-temporary-file) and [Opening a File for Reading or Writing](https://learn.microsoft.com/windows/win32/FileIO/opening-a-file-for-reading-or-writing).

## See also

[CancelIo](https://learn.microsoft.com/windows/win32/FileIO/cancelio)

[CancelIoEx](https://learn.microsoft.com/windows/win32/FileIO/cancelioex-func)

[CancelSynchronousIo](https://learn.microsoft.com/windows/win32/FileIO/cancelsynchronousio-func)

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)

[File Management Functions](https://learn.microsoft.com/windows/win32/FileIO/file-management-functions)

[GetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getcommtimeouts)

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped)

[PeekNamedPipe](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-peeknamedpipe)

[ReadFileEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfileex)

[SetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setcommtimeouts)

[SetErrorMode](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-seterrormode)

[WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile)