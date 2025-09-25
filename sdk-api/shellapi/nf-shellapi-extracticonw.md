# ExtractIconW function

## Description

Gets a handle to an icon from the specified executable file, DLL, or icon file.

To retrieve an array of handles to large or small icons, use the [ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa) function.

## Parameters

### `hInst` [in]

Type: **HINSTANCE**

Handle to the instance of the application that calls the function.

### `pszExeFileName` [in]

Type: **LPCTSTR**

Pointer to a null-terminated string that specifies the name of an executable file, DLL, or icon file.

### `nIconIndex`

Type: **UINT**

Specifies the zero-based index of the icon to retrieve. For example, if this value is 0, the function returns a handle to the first icon in the specified file.

If this value is -1, the function returns the total number of icons in the specified file. If the file is an executable file or DLL, the return value is the number of RT_GROUP_ICON resources. If the file is an .ICO file, the return value is 1.

If this value is a negative number not equal to –1, the function returns a handle to the icon in the specified file whose resource identifier is equal to the absolute value of *nIconIndex*. For example, you should use –3 to extract the icon whose resource identifier is 3. To extract the icon whose resource identifier is 1, use the [ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa) function.

## Return value

Type: **HICON**

The return value is a handle to an icon. If the file specified was not an executable file, DLL, or icon file, the return is 1. If no icons were found in the file, the return value is **NULL**.

## Remarks

When it is no longer needed, you must destroy the icon handle returned by **ExtractIcon** by calling the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.

> [!NOTE]
> The shellapi.h header defines ExtractIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtractAssociatedIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extractassociatedicona)

[ExtractAssociatedIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extractassociatediconexa)

[ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa)