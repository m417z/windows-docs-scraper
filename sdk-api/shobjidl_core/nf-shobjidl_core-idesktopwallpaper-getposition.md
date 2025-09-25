# IDesktopWallpaper::GetPosition

## Description

Retrieves the current display value for the desktop background image.

## Parameters

### `position` [out]

A pointer to a value that, when this method returns successfully, receives one of the [DESKTOP_WALLPAPER_POSITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-desktop_wallpaper_position) enumeration values that specify how the image is being displayed on the system's monitors.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A **NULL** pointer was provided in *position*. |

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::SetPosition](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setposition)