# IOleDocumentView::GetRect

## Description

Retrieves the rectangular coordinates of the viewport in which the view is or will be activated.

## Parameters

### `prcView` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to contain the coordinates of the current viewport set with [IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect).

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | This view has not yet seen a call to [IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect) or [IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex) and therefore has no rectangle to return. |

## Remarks

For a single document interface (SDI) application, the viewport is the client area of the frame window minus the space allocated for toolbars, status bar, and such. For a multiple document interface (MDI) window, the viewport is the client area of the MDI document window minus any other frame-level user-interface elements.

The viewport coordinates obtained by this method are those set in the most recent call to either [IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect) or [IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex).

A document view must implement this method completely; E_NOTIMPL is not an acceptable return value.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect)

[IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex)