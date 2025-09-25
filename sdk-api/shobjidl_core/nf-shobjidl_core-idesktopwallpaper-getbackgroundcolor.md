# IDesktopWallpaper::GetBackgroundColor

## Description

Retrieves the color that is visible on the desktop when no image is displayed or when the desktop background has been disabled. This color is also used as a border when the desktop wallpaper does not fill the entire screen.

## Parameters

### `color` [out]

A pointer to a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that, when this method returns successfully, receives the RGB color value. If this method fails, this value is set to 0.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::SetBackgroundColor](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setbackgroundcolor)