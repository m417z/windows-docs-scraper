## Description

Creates or opens a file or I/O device. The behavior of this function is identical to [**CreateFile2**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfile2), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpFileName`

The name of the file or device to be created or opened.
For information on special device names, see [Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/win32/fileio/defining-an-ms-dos-device-name).
To create a file stream, specify the name of the file, a colon, and then the name of the stream. For more information, see [File Streams](https://learn.microsoft.com/windows/win32/fileio/file-streams).
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwDesiredAccess`

The requested access to the file or device, which can be summarized as read, write, both or neither zero).

The most commonly used values are **GENERIC\_READ**, **GENERIC\_WRITE**, or both (`GENERIC_READ | GENERIC_WRITE`). For more information, see [Generic Access Rights](https://learn.microsoft.com/windows/win32/secauthz/generic-access-rights), [File Security and Access Rights](https://learn.microsoft.com/windows/win32/fileio/file-security-and-access-rights), [**File Access Rights Constants**](https://learn.microsoft.com/windows/win32/fileio/file-access-rights-constants), and [**ACCESS\_MASK**](https://learn.microsoft.com/windows/win32/secauthz/access-mask).

If this parameter is zero, the application can query certain metadata such as file, directory, or device attributes without accessing that file or device, even if **GENERIC\_READ** access would have been denied.

You cannot request an access mode that conflicts with the sharing mode that is specified by the *dwShareMode* parameter in an open request that already has an open handle.

### `dwShareMode`

The requested sharing mode of the file or device, which can be read, write, both, delete, all of these, or none (refer to the following table). Access requests to attributes or extended attributes are not affected by this flag.
If this parameter is zero and the function succeeds, the file or device cannot be shared and cannot be opened again until the handle to the file or device is closed. For more information, see the Remarks section.

You can't request a sharing mode that conflicts with the access mode that is specified in an existing request that has an open handle. This function would fail and the [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function would return **ERROR\_SHARING\_VIOLATION**.

To enable a process to share a file or device while another process has the file or device open, use a compatible combination of one or more of the following values. For more information about valid combinations of this parameter with the *dwDesiredAccess* parameter, see [Creating and Opening Files](https://learn.microsoft.com/windows/win32/fileio/creating-and-opening-files).

**Note** The sharing options for each open handle remain in effect until that handle is closed, regardless of process context.

| Value | Meaning |
| --- | --- |
| **0** 0x00000000 | Prevents other processes from opening a file or device if they request delete, read, or write access. Exclusive access to a file or directory is only granted if the application has write access to the file. |
| **FILE_SHARE_DELETE** 0x00000004 | Enables subsequent open operations on a file or device to request delete access.<br><br>Otherwise, other processes cannot open the file or device if they request delete access.<br><br>If this flag is not specified, but the file or device has been opened for delete access, the function fails.<br><br>**Note** Delete access allows both delete and rename operations. |
| **FILE_SHARE_READ** 0x00000001 | Enables subsequent open operations on a file or device to request read access.<br><br>Otherwise, other processes cannot open the file or device if they request read access.<br><br>If this flag is not specified, but the file or device has been opened for read access, the function fails.<br><br>If a file or directory is being opened and this flag is not specified, and the caller does not have write access to the file or directory, the function fails. |
| **FILE_SHARE_WRITE** 0x00000002 | Enables subsequent open operations on a file or device to request write access.<br><br>Otherwise, other processes cannot open the file or device if they request write access.<br><br>If this flag is not specified, but the file or device has been opened for write access or has a file mapping with write access, the function fails. |

### `dwCreationDisposition`

An action to take on a file or device that exists or does not exist.
For devices other than files, this parameter is usually set to **OPEN\_EXISTING**.

This parameter must be one of the following values, which cannot be combined:

| Value | Meaning |
| --- | --- |
| **CREATE_ALWAYS** 2 | Creates a new file, always.<br><br>If the specified file exists and is writable, the function truncates the file, the function succeeds, and last-error code is set to **ERROR_ALREADY_EXISTS** (183).<br><br>If the specified file does not exist and is a valid path, a new file is created, the function succeeds, and the last-error code is set to zero. |
| **CREATE_NEW** 1 | Creates a new file, only if it does not already exist.<br><br>If the specified file exists, the function fails and the last-error code is set to **ERROR_FILE_EXISTS** (80).<br><br>If the specified file does not exist and is a valid path to a writable location, a new file is created. |
| **OPEN_ALWAYS** 4 | Opens a file, always.<br><br>If the specified file exists, the function succeeds and the last-error code is set to **ERROR_ALREADY_EXISTS** (183).<br><br>If the specified file does not exist and is a valid path to a writable location, the function creates a file and the last-error code is set to zero. |
| **OPEN_EXISTING** 3 | Opens a file or device, only if it exists.<br><br>If the specified file or device does not exist, the function fails and the last-error code is set to **ERROR_FILE_NOT_FOUND** (2). |
| **TRUNCATE_EXISTING** 5 | Opens a file and truncates it so that its size is zero bytes, only if it exists.<br><br>If the specified file does not exist, the function fails and the last-error code is set to **ERROR_FILE_NOT_FOUND** (2).<br><br>The calling process must open the file with the **GENERIC_WRITE** bit set as part of the *dwDesiredAccess* parameter. |

### `pCreateExParams`

Pointer to an optional [**CREATEFILE2\_EXTENDED\_PARAMETERS**](https://learn.microsoft.com/windows/win32/api/fileapi/ns-fileapi-createfile2_extended_parameters) structure.

## Return value

If the function succeeds, the return value is an open handle to the specified file, device, named pipe, or mail slot.

If the function fails, the return value is **INVALID\_HANDLE\_VALUE**. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also