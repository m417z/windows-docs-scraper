# GetCurrentThemeName function

## Description

Retrieves the name of the current visual style, and optionally retrieves the color scheme name and size name.

## Parameters

### `pszThemeFileName` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that receives the theme path and file name.

### `cchMaxNameChars` [in]

Type: **int**

Value of type **int** that contains the maximum number of characters allowed in the theme file name.

### `pszColorBuff` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that receives the color scheme name. This parameter may be set to **NULL**.

### `cchMaxColorChars` [in]

Type: **int**

Value of type **int** that contains the maximum number of characters allowed in the color scheme name.

### `pszSizeBuff` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that receives the size name. This parameter may be set to **NULL**.

### `cchMaxSizeChars` [in]

Type: **int**

Value of type **int** that contains the maximum number of characters allowed in the size name.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful, otherwise an error code.