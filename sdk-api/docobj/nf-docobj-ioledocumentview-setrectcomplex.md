# IOleDocumentView::SetRectComplex

## Description

Sets the rectangular coordinates of the viewport, scroll bars, and size box.

## Parameters

### `prcView` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the viewport.

### `prcHScroll` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the horizontal scroll bar.

### `prcVScroll` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the vertical scroll bar.

### `prcSizeBox` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the size box.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The document object that owns this view does not support complex rectangles. |

## Remarks

View frames that support a workbook metaphor, in which a single document comprises multiple sheets or pages, typically call this method to set the coordinates to be used in common by all the sheets or pages.

### Notes to Callers

Calling **IOleDocumentView::SetRectComplex** is part of the normal activation sequence for document objects that support complex rectangles, usually following a call to [IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate) and preceding a call to [IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show).

Whenever the window used to display a document object is resized, the container should call **IOleDocumentView::SetRectComplex** or [IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect) to tell the view object to resize itself to the new window dimensions.

### Notes to Implementers

Document objects that support complex rectangles mark themselves with [DOCMISC](https://learn.microsoft.com/windows/win32/api/docobj/ne-docobj-docmisc)_SUPPORTCOMPLEXRECTANGLES, as described in **DOCMISC** and [IOleDocument::GetDocMiscStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-getdocmiscstatus). Document objects that do not support this method can return E_NOTIMPL.

Upon receiving a call to this method, a view should resize itself to fit the coordinates specified in prcView and fit its scrollbars and size box to the areas described in *prcHScroll*, *prcVScroll*, and *prcSizeBox*.

This method is defined with the [input_sync] attribute, which means that the implementing object cannot yield or make another, non input_sync RPC call while executing this method.

## See also

[IOleDocument::GetDocMiscStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-getdocmiscstatus)

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)