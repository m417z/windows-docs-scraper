# IShellItemImageFactory::GetImage

## Description

Gets an **HBITMAP** that represents an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem). The default behavior is to load a thumbnail. If there is no thumbnail for the current **IShellItem**, it retrieves an **HBITMAP** for the icon of the item. The thumbnail or icon is extracted if it is not currently cached.

## Parameters

### `size` [in]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)**

A structure that specifies the size of the image to be received.

### `flags` [in]

Type: **SIIGBF**

One or more of the following:

#### SIIGBF_RESIZETOFIT (0x00000000)

Shrink the bitmap as necessary to fit, preserving its aspect ratio.

#### SIIGBF_BIGGERSIZEOK (0x00000001)

Passed by callers if they want to stretch the returned image themselves. For example, if the caller passes an icon size of 80x80, a 96x96 thumbnail could be returned. This action can be used as a performance optimization if the caller expects that they will need to stretch the image. Note that the Shell implementation of [IShellItemImageFactory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemimagefactory) performs a GDI stretch blit. If the caller wants a higher quality image stretch than provided through that mechanism, they should pass this flag and perform the stretch themselves.

#### SIIGBF_MEMORYONLY (0x00000002)

Return the item only if it is already in memory. Do not access the disk even if the item is cached. Note that this only returns an already-cached icon and can fall back to a per-class icon if an item has a per-instance icon that has not been cached. Retrieving a thumbnail, even if it is cached, always requires the disk to be accessed, so **GetImage** should not be called from the UI thread without passing **SIIGBF_MEMORYONLY**.

#### SIIGBF_ICONONLY (0x00000004)

Return only the icon, never the thumbnail.

#### SIIGBF_THUMBNAILONLY (0x00000008)

Return only the thumbnail, never the icon. Note that not all items have thumbnails, so **SIIGBF_THUMBNAILONLY** will cause the method to fail in these cases.

#### SIIGBF_INCACHEONLY (0x00000010)

Allows access to the disk, but only to retrieve a cached item. This returns a cached thumbnail if it is available. If no cached thumbnail is available, it returns a cached per-instance icon but does not extract a thumbnail or icon.

#### SIIGBF_CROPTOSQUARE (0x00000020)

**Introduced in Windows 8**. If necessary, crop the bitmap to a square.

#### SIIGBF_WIDETHUMBNAILS (0x00000040)

**Introduced in Windows 8**. Stretch and crop the bitmap to a 0.7 aspect ratio.

#### SIIGBF_ICONBACKGROUND (0x00000080)

**Introduced in Windows 8**. If returning an icon, paint a background using the associated app's registered background color.

#### SIIGBF_SCALEUP (0x00000100)

**Introduced in Windows 8**. If necessary, stretch the bitmap so that the height and width fit the given size.

### `phbm` [out]

Type: **HBITMAP***

Pointer to a value that, when this method returns successfully, receives the handle of the retrieved bitmap. It is the responsibility of the caller to free this retrieved resource through [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) when it is no longer needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Icon extraction can be time consuming. This method generally should not be called from a UI thread to avoid causing that thread to become unresponsive. You can call **IShellItemImageFactory::GetImage** on a UI thread if you set the **SIIGBF_INCACHEONLY** flag. However, if the image is not found in the cache, the calling application should be prepared to launch a background thread to extract the image. An extraction should never be done on a UI thread.

See the [Using Image Factory](https://learn.microsoft.com/windows/win32/shell/samples-usingimagefactory) sample for a full example of how to use this method.