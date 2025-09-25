# IOleDocumentView::CloseView

## Description

Instructs a document view to close itself and release its [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) pointer.

## Parameters

### `dwReserved` [in]

This parameter is reserved and cannot be **NULL**.

## Return value

This method returns S_OK on success.

## Remarks

When a separate window is no longer needed, the container calls **IOleDocumentView::CloseView**, whereupon the view releases its site pointer to the separate window and destroys the window. Unlike the normal in-place deactivation sequence for active documents, a document view continues to hold the [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) pointer. This pointer is released only when the view's container calls [SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite), with *pIPSite* set to **NULL**, or calls **IOleDocumentView::CloseView**.

When a user closes a view's separate window, the view should not shut itself down. Instead, it should call [IOleInPlaceSite::OnInPlaceActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplaceactivate). The view site then decides whether to call [IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate) with **FALSE** immediately or later. In this way, a document view displayed in a separate window remains available for activation in the container's own window.

The container must call this method before it deletes the view, that is, releases its last reference to the view. In general, implementation of this method will call [IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show) with **FALSE** to hide the view if it is not already hidden, then call [SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite) with **NULL** to deactivate itself and release the view site pointer.

Because **IOleDocumentView::CloseView** is called when a container is going to completely shut down a view, this method must be implemented and has no reason to fail.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)

[IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show)