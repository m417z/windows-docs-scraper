# IDesktopWallpaper::SetBackgroundColor

## Description

Sets the color that is visible on the desktop when no image is displayed or when the desktop background has been disabled. This color is also used as a border when the desktop wallpaper does not fill the entire screen.

## Parameters

### `color` [in]

A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that specifies the background RGB color value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::GetBackgroundColor](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getbackgroundcolor)