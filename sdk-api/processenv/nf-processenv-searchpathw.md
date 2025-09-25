# SearchPathW function

## Description

Searches for a specified file in a specified path.

## Parameters

### `lpPath` [in, optional]

The path to be searched for the file.

If this parameter is **NULL**, the
function searches for a matching file using a registry-dependent system search path. For more information, see
the Remarks section.

### `lpFileName` [in]

The name of the file for which to search.

### `lpExtension` [in, optional]

The extension to be added to the file name when searching for the file. The first character of the file name
extension must be a period (.). The extension is added only if the specified file name does not end with an
extension.

If a file name extension is not required or if the file name contains an extension, this parameter can be
**NULL**.

### `nBufferLength` [in]

The size of the buffer that receives the valid path and file name (including the terminating null
character), in **TCHARs**.

### `lpBuffer` [out]

A pointer to the buffer to receive the path and file name of the file found. The string is a
null-terminated string.

### `lpFilePart` [out, optional]

A pointer to the variable to receive the address (within *lpBuffer*) of the last
component of the valid path and file name, which is the address of the character immediately following the final
backslash (\\) in the path.

## Return value

If the function succeeds, the value returned is the length, in **TCHARs**, of the
string that is copied to the buffer, not including the terminating null character. If the return value is
greater than *nBufferLength*, the value returned is the size of the buffer that is
required to hold the path, including the terminating null character.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *lpPath* parameter is **NULL**,
**SearchPath** searches for a matching file based on the current
value of the following registry value:

**HKEY_LOCAL_MACHINE**\**SYSTEM**\**CurrentControlSet**\**Control**\**Session Manager**\**SafeProcessSearchMode**

When the value of this **REG_DWORD** registry value is set to 1,
**SearchPath** first searches the folders that are specified in
the system path, and then searches the current working folder. When the value of this registry value is set to 0,
the computer first searches the current working folder, and then searches the folders that are specified in the
system path. The system default value for this registry key is 0.

The search mode used by the **SearchPath** function can also
be set per-process by calling the [SetSearchPathMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setsearchpathmode)
function.

The **SearchPath** function is not recommended as a method of
locating a .dll file if the intended use of the output is in a call to the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. This can result in locating the
wrong .dll file because the search order of the **SearchPath**
function differs from the search order used by the
**LoadLibrary** function. If you need to locate and load a
.dll file, use the **LoadLibrary** function.

**Tip** Starting with Windows 10, version 1607, for the unicode version of this function (**SearchPathW**), you can opt-in to remove the **MAX_PATH** limitation. See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) for details.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

> [!NOTE]
> The processenv.h header defines SearchPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea)

[GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya)

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)

[SetSearchPathMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setsearchpathmode)