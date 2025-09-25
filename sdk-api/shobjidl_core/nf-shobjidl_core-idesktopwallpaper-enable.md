# IDesktopWallpaper::Enable

## Description

Enables or disables the desktop background.

## Parameters

### `enable` [in]

**TRUE** to enable the desktop background, **FALSE** to disable it.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The desktop wallpaper is already in the state you're asking for through this call. |
| **E_FILE_NOT_FOUND** | The desktop wallpaper that would be used when the background is enabled is missing from its expected location. Call [SetWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setwallpaper) to specify a new wallpaper. |

## Remarks

This method would normally be called to disable the desktop background for performance reasons.

When the desktop background is disabled, a solid color is shown in its place. To get or set the specific color, use the [GetBackgroundColor](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getbackgroundcolor) and [SetBackgroundColor](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setbackgroundcolor) methods.

**Note** A call to the [IDesktopWallpaper_SetWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setwallpaper) or [IDesktopWallpaper_SetSlideshow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setslideshow) methods will enable the desktop background even if it is currently disabled through this method.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)