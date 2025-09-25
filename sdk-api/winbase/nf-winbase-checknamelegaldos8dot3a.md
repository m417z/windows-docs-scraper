# CheckNameLegalDOS8Dot3A function

## Description

Determines whether the specified name can be used to create a file on a FAT file
system.

## Parameters

### `lpName` [in]

The file name, in 8.3 format.

### `lpOemName` [out, optional]

A pointer to a buffer that receives the OEM string that corresponds to *Name*. This
parameter can be **NULL**.

### `OemNameSize` [in]

The size of the *lpOemName* buffer, in characters. If
*lpOemName* is **NULL**, this parameter must be 0 (zero).

### `pbNameContainsSpaces` [out, optional]

Indicates whether or not a name contains spaces. This parameter can be **NULL**. If
the name is not a valid 8.3 FAT file system name, this parameter is undefined.

### `pbNameLegal` [out]

If the function succeeds, this parameter indicates whether a file name is a valid 8.3 FAT file name when
the current OEM code page is applied to the file name.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function can be used to determine whether or not a file name can be passed to a 16-bit Windows-based
application or an MS-DOS-based application.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | See remarks |
| SMB 3.0 with Scale-out File Shares (SO) | See remarks |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

Note that SMB 3.0 does not support short names on shares with continuous availability capability, so function will always return zero (fail).

> [!NOTE]
> The winbase.h header defines CheckNameLegalDOS8Dot3 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetOEMCP](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getoemcp)