# IImageList::SetBkColor

## Description

Sets the background color for an image list. This method only functions if you add an icon to the image list or use the [IImageList::AddMasked](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-addmasked) method to add a black and white bitmap. Without a mask, the entire image draws, and the background color is not visible.

## Parameters

### `clrBk` [in]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The background color to set. If this parameter is set to CLR_NONE, then images draw transparently using the [mask](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-addmasked).

### `pclr` [out]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a **COLORREF** that contains the previous background color on return if successful, or CLR_NONE otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::SetBkColor**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).