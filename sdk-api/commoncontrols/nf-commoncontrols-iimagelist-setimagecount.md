# IImageList::SetImageCount

## Description

Resizes an existing image list.

## Parameters

### `uNewCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies the new size of the image list.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If an application expands an image list using this method, it must add new images by using [IImageList::Replace](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-replace). If the application does not add valid images to the new indexes, draw operations that use the new indexes are unpredictable.

If you decrease the size of an image list using this method, images at the end of the list for which there is no longer room are truncated from the list. Images truncated in this manner are automatically deallocated.

To use **IImageList::SetImageCount**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).