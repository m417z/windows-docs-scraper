# IOleDocumentView::Clone

## Description

Creates a duplicate view object with an internal state identical to that of the current view.

## Parameters

### `pIPSiteNew` [in]

A pointer to a [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) interface that represents the view site in which the new view object will be activated. On receiving this pointer, the view being cloned should pass it to the new view's [IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite) method. This pointer can be **NULL**, in which case the caller is responsible for calling **IOleDocumentView::SetInPlaceSite** on the new view directly.

### `ppViewNew` [out]

A pointer to an [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) pointer variable that receives the interface pointer to the new view object. The caller is responsible for releasing *ppViewNew* when it is no longer needed.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_POINTER** | The value in *ppViewNew* is **NULL**. |
| **E_NOTIMPL** | The view object does not implement this interface. |

## Remarks

This method is useful for creating a new view with a different viewport and view site but with the same view context as the view being cloned. Typically, containers hosting an MDI application will call this method to provide "Window/New window" capability.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)