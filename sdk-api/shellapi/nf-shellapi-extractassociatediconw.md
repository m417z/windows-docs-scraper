# ExtractAssociatedIconW function

## Description

Gets a handle to an icon stored as a resource in a file or an icon stored in a file's associated executable file.

## Parameters

### `hInst` [in]

Type: **HINSTANCE**

A handle to the instance of the calling application.

### `pszIconPath` [in, out]

Type: **LPTSTR**

Pointer to a string that, on entry, specifies the full path and file name of the file that contains the icon. The function extracts the icon handle from that file, or from an executable file associated with that file.

When this function returns, if the icon handle was obtained from an executable file (either an executable file pointed to by *lpIconPath* or an associated executable file) the function stores the full path and file name of that executable in the buffer pointed to by this parameter.

### `piIcon` [in, out]

Type: **LPWORD**

Pointer to a **WORD** value that, on entry, specifies the index of the icon whose handle is to be obtained.

When the function returns, if the icon handle was obtained from an executable file (either an executable file pointed to by *lpIconPath* or an associated executable file), this value points to the icon's index in that file.

## Return value

Type: **HICON**

If the function succeeds, the return value is an icon handle. If the icon is extracted from an associated executable file, the function stores the full path and file name of the executable file in the string pointed to by *lpIconPath*, and stores the icon's identifier in the **WORD** pointed to by *lpiIcon*.

If the function fails, the return value is **NULL**.

## Remarks

When it is no longer needed, the caller is responsible for freeing the icon handle returned by **ExtractAssociatedIcon** by calling the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.

The **ExtractAssociatedIcon** function first looks for the indexed icon in the file specified by *lpIconPath*. If the function cannot obtain the icon handle from that file, and the file has an associated executable file, it looks in that executable file for an icon. Associations with executable files are based on file name extensions and are stored in the per-user part of the registry.

> [!NOTE]
> The shellapi.h header defines ExtractAssociatedIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtractAssociatedIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extractassociatediconexa)

[ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona)

[ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa)