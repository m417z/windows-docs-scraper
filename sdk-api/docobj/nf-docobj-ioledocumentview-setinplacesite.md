# IOleDocumentView::SetInPlaceSite

## Description

Associates a container's document view site with a document's view object.

## Parameters

### `pIPSite` [in]

A pointer to the document view site's [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) interface. This parameter can be **NULL**, in which case the document view object loses all asociation with the container.

## Return value

This method returns S_OK if a document view site was successfully associated (or disassociated if *pIPSite* is **NULL**) with a document view object. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |

## Remarks

As part of activating a document object, a container must pass the object a pointer to the container's implementation of [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite). This pointer designates the document view site that is to be associated with the view on which this method is called.

A container normally passes this pointer in response to a document's request to be activated. A document makes such a request by calling [IOleDocumentSite::ActivateMe](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentsite-activateme) and passing the container a pointer to the view to be activated. The container, in turn, uses this pointer to call **IOleDocumentView::SetInPlaceSite**.

### Notes to Callers

If the container is requesting creation and activation of a new instance of a document object, rather than merely the activation of a loaded instance of a document object, the view site is passed in the *pIPSite* argument of [IOleDocument::CreateView](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-createview). Therefore, an explicit call to **IOleDocumentView::SetInPlaceSite** is unnecessary.

### Notes to Implementers

If this method is called on a view that is already associated with a view site, the view must do some housekeeping in preparation for activating itself in the new site. First, the view must deactivate itself in the current site and release its pointer to that site. Next, if the new [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) pointer is not **NULL**, the view should both save the pointer and call [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on it. The view should then wait for the container to tell it when to activate itself in the new view site.

A document view must implement this method completely; E_NOTIMPL is not an acceptable return value.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)