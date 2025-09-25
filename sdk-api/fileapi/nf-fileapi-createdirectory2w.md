## Description

Creates a new directory. If the underlying file system supports security on files and directories, the function applies a specified security descriptor to the new directory.

To specify a template directory, use the [CreateDirectoryEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createdirectoryexw) function.

To perform this operation as a transacted operation, use the [CreateDirectoryTransacted](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createdirectorytransactedw) function.

## Parameters

### `lpPathName`

The path of the directory to be created.

By default, the name is limited to **MAX_PATH** characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> You can opt-in to remove the **MAX_PATH** limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwDesiredAccess`

The **ACCESS_MASK** value that expresses the type of access that the caller requires to the directory. The set of system-defined *dwDesiredAccess* flags determines the following specific access rights directory file objects:

| Value | Meaning |
|-------|---------|
| **FILE_LIST_DIRECTORY** | Files in the directory can be listed. |
| **FILE_TRAVERSE** | The directory can be traversed: that is, it can be part of the pathname of a file. |
| **SYNCHRONIZE** | The returned handle can be waited on to synchronize with the completion of an I/O operation. If the handle was not opened for synchronous I/O, this value is ignored. |

### `dwShareMode`

The type of share access that the caller would like to use in the file, as zero, or as one or a combination of the following values:

| Value | Meaning |
|-------|---------|
| **0**<br>`0x00000000` | Prevents other processes from opening a file or device if they request delete, read, or write access. |
| **FILE_SHARE_READ**<br>`0x00000001` | Enables subsequent open operations on a file or device to request read access. Otherwise, other processes cannot open the file or device if they request read access. If this flag is not specified, but the file or device has been opened for read access, the function fails. |
| **FILE_SHARE_WRITE**<br>`0x00000002` | Enables subsequent open operations on a file or device to request write access. Otherwise, other processes cannot open the file or device if they request write access. If this flag is not specified, but the file or device has been opened for write access or has a file mapping with write access, the function fails. |
| **FILE_SHARE_DELETE**<br>`0x00000004` | Enables subsequent open operations on a file or device to request delete access. Otherwise, other processes cannot open the file or device if they request delete access. If this flag is not specified, but the file or device has been opened for delete access, the function fails.<br><br>**Note:**  Delete access allows both delete and rename operations. |

### `DirectoryFlags`

This parameter can contain combinations of [DIRECTORY_FLAGS](https://learn.microsoft.com/windows/win32/api/fileapi/ne-fileapi-directory_flags).

| Value | Meaning |
|-------|---------|
| **DIRECTORY_FLAGS_DISALLOW_PATH_REDIRECTS**<br>`0x00000001` | Prevent *lpPathName* from being redirected by reparse points or symbolic links. |

### `lpSecurityAttributes`

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure. The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new directory. If *lpSecurityAttributes* is `NULL`, the directory gets a default security descriptor. The ACLs in the default security descriptor for a directory are inherited from its parent directory.

The target file system must support security on files and directories for this parameter to have an effect. (This is indicated when [GetVolumeInformation](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getvolumeinformationw) returns **FS_PERSISTENT_ACLS**.)

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Possible errors include the following:

| Return code | Description |
|-------------|-------------|
| **ERROR_ALREADY_EXISTS** | The specified directory already exists. |
| **ERROR_PATH_NOT_FOUND** | One or more intermediate directories do not exist; this function will only create the final directory in the path. |

## Remarks

Some file systems, such as the NTFS file system, support compression or encryption for individual files and directories. On volumes formatted for such a file system, a new directory inherits the compression and encryption attributes of its parent directory.

An application can obtain a handle to a directory by calling [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) with the **FILE_FLAG_BACKUP_SEMANTICS** flag set. For a code example, see [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew).

To support inheritance functions that query the security descriptor of this object may heuristically determine and report that inheritance is in effect. See [Automatic Propagation of Inheritable ACEs](https://learn.microsoft.com/windows/win32/SecAuthZ/automatic-propagation-of-inheritable-aces) for more information.

This function is supported by the following technologies:

| Technology | Supported |
|------------|-----------|
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

> [!NOTE]
> The `fileapi.h` header defines **CreateDirectory2** as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

#### Examples

The following example creates a new directory with the **CreateDirectory2** function. The new directory is created with the **FILE_LIST_DIRECTORY** and **SYNCHRONIZE** access rights. The new directory is also created with the **FILE_SHARE_READ** share mode, which allows other processes to open the directory for read access.

```cpp
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (C) Microsoft. All rights reserved
#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>

int main(int argc, wchar_t* argv[])
{
    WCHAR filePath[MAX_PATH] = { 0 };

    // Create a directory to put a file into, that can't be deleted
    // and redirected before this handle is closed.
    HANDLE hDirectory = CreateDirectory2(argv[1],
        FILE_LIST_DIRECTORY | SYNCHRONIZE,
        FILE_SHARE_READ,
        DIRECTORY_FLAGS_NONE,
        NULL,
        NULL);
    if (hDirectory == INVALID_HANDLE_VALUE)
    {
        // Handle the error.
        printf("CreateDirectory2 failed (%d)\n", GetLastError());
        return (1);
    }

    StringCchPrintf(filePath,
        ARRAYSIZE(filePath),
        L"%ws\\example.test",
        argv[1]);

    HANDLE hFile = CreateFile3(filePath,
        GENERIC_ALL,
        FILE_SHARE_READ,
        CREATE_ALWAYS,
        NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        // Handle the error.
        CloseHandle(hDirectory);
        printf("CreateFile3 failed (%d)\n", GetLastError());
        return (1);
    }

    CloseHandle(hFile);
    CloseHandle(hDirectory);
    return (0);
}
```

For additional examples, see [Retrieving and Changing File Attributes](https://learn.microsoft.com/windows/win32/fileio/retrieving-and-changing-file-attributes).

## See also

[CreateFile3](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfile3)

[DeleteFile2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-deletefile2w)

[RemoveDirectory2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-removedirectory2w)