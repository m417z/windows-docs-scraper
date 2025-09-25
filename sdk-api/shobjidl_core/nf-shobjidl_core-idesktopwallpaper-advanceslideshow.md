# IDesktopWallpaper::AdvanceSlideshow

## Description

Switches the wallpaper on a specified monitor to the next image in the slideshow.

## Parameters

### `monitorID` [in]

The ID of the monitor on which to change the wallpaper image. This ID can be obtained through the [GetMonitorDevicePathAt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitordevicepathat) method. If this parameter is set to **NULL**, the monitor scheduled to change next is used.

### `direction` [in]

The direction that the slideshow should advance. One of the following DESKTOP_SLIDESHOW_DIRECTION values:

#### DSD_FORWARD (0)

Advance the slideshow forward.

#### DSD_BACKWARD (1)

Advance the slideshow backward.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)