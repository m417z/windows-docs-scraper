# GetTempFileNameA function

## Description

Creates a name for a temporary file. If a unique file name is generated, an empty file is created and the handle to it is released; otherwise, only a file name is generated.

## Parameters

### `lpPathName` [in]

The directory path for the file name. Applications typically specify a period (`.`) for the current directory or the result of the [GetTempPath2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-gettemppath2a) function. The string cannot be longer than **MAX_PATH**–14 characters or **GetTempFileName** will fail. If this parameter is `NULL`, the function fails.

### `lpPrefixString` [in]

The null-terminated prefix string. The function uses up to the first three characters of this string as the prefix of the file name. This string must consist of characters in the OEM-defined character set.

### `uUnique` [in]

An unsigned integer to be used in creating the temporary file name. For more information, see Remarks.

If *uUnique* is zero, the function attempts to form a unique file name using the current system time. If the file already exists, the number is increased by one and the functions tests if this file already exists. This continues until a unique filename is found; the function creates a file by that name and closes it. Note that the function does not attempt to verify the uniqueness of the file name when *uUnique* is nonzero.

### `lpTempFileName` [out]

A pointer to the buffer that receives the temporary file name. This buffer should be **MAX_PATH** characters to accommodate the path plus the terminating null character.

## Return value

If the function succeeds, the return value specifies the unique numeric value used in the temporary file name. If the *uUnique* parameter is nonzero, the return value specifies that same number.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following is a list of possible return values:

| Return value | Description |
|--------------|-------------|
| **ERROR_BUFFER_OVERFLOW** | The length of the string pointed to by the *lpPathName* parameter is more than **MAX_PATH**–14 characters. |

## Remarks

The **GetTempFileName** function creates a temporary file name of the following form:

`<path>\<pre><uuuu>.TMP`

The following table describes the file name syntax:

| Component | Meaning |
|-----------|---------|
| `<path>` | Path specified by the *lpPathName* parameter |
| `<pre>` | First three letters of the *lpPrefixString* string |
| `<uuuu>` | Hexadecimal value of *uUnique* |

If *uUnique* is zero, **GetTempFileName** creates an empty file and closes it. If *uUnique* is not zero, you must create the file yourself. Only a file name is created, because **GetTempFileName** is not able to guarantee that the file name is unique.

Only the lower 16 bits of the *uUnique* parameter are used. This limits **GetTempFileName** to a maximum of 65,535 unique file names if the *lpPathName* and *lpPrefixString* parameters remain the same.

Due to the algorithm used to generate file names, **GetTempFileName** can perform poorly when creating a large number of files with the same prefix. In such cases, it is recommended that you construct unique file names based on **GUID**s. You can also append the current process ID to the prefix string to reduce the likelihood of collisions in parallel operations.

Temporary files whose names have been created by this function are not automatically deleted. To delete these files call [DeleteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-deletefilea).

To avoid problems resulting when converting an ANSI string, an application should call the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function to create a temporary file.

Starting in Windows 8 and Windows Server 2012, this function is supported by the following technologies:

| Technology | Supported |
|------------|-----------|
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SOFS) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see [Creating and Using a Temporary File](https://learn.microsoft.com/windows/win32/FileIO/creating-and-using-a-temporary-file).

> [!NOTE]
> The fileapi.h header defines GetTempFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)

[DeleteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-deletefilea)

[File Management Functions](https://learn.microsoft.com/windows/win32/FileIO/file-management-functions)

[GetTempPath2](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-gettemppath2a)

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/FileIO/naming-a-file)