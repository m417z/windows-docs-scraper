# ExtractAssociatedIconExA function

## Description

[**ExtractAssociatedIconEx** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets a handle to an icon stored as a resource in a file or an icon stored in a file's associated executable file. It extends the [ExtractAssociatedIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extractassociatedicona) function by retrieving the icon's ID when that icon is extracted from an executable file.

## Parameters

### `hInst` [in]

Type: **HINSTANCE**

The handle of the module from which to extract the icon.

### `pszIconPath` [in, out]

Type: **LPTSTR**

Pointer to a string that, on entry, specifies the full path and file name of the file that contains the icon. The function extracts the icon handle from that file, or from an executable file associated with that file.

When this function returns, if the icon handle was obtained from an executable file (either an executable file directly pointed to by this parameter or an associated executable file) the function stores the full path and file name of that executable in the buffer pointed to by this parameter.

### `piIconIndex` [in, out]

Type: **LPWORD**

Pointer to a **WORD** value that, on entry, specifies the index of the icon whose handle is to be obtained.

When the function returns, if the icon handle was obtained from an executable file (either an executable file pointed to by *lpIconPath* or an associated executable file), this value points to the icon's index in that file.

### `piIconId` [in, out]

Type: **LPWORD**

Pointer to a **WORD** value that, on entry, specifies the ID of the icon whose handle is to be obtained.

When the function returns, if the icon handle was obtained from an executable file (either an executable file pointed to by *lpIconPath* or an associated executable file), this value points to the icon's ID within that file.

## Return value

Type: **HICON**

Returns the icon's handle if successful, otherwise **NULL**.

## Remarks

The icon handle returned by this function must be released by calling [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) when it is no longer needed.

> [!NOTE]
> The shellapi.h header defines ExtractAssociatedIconEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtractAssociatedIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extractassociatedicona)

[ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona)

[ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa)