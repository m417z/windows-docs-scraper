# OpenThemeData function

## Description

Opens the theme data for a window and its associated class.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle of the window for which theme data is required.

### `pszClassList` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that contains a semicolon-separated list of classes.

## Return value

Type: **HTHEME**

**OpenThemeData** tries to match each class, one at a time, to a class data section in the active theme. If a match is found, an associated HTHEME handle is returned. If no match is found **NULL** is returned.

## Remarks

The *pszClassList* parameter contains a list, not just a single name, to provide the class an opportunity to get the best match between the class and the current visual style. For example, a button might pass L"OkButton;Button"
if its ID is ID_OK. If the current visual style has an entry for OkButton, that is used; otherwise no visual style is applied.

Class names for the Aero theme are defined in AeroStyle.xml.

## See also

[CloseThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-closethemedata)