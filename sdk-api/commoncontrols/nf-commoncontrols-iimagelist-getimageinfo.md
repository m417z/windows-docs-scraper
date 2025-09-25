# IImageList::GetImageInfo

## Description

Gets information about an image.

## Parameters

### `i` [in]

Type: **int**

A value of type **int** that contains the index of the image.

### `pImageInfo` [out]

Type: **[IMAGEINFO](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imageinfo)***

A pointer to an [IMAGEINFO](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imageinfo) structure that receives information about the image. The information in this structure can directly manipulate the bitmaps of the image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::GetImageInfo**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).