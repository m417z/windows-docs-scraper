# IDesktopWallpaper::SetSlideshow

## Description

Specifies the images to use for the desktop wallpaper slideshow.

## Parameters

### `items` [in]

A pointer to an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray) that contains the slideshow images. This array can contain individual items stored in the same container (files stored in a folder), or it can contain a single item which is the container itself (a folder that contains images). Any other configuration of the array will cause this method to fail.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::GetSlideshow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getslideshow)