# IDesktopWallpaper::SetSlideshowOptions

## Description

Sets the desktop wallpaper slideshow settings for shuffle and timing.

## Parameters

### `options` [in]

Set to either 0 to disable shuffle or the following value.

#### DSO_SHUFFLEIMAGES (0x01)

Enable shuffle; advance through the slideshow in a random order.

### `slideshowTick` [in]

The amount of time, in milliseconds, between image transitions.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::GetSlideshowOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getslideshowoptions)