# OpenFileMappingW function

## Description

Opens a named file mapping object.

## Parameters

### `dwDesiredAccess` [in]

The access to the file mapping object. This access is checked against any security descriptor on the target
file mapping object. For a list of values, see
[File Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights).

### `bInheritHandle` [in]

If this parameter is **TRUE**, a process created by the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function can inherit the handle;
otherwise, the handle cannot be inherited.

### `lpName` [in]

The name of the file mapping object to be opened. If there is an open handle to a file mapping object by
this name and the security descriptor on the mapping object does not conflict with the
*dwDesiredAccess* parameter, the open operation succeeds. The name can have a
"Global\" or "Local\" prefix to explicitly open an object in the global or
session namespace. The remainder of the name can contain any character except the backslash character (\\). For
more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces). Fast user
switching is implemented using Terminal Services sessions. The first user to log on uses session 0, the next
user to log on uses session 1, and so on. Kernel object names must follow the guidelines outlined for Terminal
Services so that applications can support multiple users.

## Return value

If the function succeeds, the return value is an open handle to the specified file mapping object.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The handle that **OpenFileMapping** returns can be used
with any function that requires a handle to a file mapping object.

When modifying a file through a mapped view, the last modification timestamp may not be updated automatically.
If required, the caller should use [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) to set the
timestamp.

When it is no longer needed, the caller should release the handle returned by
**OpenFileMapping** with a call to
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see
[Creating Named Shared Memory](https://learn.microsoft.com/windows/desktop/Memory/creating-named-shared-memory).

## See also

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[File Mapping Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

Memory Management Functions

[Sharing Files and Memory](https://learn.microsoft.com/windows/desktop/Memory/sharing-files-and-memory)