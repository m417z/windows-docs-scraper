# IImageList::SetOverlayImage

## Description

Adds a specified image to the list of images used as overlay masks. An image list can have up to four overlay masks in Common Controls [version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and earlier, and up to 15 in version 4.71 or later. The method assigns an overlay mask index to the specified image.

## Parameters

### `iImage` [in]

Type: **int**

A value of type **int** that contains the zero-based index of an image in the image list. This index identifies the image to use as an overlay mask.

### `iOverlay` [in]

Type: **int**

A value of type **int** that contains the one-based index of the overlay mask.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An overlay mask is an image drawn transparently over another image. To draw an overlay mask over an image, call [IImageList::Draw](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-draw). The **fStyle** parameter of these functions can use the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro to specify an overlay mask index.

A call to this method fails and returns E_INVALIDARG unless the image list is created using a mask.

To use **IImageList::SetOverlayImage**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).