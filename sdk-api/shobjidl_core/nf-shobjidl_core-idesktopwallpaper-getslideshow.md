# IDesktopWallpaper::GetSlideshow

## Description

Gets the path to the directory where the slideshow images are stored.

## Parameters

### `items` [out]

The address of a pointer to an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray) object that, when this method returns successfully, receives the items that make up the slideshow. This array can contain individual items stored in the same container, or it can contain a single item which is the container itself.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A **NULL** pointer was provided in *position*. |

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::SetSlideshow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-setslideshow)