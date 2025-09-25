# IOleDocumentView::UIActivate

## Description

Activates or deactivates a document view's user interface elements, such as menus, toolbars, and accelerators.

## Parameters

### `fUIActivate` [in]

If **TRUE**, the view is to activate its user interface. If **FALSE**, the view is to deactivate its user interface.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_OUTOFMEMORY** | Insufficient memory available for operation. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

### Notes to Callers

Calling this method before calling [IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite) returns E_UNEXPECTED, because the view must be associated with a view site before it can activate itself.

When **IOleDocumentView::UIActivate** is called as part of the activation sequence, the call should precede a call to [IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect) or [IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex), because otherwise the view dimensions would not account for toolbar space.

To deactivate a view, the container should call [IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show) with **FALSE**, followed by **IOleDocumentView::UIActivate** with **FALSE**.

### Notes to Implementers

Implementations of this method should embody the following pseudocode.

``` syntax
if (fActivate)
    {
    UI activate the view (do menu merging, show frame level tools, process accelerators)
    Take focus, and bring the view window forward.
    }
else
    call IOleInPlaceObject::UIDeactivate on this view
```

In addition, the view can and should participate in extended **Help** menu merging.

All views of a document object must support in-place activation. E_NOTIMPL is not an acceptable return value.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)

[IOleDocumentView::SetRect](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrect)

[IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex)

[IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show)