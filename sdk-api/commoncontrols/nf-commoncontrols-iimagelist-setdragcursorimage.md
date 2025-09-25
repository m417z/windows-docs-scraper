# IImageList::SetDragCursorImage

## Description

Creates a new drag image by combining the specified image, which is typically a mouse cursor image, with the current drag image.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface that accesses the image list interface, which contains the new image to combine with the drag image.

### `iDrag` [in]

Type: **int**

A value of type **int** that contains the index of the new image to combine with the drag image.

### `dxHotspot` [in]

Type: **int**

A value of type **int** that contains the x-component of the hot spot within the new image.

### `dyHotspot` [in]

Type: **int**

A value of type **int** that contains the x-component of the hot spot within the new image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::SetDragCursorImage**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).