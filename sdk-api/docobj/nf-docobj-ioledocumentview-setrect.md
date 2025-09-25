# IOleDocumentView::SetRect

## Description

Sets the rectangular coordinates of the viewport in which the view is to be activated or resets the coordinates of the viewport in which a view is currently activated.

## Parameters

### `prcView` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the viewport.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |

## Remarks

For a single document interface (SDI) application, the viewport is the client area of the frame window minus the space allocated for toolbars, status bar, and such. For a multiple document interface (MDI) window, the viewport is the client area of the MDI document window minus any other frame-level user-interface elements.

### Notes to Callers

Calling **IOleDocumentView::SetRect** or [IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex) is part of the normal activation sequence for document objects, usually following a call to [IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate) and preceding a call to [IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show).

Whenever the window used to display a document object is resized, the container should call **IOleDocumentView::SetRect** (or [IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex)) to tell the document view object to resize itself to the new window dimensions.

### Notes to Implementers

The coordinates of the viewport are within the coordinates of the view window, which is obtained through [IOleWindow::GetWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolewindow-getwindow). The view must resize itself to fit the new coordinates passed in *prcView*.

This method is defined with the [input_sync] attribute, which means that the view object cannot yield or make another, non input_sync RPC call while executing this method.

A document view must implement this method completely; E_NOTIMPL is not an acceptable return value.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)