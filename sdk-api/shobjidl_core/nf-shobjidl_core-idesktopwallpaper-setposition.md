# IDesktopWallpaper::SetPosition

## Description

Sets the display option for the desktop wallpaper image, determining whether the image should be centered, tiled, or stretched.

## Parameters

### `position` [in]

One of the [DESKTOP_WALLPAPER_POSITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-desktop_wallpaper_position) enumeration values that specify how the image will be displayed on the system's monitors.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The desktop wallpaper is already displayed as asked for in *position*. |

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::GetPosition](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getposition)