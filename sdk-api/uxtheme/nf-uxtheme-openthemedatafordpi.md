# OpenThemeDataForDpi function

## Description

A variant of [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) that opens a theme handle associated with a specific DPI.

## Parameters

### `hwnd`

The handle of the window for which theme data is required.

### `pszClassList`

A pointer to a string that contains a semicolon-separated list of classes.

### `dpi`

The specified DPI value with which to associate the theme handle. The function will return an error if this value is outside of those that correspond to the set of connected monitors.

## Return value

See [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata).

## Remarks

[OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) will create theme handles associated with the DPI of a window when used with Per Monitor v2 windows. OpenThemeDataForDpi allows you to open a theme handle for a specific DPI when you do not have a window at that DPI.

The behavior of the returned theme handle will be undermined if the requested DPI value does not correspond to a currently connected display. The theming system only loads theme assets for the set of DPI values corresponding to the *currently* connected displays.

The theme handle will become invalid anytime the system reloads the theme data. Applications are required to monitor [WM_THEMECHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-themechanged) and close and reopen all theme handles in response. This behavior is the same regardless of whether the handles were opened via OpenThemeData or OpenThemeDataForDpi.

## See also

[OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata)