# IOleDocumentSite::ActivateMe

## Description

Asks a document site to activate the document making the call as a document object rather than an in-place-active object and, optionally, specifies which view of the object document to activate.

## Parameters

### `pViewToActivate` [in]

A pointer to an [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) interface pointer that represents the document view to be used in activating the document object. This parameter can be **NULL**, in which case the container should call [IOleDocument::CreateView](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-createview) to obtain a document view pointer.

## Return value

This method returns S_OK on success.

## Remarks

When a container calls [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) to activate a document, a document object bypasses the usual in-place activation sequence by calling **IOleDocumentSite::ActivateMe**.

When calling [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) on a document object, the most appropriate activation verb is usually OLEIVERB_SHOW. Other allowable verbs include OLEIVERB_PRIMARY and OLEIVERB_UIACTIVATE. OLEIVERB_OPEN is discouraged because it means opening an embedded object in a separate window, which is contrary to the intent of document object activation.

### Notes to Callers

Only document objects should call this method. A normal in-place active document should respond to a container's call to [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) by calling [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite).

A document object should initiate its activation by calling **IOleDocumentSite::ActivateMe**. If the container does not implement [IOleDocumentSite](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentsite), then the document should default to the normal in-place activation sequence.

A document object that supports more than one view of its data can specify which view to activate by passing a pointer to that view's [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) interface in *pViewToActivate*.

However the [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) pointer is obtained, the container should release the pointer when it is no longer needed.

### Notes to Implementers

This function must be completely implemented in a document object container; E_NOTIMPL is not an acceptable return value.

If a document object passes an [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) pointer in *pViewToActivate*, the container's implementation of **IOleDocumentSite::ActivateMe** should call [IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite) and pass a pointer to its [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) interface back to the view object. If the container is holding onto the **IOleDocumentView** pointer, which will normally be the case, it should follow the call to **IOleDocumentView::SetInPlaceSite** with a call to [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref).

If *pViewToActivate* is **NULL**, the container can obtain a pointer to a document view by querying the document for [IOleDocument](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocument), then calling [IOleDocument::CreateView](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-createview) and passing its [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) pointer.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)

[IOleDocument::CreateView](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-createview)

[IOleDocumentSite](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentsite)

[IOleDocumentView::SetInPlaceSite](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setinplacesite)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)

[IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb)