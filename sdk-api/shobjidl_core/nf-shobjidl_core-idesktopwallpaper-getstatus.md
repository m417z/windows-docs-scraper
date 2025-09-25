# IDesktopWallpaper::GetStatus

## Description

Gets the current status of the slideshow.

## Parameters

### `state` [out]

A pointer to a DESKTOP_SLIDESHOW_STATE value that, when this method returns successfully, receives one or more of the following flags.

#### DSS_ENABLED (0x01)

Slideshows are enabled.

#### DSS_SLIDESHOW (0x02)

A slideshow is currently configured.

#### DSS_DISABLED_BY_REMOTE_SESSION (0x04)

A remote session has temporarily disabled the slideshow.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)