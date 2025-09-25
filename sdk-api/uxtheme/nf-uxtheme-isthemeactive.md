# IsThemeActive function

## Description

Tests if a visual style for the current application is active.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | A visual style is enabled, and windows with visual styles applied should call [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to start using theme drawing services. |
| **FALSE** | A visual style is not enabled, and the window message handler does not need to make another call to [IsThemeActive](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-isthemeactive) until it receives a WM_THEMECHANGED message. |

## Remarks

Do not call this function during [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) or global objects constructors. This may cause invalid return values.