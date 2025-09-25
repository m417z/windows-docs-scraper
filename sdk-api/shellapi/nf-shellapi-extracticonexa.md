# ExtractIconExA function

## Description

The **ExtractIconEx** function creates an array of handles to large or small icons extracted from the specified executable file, DLL, or icon file.

## Parameters

### `lpszFile` [in]

Type: **LPCTSTR**

Pointer to a null-terminated string that specifies the name of an executable file, DLL, or icon file from which icons will be extracted.

### `nIconIndex` [in]

Type: **int**

Specifies the zero-based index of the first icon to extract. For example, if this value is zero, the function extracts the first icon in the specified file.

If this value is –1 and *phiconLarge* and *phiconSmall* are both **NULL**, the function returns the total number of icons in the specified file. If the file is an executable file or DLL, the return value is the number of RT_GROUP_ICON resources. If the file is an .ico file, the return value is 1.

 If this value is a negative number and either *phiconLarge* or *phiconSmall* is not **NULL**, the function begins by extracting the icon whose resource identifier is equal to the absolute value of *nIconIndex*. For example, use -3 to extract the icon whose resource identifier is 3.

### `phiconLarge` [out]

Type: **HICON***

Pointer to an array of icon handles that receives handles to the large icons extracted from the file. If this parameter is **NULL**, no large icons are extracted from the file.

### `phiconSmall` [out]

Type: **HICON***

Pointer to an array of icon handles that receives handles to the small icons extracted from the file. If this parameter is **NULL**, no small icons are extracted from the file.

### `nIcons`

Type: **UINT**

The number of icons to extract from the file.

## Return value

Type: **UINT**

If the *nIconIndex* parameter is -1 and both the *phiconLarge* and *phiconSmall* parameters are **NULL**, then the return value is the number of icons contained in the specified file.

If the *nIconIndex* parameter is any value other than -1 and either *phiconLarge* or *phiconSmall* is not **NULL**, the return value is the number of icons successfully extracted from the file.

> [!NOTE]
> If the function encounters an error, it returns **UINT_MAX**. In this case, you can call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error code. For example, this function returns **UINT_MAX** if the file specified by *lpszFile* cannot be found while the *nIconIndex* parameter is any value other than -1 and either *phiconLarge* or *phiconSmall* is not **NULL**. In this case, **GetLastError** returns **ERROR_FILE_NOT_FOUND** (2).

## Remarks

When they are no longer needed, you must destroy all icons extracted by **ExtractIconEx** by calling the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.

To retrieve the dimensions of the large and small icons, use this function with the SM_CXICON, SM_CYICON, SM_CXSMICON, and SM_CYSMICON flags.

> [!NOTE]
> The shellapi.h header defines ExtractIconEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtractAssociatedIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extractassociatedicona)

[ExtractAssociatedIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extractassociatediconexa)

[ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona)