# IImageList::Draw

## Description

Draws an image list item in the specified device context.

## Parameters

### `pimldp` [in]

Type: **[IMAGELISTDRAWPARAMS](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imagelistdrawparams)***

A pointer to an [IMAGELISTDRAWPARAMS](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imagelistdrawparams) structure that contains the drawing parameters.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Overlay images draw transparently over the primary image specified in the **i** parameter of [IMAGELISTDRAWPARAMS](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imagelistdrawparams). You specify an overlay image in the **fStyle**, parameter of **IMAGELISTDRAWPARAMS** using the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro to shift the one-based index of the overlay image. Use the OR operator to combine the macro's return value with the drawing style flags specified in **fStyle**. You must first specify this image as an overlay image by using [IImageList::SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-setoverlayimage).

To use **IImageList::Draw**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).