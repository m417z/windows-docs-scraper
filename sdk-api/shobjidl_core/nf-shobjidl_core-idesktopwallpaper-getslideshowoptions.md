# IDesktopWallpaper::GetSlideshowOptions

## Description

Gets the current desktop wallpaper slideshow settings for shuffle and timing.

## Parameters

### `options` [out]

Type: **DESKTOP_SLIDESHOW_OPTIONS***

A pointer to a value that, when this method returns successfully, receives either 0 to indicate that shuffle is disabled or the following value.

#### DSO_SHUFFLEIMAGES (0x01)

Shuffle is enabled; the images are shown in a random order.

### `slideshowTick` [out]

Type: **UINT***

A pointer to a value that, when this method returns successfully, receives the interval between image transitions, in milliseconds.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A **NULL** pointer was provided in one of the parameters. |

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::SetSlideshowOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setslideshowoptions)