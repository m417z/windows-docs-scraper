# CopyFile2 function

## Description

Copies an existing file to a new file, notifying the application of its progress through a callback
function.

## Parameters

### `pwszExistingFileName` [in]

The name of an existing file.

To extend this limit to 32,767 wide characters, prepend "\\?\" to the path. For more
information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

**Tip** Starting in Windows 10, version 1607, you can opt-in to remove the **MAX_PATH** character limitation without prepending "\\?\". See the "Maximum Path Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) for details.

If *lpExistingFileName* does not exist, the
**CopyFile2** function fails returns
`HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)`.

### `pwszNewFileName` [in]

The name of the new file.

To extend this limit to 32,767 wide characters, prepend "\\?\" to the path. For more
information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

**Tip** Starting in Windows 10, version 1607, you can opt-in to remove the **MAX_PATH** character limitation without prepending "\\?\". See the "Maximum Path Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) for details.

### `pExtendedParameters` [in, optional]

Optional address of a
[COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters)
structure.

## Return value

If the function succeeds, the return value will return **TRUE** when passed to the
[SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) macro.

| Return code | Description |
| --- | --- |
| **S_OK** | The copy operation completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_REQUEST_PAUSED)** | The copy operation was paused by a **COPYFILE2_PROGRESS_PAUSE** return from the [CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) callback function. |
| **HRESULT_FROM_WIN32(ERROR_REQUEST_ABORTED)** | The copy operation was paused by a **COPYFILE2_PROGRESS_CANCEL** or **COPYFILE2_PROGRESS_STOP** return from the [CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) callback function. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | The **dwCopyFlags** member of the [COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters) structure passed through the *pExtendedParameters* parameter contains the **COPY_FILE_FAIL_IF_EXISTS** flag and a conflicting name existed. |
| **HRESULT_FROM_WIN32(ERROR_FILE_EXISTS)** | The **dwCopyFlags** member of the [COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters) structure passed through the *pExtendedParameters* parameter contains the **COPY_FILE_FAIL_IF_EXISTS** flag and a conflicting name existed. |

## Remarks

This function preserves extended attributes, OLE structured storage, NTFS file system alternate data streams,
and file attributes. Security attributes for the existing file are not copied to the new file. To copy security
attributes, use the [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) function.

This function fails with
`HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)` if the destination
file already exists and has the **FILE_ATTRIBUTE_HIDDEN** or
**FILE_ATTRIBUTE_READONLY** attribute set.

To compile an application that uses this function, define the **_WIN32_WINNT** macro
as **_WIN32_WINNT_WIN8** or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

Starting with Windows 10, version 1903 and Windows Server 2022, a new value, **COPY_FILE_REQUEST_COMPRESSED_TRAFFIC**, is supported for the *dwCopyFlags* field of the [COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winbase/ns-winbase-copyfile2_extended_parameters) structure passed in the *pExtendedParameters* argument to this function. This new value requests that the underlying transfer channel compress the data during the copy operation. The request may not be supported for all mediums, in which case it is ignored. The compression attributes and parameters (computational complexity, memory usage) are not configurable through this API, and are subject to change between different OS releases. On Windows 10, the flag is supported for files residing on SMB shares, where the negotiated SMB protocol version is SMB v3.1.1 or greater.

## See also

[COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)