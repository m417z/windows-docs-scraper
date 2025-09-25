# IImageList::DragMove

## Description

Moves the image that is being dragged during a drag-and-drop operation. This function is typically called in response to a [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) message.

## Parameters

### `x` [in]

Type: **int**

A value of type **int** that contains the x-coordinate where the drag image appears. The coordinate is relative to the upper-left corner of the window, not the client area.

### `y` [in]

Type: **int**

A value of type **int** that contains the y-coordinate where the drag image appears. The coordinate is relative to the upper-left corner of the window, not the client area.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To begin a drag operation, use the [IImageList::BeginDrag](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-begindrag) method.

To use **IImageList::DragMove**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).