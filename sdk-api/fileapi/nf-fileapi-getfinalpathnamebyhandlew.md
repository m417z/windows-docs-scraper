# GetFinalPathNameByHandleW function

## Description

Retrieves the final path for the specified file.

For more information about file and path names, see
[Naming a File](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

## Parameters

### `hFile` [in]

A handle to a file or directory.

### `lpszFilePath` [out]

A pointer to a buffer that receives the path of *hFile*.

### `cchFilePath` [in]

The size of *lpszFilePath*, in **TCHAR**s. This value must include a **NULL** termination character.

### `dwFlags` [in]

The type of result to return. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_NAME_NORMALIZED**<br><br>0x0 | Return the normalized drive name. This is the default. |
| **FILE_NAME_OPENED**<br><br>0x8 | Return the opened file name (not normalized). |

This parameter can also include one of the following values.

| Value | Meaning |
| --- | --- |
| **VOLUME_NAME_DOS**<br><br>0x0 | Return the path with the drive letter. This is the default. |
| **VOLUME_NAME_GUID**<br><br>0x1 | Return the path with a volume **GUID** path instead of the drive name. |
| **VOLUME_NAME_NONE**<br><br>0x4 | Return the path with no drive information. |
| **VOLUME_NAME_NT**<br><br>0x2 | Return the NT device object path. |

## Return value

If the function succeeds, the return value is the length of the string received by
*lpszFilePath*, in **TCHAR**s. This value does not include the
size of the terminating null character.

**Windows Server 2008 and Windows Vista:** For the ANSI version of this function,
**GetFinalPathNameByHandleA**, the return value
includes the size of the terminating null character.

If the function fails because *lpszFilePath* is too small to hold the string plus the
terminating null character, the return value is the required buffer size, in
**TCHAR**s. This value includes the size of the terminating null character.

If the function fails for any other reason, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

| Return code | Description |
| --- | --- |
| **ERROR_PATH_NOT_FOUND** | Can be returned if you are searching for a drive letter and one does not exist. For example, the handle was opened on a drive that is not currently mounted, or if you create a volume and do not assign it a drive letter. If a volume has no drive letter, you can use the volume **GUID** path to identify it.<br><br>This return value can also be returned if you are searching for a volume **GUID** path on a network share. Volume **GUID** paths are not created for network shares. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory to complete the operation. |
| **ERROR_INVALID_PARAMETER** | Invalid flags were specified for *dwFlags*. |

## Remarks

The Server Message Block (SMB) Protocol does not support queries for normalized paths. Consequently, when you call this function passing the handle of a file opened using SMB, and with the FILE_NAME_NORMALIZED flag, the function splits the path into its components and tries to query for the normalized name of each of those components in turn. If the user lacks access permission to any one of those components, then the function call fails with ERROR_ACCESS_DENIED.

 A final path is the path that is returned when a path is fully resolved. For example, for a symbolic link
named "C:\tmp\mydir" that points to "D:\yourdir", the final path would be
"D:\yourdir".

When using **VOLUME_NAME_DOS**, the string that is returned by this function uses the "\\\\?\\"
syntax. For more information, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).
When using **VOLUME_NAME_GUID**, the returned path will begin with a volume GUID path formatted like "\\\\?\\Volume{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}\\".

When using **VOLUME_NAME_NT**, the returned path is for an NT device object, and will begin with a device name such as "\\Device\\HarddiskVolume1\\". This type of path can not be used directly by Windows programs, as it resembles a relative path.

Some third-party drivers can create a drive letter or mount point without using the Mount Manager. If the Mount Manager was not used to create the drive, then **VOLUME_NAME_DOS** or **VOLUME_NAME_GUID** will not succeed; only **VOLUME_NAME_NT** will be available. To determine the drive letter for the volume device path, use the [QueryDosDevice](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-querydosdevicew) function on every drive letter until a matching device name is found.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

The following example demonstrates the use of the
**GetFinalPathNameByHandle** function.

```cpp
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define BUFSIZE MAX_PATH

void __cdecl _tmain(int argc, TCHAR *argv[])
{
    TCHAR Path[BUFSIZE];
    HANDLE hFile;
    DWORD dwRet;

    printf("\n");
    if( argc != 2 )
    {
        printf("ERROR:\tIncorrect number of arguments\n\n");
        printf("%s <file_name>\n", argv[0]);
        return;
    }

    hFile = CreateFile(argv[1],               // file to open
                       GENERIC_READ,          // open for reading
                       FILE_SHARE_READ,       // share for reading
                       NULL,                  // default security
                       OPEN_EXISTING,         // existing file only
                       FILE_ATTRIBUTE_NORMAL, // normal file
                       NULL);                 // no attr. template

    if( hFile == INVALID_HANDLE_VALUE)
    {
        printf("Could not open file (error %d\n)", GetLastError());
        return;
    }

    dwRet = GetFinalPathNameByHandle( hFile, Path, BUFSIZE, VOLUME_NAME_NT );
    if(dwRet < BUFSIZE)
    {
        _tprintf(TEXT("\nThe final path is: %s\n"), Path);
    }
    else printf("\nThe required buffer size is %d.\n", dwRet);

    CloseHandle(hFile);
}

```

> [!NOTE]
> The fileapi.h header defines GetFinalPathNameByHandle as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)