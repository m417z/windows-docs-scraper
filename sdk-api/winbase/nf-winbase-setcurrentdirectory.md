# SetCurrentDirectory function

## Description

Changes the current directory for the current process.

## Parameters

### `lpPathName` [in]

The path to the new current directory. This parameter may specify a relative path or a full path. In either case, the full path of the specified directory is calculated and stored as the current directory.

For more info, see [Naming files, paths, and namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).
By default, the name is limited to **MAX_PATH** characters.

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt in to remove the **MAX_PATH** limitation. For details, see the *Maximum path length limitation* section of [Naming files, paths, and namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!IMPORTANT]
> Setting a current directory longer than **MAX_PATH** causes [CreateProcessW](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw) to fail.

The final character before the null character must be a backslash ('\\'). If you don't specify the backslash, then it will be added for you. Therefore, specify **>MAX_PATH**-2 characters for the path unless you include the trailing backslash; in which case, specify **MAX_PATH**-1 characters for the path.

## Return value

If the function succeeds, then the return value is non-zero.

If the function fails, then the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Each process has a single current directory made up of two parts:

* A disk designator that is either a drive letter followed by a colon, or a server name and share name (\\*servername*\*sharename*)
* A directory on the disk designator

The current directory is shared by all threads of the process:
If one thread changes the current directory, it affects all threads
in the process.

Multithreaded applications and shared library code should avoid
calling the **SetCurrentDirectory** function due to the risk of
affecting relative path calculations being performed by other threads.
Conversely,

multithreaded applications and shared library code should avoid
using relative paths so that they are unaffected by changes to the
current directory performed by other threads.

> [!NOTE]
The current directory for a process is locked while the process is executing. That prevents the directory from being deleted, moved, or renamed.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## Examples

For an example, see [Changing the current directory](https://learn.microsoft.com/windows/desktop/FileIO/changing-the-current-directory).

## See also

* [Directory Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/directory-management-functions)
* [GetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrentdirectory)
* [GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea)