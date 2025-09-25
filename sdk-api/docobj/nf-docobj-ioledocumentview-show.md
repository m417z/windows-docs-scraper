# IOleDocumentView::Show

## Description

Activates or deactivates a view.

## Parameters

### `fShow` [in]

If **TRUE**, the view is to show itself. If **FALSE**, the view is to hide itself.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_OUTOFMEMORY** | Insufficient memory available for operation. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

Calling **Show** is the last step in the activation sequence, because before showing itself a document object must know exactly what space it occupies and have all its tools available.

### Notes to Callers

A call to this method for the purpose of activating a view should follow calls to [IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite), [IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate), and [IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect) (or [IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex)).

### Notes to Implementers

Implementations of this method should embody the following pseudocode.

``` syntax
if (fShow)
    {
    In-place activate the view but do not UI activate it.
    Show the view window.
    }
else
    {
    Call IOleDocumentView::UIActivate(FALSE) on this view
    Hide the view window
    }
```

All views of a document object must at least support in-place activation; E_NOTIMPL is not an acceptable value.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)

[IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect)

[IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex)

[IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate)