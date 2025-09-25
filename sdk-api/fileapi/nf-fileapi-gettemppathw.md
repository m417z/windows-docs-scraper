# GetTempPathW function

## Description

Retrieves the path of the directory designated for temporary files.

## Parameters

### `nBufferLength` [in]

The size of the string buffer identified by *lpBuffer*, in
**TCHARs**.

### `lpBuffer` [out]

A pointer to a string buffer that receives the null-terminated string specifying the temporary file path.
The returned string ends with a backslash, for example, "C:\\TEMP\\".

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the
string copied to *lpBuffer*, not including the terminating null character. If the
return value is greater than *nBufferLength*, the return value is the length, in
**TCHARs**, of the buffer required to hold the path.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The maximum possible return value is **MAX_PATH**+1 (261).

## Remarks

> [!NOTE]
> Apps should call [GetTempPath2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-gettemppath2w) instead of **GetTempPath**.

The **GetTempPath** function checks for the existence of
environment variables in the following order and uses the first path found:

1. The path specified by the TMP environment variable.
2. The path specified by the TEMP environment variable.
3. The path specified by the USERPROFILE environment variable.
4. The Windows directory.

Note that the function does not verify that the path exists, nor does it test to see if the current process has
any kind of access rights to the path. The **GetTempPath**
function returns the properly formatted string that specifies the fully qualified path based on the environment
variable search order as previously specified. The application should verify the existence of the path and
adequate access rights to the path prior to any use for file I/O operations.

Symbolic link behavior—If the path points to a symbolic link, the temp path name
maintains any symbolic links.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see
[Creating and Using a Temporary File](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-using-a-temporary-file).

> [!NOTE]
> The fileapi.h header defines GetTempPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetTempFileName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-gettempfilenamea)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)