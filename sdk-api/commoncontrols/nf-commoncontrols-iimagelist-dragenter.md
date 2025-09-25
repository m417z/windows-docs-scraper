# IImageList::DragEnter

## Description

Locks updates to the specified window during a drag operation and displays the drag image at the specified position within the window.

## Parameters

### `hwndLock` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that owns the drag image.

### `x` [in]

Type: **int**

The x-coordinate at which to display the drag image. The coordinate is relative to the upper-left corner of the window, not the client area.

### `y` [in]

Type: **int**

The y-coordinate at which to display the drag image. The coordinate is relative to the upper-left corner of the window, not the client area.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To begin a drag operation, use [IImageList::BeginDrag](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-begindrag).

To use **IImageList::DragEnter**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).