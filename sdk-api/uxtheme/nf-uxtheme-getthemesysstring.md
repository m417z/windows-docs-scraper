# GetThemeSysString function

## Description

Retrieves the value of a system string.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to theme data.

### `iStringId` [in]

Type: **int**

Value of type **int** that specifies a system string. May be one of the following values.

| Value | Meaning |
| --- | --- |
| **TMT_CSSNAME** | The name of the CSS file associated with the theme specified by *hTheme*. |
| **TMT_XMLNAME** | The name of the XML file associated with the theme specified by *hTheme*. |

### `pszStringBuff` [out]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the buffer that receives the string value from this function.

### `cchMaxStringChars` [in]

Type: **int**

Value of type **int** that specifies the maximum number of characters the string buffer can hold.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the theme data handle is not a **NULL** handle, this function returns the desired string from the SysMetrics section of the visual style. If the theme data handle is **NULL**, this function returns the value of the global system metric of the same type.