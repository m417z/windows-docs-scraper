# MsiGetFileVersionA function

## Description

The
**MsiGetFileVersion** returns the version string and language string in the format that the installer expects to find them in the database. If you want only version information, set *lpLangBuf* and *pcchLangBuf* to 0 (zero). If you just want language information, set *lpVersionBuf* and *pcchVersionBuf* to 0 (zero).

## Parameters

### `szFilePath` [in]

Specifies the path to the file.

### `lpVersionBuf` [out]

Returns the file version.

Set to 0 for language information only.

### `pcchVersionBuf` [in, out]

In and out buffer count as the number of **TCHAR**.

Set to 0 (zero) for language information only. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

### `lpLangBuf` [out]

Returns the file language.

Set to 0 (zero) for version information only.

### `pcchLangBuf` [in, out]

In and out buffer count as the number of **TCHAR**.

Set to 0 (zero) for version information only. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | Successful completion. |
| **ERROR_FILE_NOT_FOUND** | File does not exist. |
| **ERROR_ACCESS_DENIED** | File cannot be opened to get version information. |
| **ERROR_FILE_INVALID** | File does not contain version information. |
| **ERROR_INVALID_DATA** | The version information is invalid. |
| **E_FAIL** | Unexpected error. |

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

## Remarks

> [!NOTE]
> The msi.h header defines MsiGetFileVersion as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).