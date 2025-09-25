# SetFileShortNameA function

## Description

Sets the short name for the specified file. The file must be on an NTFS file system volume.

## Parameters

### `hFile` [in]

A handle to the file. The file must be opened with **DELETE**, and with the **FILE_FLAG_BACKUP_SEMANTICS** file attribute.

> [!NOTE]
> Prior to Windows 10, Version 1903, the file must be opened with either the **GENERIC_ALL** access right or **GENERIC_WRITE**\|**DELETE**, and with the **FILE_FLAG_BACKUP_SEMANTICS** file attribute.

### `lpShortName` [in]

A pointer to a string that specifies the short name for the file.

Specifying an empty (zero-length) string will remove the short file name, if it exists for the file specified by the *hFile* parameter. If a short file name does not exist, the function will do nothing and return success.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This behavior is not supported. The parameter must contain a valid string of one or more characters.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes that are specific to this function:

| Return code | Description |
| ----------- | ----------- |
| **ERROR_ALREADY_EXISTS** | The specified short name is not unique. |
| **ERROR_INVALID_PARAMETER** | Either the specified file has been opened in case-sensitive mode or the specified short name is invalid. |

## Remarks

> [!NOTE]
> Prior to Windows 10, Version 1903, the **SE_RESTORE_NAME** privilege was required to call this function. For more information, see [Running with Special Privileges](https://learn.microsoft.com/windows/win32/secbp/running-with-special-privileges).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies:

| Technology | Supported |
| ---------- | --------- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support short names on shares with continuous availability capability . Short names are not recommended on CsvFs.

> [!NOTE]
> The `winbase.h` header defines **SetFileShortName** as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/win32/FileIO/file-management-functions)

[GetShortPathName](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getshortpathnamew)