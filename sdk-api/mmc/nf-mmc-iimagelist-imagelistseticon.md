# IImageList::ImageListSetIcon

## Description

The **IImageList::ImageListSetIcon** method enables a user to set an icon in the image list or to create an icon if it is not there.

## Parameters

### `pIcon` [in]

A value that specifies the Win32
HICON handle to the icon to set. The type must be cast as a pointer to a LONG_PTR. The snap-in owns this resource and must free it when finished. A resource memory leak will occur if the snap-in does not free Icon.

### `nLoc` [in]

A value that specifies the index assigned to the entry. This is a virtual index that is internally mapped to the actual index.

## Return value

This method can return one of these values.

## Remarks

If the index specified by *nLoc* has been used before,
**ImageListSetIcon** replaces the icon stored at *nLoc*. If it has not been previously used, a new entry in the image list is added. The icon being inserted must have both the 32x32 and 16x16 pixel sizes defined.

### Selectively Changing the Small or Large Icon in an Image List

In MMC 1.2, two new macros are introduced to support changing only the small or large icon in an image list. The two macros, ILSI_LARGE_ICON and ILSI_SMALL_ICON, are applied to the *nLoc* parameter of
**ImageListSetIcon**.

The ILSI_LARGE_ICON macro is used to change only the large icon at nLoc. The ILSI_SMALL_ICON macro is used to change only the small icon at nLoc.

To set different large and small icons, you can use either one of the two macros. The following code examples show these macros.

### Snippet 1

```cpp
pImageList->ImageListSetIcon((LONG_PTR*) hLargeIcon, nLoc); // set both
pImageList->ImageListSetIcon((LONG_PTR*) hSmallIcon, ILSI_SMALL_ICON (nLoc)); // change small
```

### Snippet 2

```cpp
pImageList->ImageListSetIcon((LONG_PTR*) hSmallIcon, nLoc); // set both
pImageList->ImageListSetIcon((LONG_PTR*) hLargeIcon, ILSI_LARGE_ICON (nLoc)); // change large
```

Before using either ILSI_LARGE_ICON or ILSI_SMALL_ICON, the snap-in must first insert an image at nLoc. The
ImageListSetIcon method will fail if the ILSI_LARGE_ICON or ILSI_SMALL_ICON macro is used and nLoc does not refer to an existing image.

## See also

[IImageList](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iimagelist)