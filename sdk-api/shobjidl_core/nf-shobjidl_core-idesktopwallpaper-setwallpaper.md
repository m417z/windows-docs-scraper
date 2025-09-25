# IDesktopWallpaper::SetWallpaper

## Description

Sets the desktop wallpaper.

## Parameters

### `monitorID` [in]

The ID of the monitor. This value can be obtained through [GetMonitorDevicePathAt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitordevicepathat). Set this value to NULL to set the wallpaper image on all monitors.

### `wallpaper` [in]

The full path of the wallpaper image file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::GetWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getwallpaper)