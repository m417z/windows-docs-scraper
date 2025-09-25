# CloseThemeData function

## Description

Closes the theme data handle.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an **HTHEME**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **CloseThemeData** function should be called when a window that has a visual style applied is destroyed. This function should also be called whenever a window receives a [WM_THEMECHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-themechanged) message. This call should be followed by an attempt to create a new theme data handle if a call to the [IsThemeActive](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-isthemeactive) function returns **TRUE**.

## See also

[OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata)