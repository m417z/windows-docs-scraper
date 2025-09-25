# ReadDirectoryChangesW function

## Description

Retrieves information that describes the changes within the specified directory. The
function does not report changes to the specified directory itself.

To track changes on a volume, see
[change journals](https://learn.microsoft.com/windows/desktop/FileIO/change-journals).

## Parameters

### `hDirectory` [in]

A handle to the directory to be monitored. This directory must be opened with the
**FILE_LIST_DIRECTORY** access right, or an access right such as **GENERIC_READ** that includes the **FILE_LIST_DIRECTORY** access right.

### `lpBuffer` [out]

A pointer to the **DWORD**-aligned formatted buffer in which the read results are
to be returned. The structure of this buffer is defined by the
[FILE_NOTIFY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_notify_information) structure. This
buffer is filled either synchronously or asynchronously, depending on how the directory is opened and what value
is given to the *lpOverlapped* parameter. For more information, see the Remarks
section.

### `nBufferLength` [in]

The size of the buffer that is pointed to by the *lpBuffer* parameter, in
bytes.

### `bWatchSubtree` [in]

If this parameter is **TRUE**, the function monitors the directory tree rooted at the
specified directory. If this parameter is **FALSE**, the function monitors only the
directory specified by the *hDirectory* parameter.

### `dwNotifyFilter` [in]

The filter criteria that the function checks to determine if the wait operation has completed. This
parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_NOTIFY_CHANGE_FILE_NAME**<br><br>0x00000001 | Any file name change in the watched directory or subtree causes a change notification wait operation to return. Changes include renaming, creating, or deleting a file. |
| **FILE_NOTIFY_CHANGE_DIR_NAME**<br><br>0x00000002 | Any directory-name change in the watched directory or subtree causes a change notification wait operation to return. Changes include creating or deleting a directory. |
| **FILE_NOTIFY_CHANGE_ATTRIBUTES**<br><br>0x00000004 | Any attribute change in the watched directory or subtree causes a change notification wait operation to return. |
| **FILE_NOTIFY_CHANGE_SIZE**<br><br>0x00000008 | Any file-size change in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change in file size only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed. |
| **FILE_NOTIFY_CHANGE_LAST_WRITE**<br><br>0x00000010 | Any change to the last write-time of files in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change to the last write-time only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed. |
| **FILE_NOTIFY_CHANGE_LAST_ACCESS**<br><br>0x00000020 | Any change to the last access time of files in the watched directory or subtree causes a change notification wait operation to return. |
| **FILE_NOTIFY_CHANGE_CREATION**<br><br>0x00000040 | Any change to the creation time of files in the watched directory or subtree causes a change notification wait operation to return. |
| **FILE_NOTIFY_CHANGE_SECURITY**<br><br>0x00000100 | Any security-descriptor change in the watched directory or subtree causes a change notification wait operation to return. |

### `lpBytesReturned` [out, optional]

For synchronous calls, this parameter receives the number of bytes transferred into the
*lpBuffer* parameter. For asynchronous calls, this parameter is undefined. You must use
an asynchronous notification technique to retrieve the number of bytes transferred.

### `lpOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that supplies
data to be used during asynchronous operation. Otherwise, this value is **NULL**. The
**Offset** and **OffsetHigh** members of this structure are not
used.

### `lpCompletionRoutine` [in, optional]

A pointer to a completion routine to be called when the operation has been completed or canceled and the
calling thread is in an alertable wait state. For more information about this completion routine, see
[FileIOCompletionRoutine](https://learn.microsoft.com/windows/desktop/api/minwinbase/nc-minwinbase-lpoverlapped_completion_routine).

## Return value

If the function succeeds, the return value is nonzero. For synchronous calls, this means that the operation
succeeded. For asynchronous calls, this indicates that the operation was successfully queued.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the network redirector or the target file system does not support this operation, the function fails with
**ERROR_INVALID_FUNCTION**.

## Remarks

To obtain a handle to a directory, use the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)
function with the **FILE_FLAG_BACKUP_SEMANTICS** flag.

A call to **ReadDirectoryChangesW** can be
completed synchronously or asynchronously. To specify asynchronous completion, open the directory with
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) as shown above, but additionally specify the
**FILE_FLAG_OVERLAPPED** attribute in the *dwFlagsAndAttributes*
parameter. Then specify an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure when you
call **ReadDirectoryChangesW**.

When you first call **ReadDirectoryChangesW**, the system allocates a buffer to store change information. This buffer is associated with the directory handle until it is closed and its size does not change during its lifetime. Directory changes that occur between calls to this function are added to the buffer and then returned with the next call. If the buffer overflows, **ReadDirectoryChangesW** will still return **true**, but the entire contents of the buffer are discarded and the *lpBytesReturned* parameter will be zero, which indicates that your buffer was too small to hold all of the changes that occurred.

Upon successful synchronous completion, the *lpBuffer* parameter is a formatted buffer
and the number of bytes written to the buffer is available in *lpBytesReturned*. If the
number of bytes transferred is zero, the buffer was either too large for the system to allocate or too small to
provide detailed information on all the changes that occurred in the directory or subtree. In this case, you
should compute the changes by enumerating the directory or subtree.

For asynchronous completion, you can receive notification in one of three ways:

* Using the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function. To
  receive notification through
  **GetOverlappedResult**, do not specify a completion
  routine in the *lpCompletionRoutine* parameter. Be sure to set the
  **hEvent** member of the
  [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure to a unique event.
* Using the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)
  function. To receive notification through
  **GetQueuedCompletionStatus**, do not specify
  a completion routine in *lpCompletionRoutine*. Associate the directory handle
  *hDirectory* with a completion port by calling the
  [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function.
* Using a completion routine. To receive notification through a completion routine, do not associate the
  directory with a completion port. Specify a completion routine in *lpCompletionRoutine*.
  This routine is called whenever the operation has been completed or canceled while the thread is in an alertable
  wait state. The **hEvent** member of the
  [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure is not used by the system, so you
  can use it yourself.

For more information, see
[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o).

**ReadDirectoryChangesW** fails with
**ERROR_INVALID_PARAMETER** when the buffer length is greater than 64 KB and the application
is monitoring a directory over the network. This is due to a packet size limitation with the underlying file
sharing protocols.

**ReadDirectoryChangesW** fails with
**ERROR_NOACCESS** when the buffer is not aligned on a **DWORD**
boundary.

**ReadDirectoryChangesW** fails with
**ERROR_NOTIFY_ENUM_DIR**
when the system was unable to record all the changes to the directory.
In this case, you should compute the changes by enumerating the directory or subtree.

If you opened the file using the short name, you can receive change notifications for the short name.

In Windows 8 and Windows Server 2012, this function is supported by the following
technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

### Transacted Operations

If there is a transaction bound to the directory handle, then the notifications follow the appropriate
transaction isolation rules.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport)

[Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)

[FILE_NOTIFY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-file_notify_information)

[FileIOCompletionRoutine](https://learn.microsoft.com/windows/desktop/api/minwinbase/nc-minwinbase-lpoverlapped_completion_routine)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)