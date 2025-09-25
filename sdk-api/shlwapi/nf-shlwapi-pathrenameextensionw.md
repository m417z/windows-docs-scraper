# PathRenameExtensionW function

## Description

Replaces the extension of a file name with a new extension. If the file name does not contain an extension, the extension will be attached to the end of the string.

**Note** Misuse of this function can lead to a buffer overrun. We recommend the use of the safer [PathCchRenameExtension](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchrenameextension) function in its place.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

Pointer to a null-terminated string of length MAX_PATH in which to replace the extension.

### `pszExt` [in]

Type: **LPCTSTR**

Pointer to a character buffer that contains a '.' character followed by the new extension.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero if the new path and extension would exceed MAX_PATH characters.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathRenameExtension as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).