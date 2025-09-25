# IOleDocumentView::GetInPlaceSite

## Description

Retrieves the view site associated with this view object.

## Parameters

### `ppIPSite` [out]

A pointer to an [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) pointer variable that receives the interface pointer to the document's view site.

## Return value

This method returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |

## Remarks

**IOleDocumentView::GetInPlaceSite** obtains the most recent [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) pointer passed by [IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite), or **NULL** if **IOleDocumentView::SetInPlaceSite** has not yet been called. If this pointer is not **NULL**, this method will call [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer. The caller is responsible for releasing it. A document view must implement this method completely; E_NOTIMPL is not an acceptable return value.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)