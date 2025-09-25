# IImageList::GetBkColor

## Description

Gets the current background color for an image list.

## Parameters

### `pclr` [out]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) that contains the background color when the method returns.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::GetBkColor**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).