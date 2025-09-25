# OpenThemeDataEx function

## Description

Opens the theme data associated with a window for specified theme classes.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a window or control that the theme is to be retrieved from.

### `pszClassList` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A semicolon-separated list of class names to match.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional flags that control how to return the theme data. May be set to a combination of the following values.

| Value | Meaning |
| --- | --- |
| **OTD_FORCE_RECT_SIZING** | Forces drawn images from this theme to stretch to fit the rectangles specified by drawing functions. |
| **OTD_NONCLIENT** | Allows theme elements to be drawn in the non-client area of the window. |

## Return value

Type: **HTHEME**

If a match is found, a valid handle to a theme is returned. Otherwise, a **NULL** value will be returned.

## Remarks

The string specified by *pszClassIdList* will be tokenized using semicolons as a delimiter. The names are matched against class names one token at a time. If no match is found for a particular token, the next token will be matched. If a match is found, the return value of the function will be the theme handle associated with the matched class.

Class names for the Aero theme are defined in AeroStyle.xml.

## See also

[OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata)