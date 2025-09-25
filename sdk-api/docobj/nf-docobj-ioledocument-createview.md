# IOleDocument::CreateView

## Description

Creates a document view object in the caller's process and obtains a pointer to that object's [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) interface.

## Parameters

### `pIPSite` [in]

A pointer to the [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) interface that represents the view site object to be associated with the new document view object. This parameter can be **NULL**, for example, when the view is contained in a new, uninitialized document object, in which case the caller must initialize the view with a subsequent call to [IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite).

### `pstm` [in]

A pointer to a stream containing data from which the new document view object should initialize itself. If **NULL**, the document object initializes the new document view object with a default state.

### `dwReserved` [in]

This parameter is reserved and must be zero.

### `ppView` [out]

 A pointer to an [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) pointer variable that receives the interface pointer to the new document view object. When successful, the caller is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the *ppview* pointer when the view object is no longer needed.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_OUTOFMEMORY** | Insufficient memory available for the operation. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_POINTER** | The address in *ppView* is **NULL**. |

## Remarks

A document object container's document site calls **CreateView** to instruct a document object to create a new view of itself in the container's process, either from default data or using the contents of an existing stream.

Calling **CreateView** does not cause the new view to display itself. To do so requires a call to either [IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show) or [IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate).

## See also

[IOleDocument](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocument)

[IOleDocumentSite::ActivateMe](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentsite-activateme)

[IOleDocumentView::ApplyViewState](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-applyviewstate)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)

[IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show)

[IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate)