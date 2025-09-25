# IOleDocumentView::Open

## Description

Displays a document view in a separate pop-up window. The semantics are equivalent to [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) with OLEIVERB_OPEN.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_OUTOFMEMORY** | Insufficient memory available for the operation. |
| **E_UNEXPECTED** | An unexpected error occurred. |
| **E_NOTIMPL** | The document object that owns this view does not support separate window activation. |

## Remarks

A user viewing a document object in a container application such as a browser or "binder" may want to see two or more views or documents at once. Because the browser displays only one view at a time, the container needs a way to ask the other views or documents to display themselves, as required, in separate windows. The **IOleDocumentView::Open** method provides that way.

### Notes to Callers

A successful call to **IOleDocumentView::Open** should be followed by a call to [IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show) to hide the window or to show the window and bring it to the foreground. While the view is active in its separate window, a container can show or hide the window as many times as it may require.

### Notes to Implementers

A document object indicates that it does not support activation in a separate window by setting the [DOCMISC](https://learn.microsoft.com/windows/win32/api/docobj/ne-docobj-docmisc)_CANTOPENEDIT status flag and returning E_NOTIMPL to containers that call this method.

Implementation consists mainly of the view object calling its own [IOleInPlaceObject::InPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate) method, which leaves the document object in a running state but without in-place activation. The document object's user interface is not visible until the container calls [IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show) (see Notes to Callers above).

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::CloseView](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-closeview)

[IOleDocumentView::Show](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-show)

[IOleDocumentView::UIActivate](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-uiactivate)

[IOleInPlaceObject::InPlaceDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate)

[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)

[IOleInPlaceSite::OnInPlaceActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-oninplaceactivate)