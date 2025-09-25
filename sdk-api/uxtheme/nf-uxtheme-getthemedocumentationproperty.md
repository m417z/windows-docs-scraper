# GetThemeDocumentationProperty function

## Description

Retrieves the value for a theme property from the documentation section of the specified theme file.

## Parameters

### `pszThemeName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that contains the name of the theme file that will be opened to query for the property.

### `pszPropertyName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that contains the name of the theme property to query. Can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SZ_THDOCPROP_DISPLAYNAME** | Retrieves the display name of the theme. |
| **SZ_THDOCPROP_TOOLTIP** | Retrieves the tooltip associated with this theme. |
| **SZ_THDOCPROP_AUTHOR** | Retrieves the name of the author of the theme. |
| **SZ_THDOCPROP_CANONICALNAME** | Retrieves the name of the theme. |

### `pszValueBuff` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string buffer that receives the property string value.

### `cchMaxValChars` [in]

Type: **int**

Value of type **int** that specifies the maximum number of characters that *pszValueBuff* can contain.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the theme property has been localized in the theme files string table, this function returns the localized version.