# IImageList::DragShowNolock

## Description

Shows or hides the image being dragged.

## Parameters

### `fShow` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies whether to show or hide the image being dragged. Specify **TRUE** to show the image or **FALSE** to hide the image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use **IImageList::DragShowNolock**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).