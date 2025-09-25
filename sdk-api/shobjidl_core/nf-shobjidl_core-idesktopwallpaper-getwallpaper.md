# IDesktopWallpaper::GetWallpaper

## Description

Gets the current desktop wallpaper.

## Parameters

### `monitorID` [in]

The ID of the monitor. This value can be obtained through [GetMonitorDevicePathAt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitordevicepathat).

This value can be set to **NULL**. In that case, if a single wallpaper image is displayed on all of the system's monitors, the method returns successfully. If this value is set to **NULL** and different monitors are displaying different wallpapers or a slideshow is running, the method returns S_FALSE and an empty string in the *wallpaper* parameter.

### `wallpaper` [out]

The address of a pointer to a buffer that, when this method returns successfully, receives the path to the wallpaper image file. Note that this image could be currently displayed on all of the system's monitors, not just the monitor specified in the *monitorID* parameter.

This string will be empty if no wallpaper image is being displayed or if a monitor is displaying a solid color. The string will also be empty if the method fails.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::SetWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setwallpaper)