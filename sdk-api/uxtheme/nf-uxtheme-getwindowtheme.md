# GetWindowTheme function

## Description

Retrieves a theme handle to a window that has visual styles applied.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle of the window.

## Return value

Type: **HTHEME**

The most recent theme handle from [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata).

## Remarks

If a window has a visual style applied, the **GetWindowTheme** function returns the most recent theme handle from [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata). If no visual style is applied, **GetWindowTheme** returns **NULL**.