# IImageList::BeginDrag

## Description

Begins dragging an image.

## Parameters

### `iTrack` [in]

Type: **int**

A value of type **int** that contains the index of the image to drag.

### `dxHotspot` [in]

Type: **int**

A value of type **int** that contains the x-component of the drag position relative to the upper-left corner of the image.

### `dyHotspot` [in]

Type: **int**

A value of type **int** that contains the y-component of the drag position relative to the upper-left corner of the image.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IImageList::BeginDrag** creates a temporary image list that is used for dragging. In response to subsequent [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) messages, you can move the drag image by using [IImageList::DragMove](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-dragmove). To end the drag operation, you can use [IImageList::EndDrag](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-enddrag).

To use **IImageList::BeginDrag**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).