# ImageList_SetOverlayImage function

## Description

Adds a specified image to the list of images to be used as overlay masks. An image list can have up to four overlay masks in version 4.70 and earlier and up to 15 in version 4.71. The function assigns an overlay mask index to the specified image.

## Parameters

### `himl` [in]

Type: **HIMAGELIST**

A handle to the image list.

### `iImage` [in]

Type: **int**

The zero-based index of an image in the *himl* image list. This index identifies the image to use as an overlay mask.

### `iOverlay` [in]

Type: **int**

The one-based index of the overlay mask.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

An overlay mask is an image drawn transparently over another image. To draw an overlay mask over an image, call the [ImageList_Draw](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_draw) or [ImageList_DrawEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_drawex) function. The *fStyle* parameter of these functions can use the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro to specify an overlay mask index.

A call to this method fails and returns E_INVALIDARG unless the image list is created using a mask.