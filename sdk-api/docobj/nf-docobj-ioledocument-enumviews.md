# IOleDocument::EnumViews

## Description

Creates an object that enumerates the views supported by a document object, or if only one view is supported, returns a pointer to that view.

## Parameters

### `ppEnum` [out]

A pointer to an [IEnumOleDocumentViews](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ienumoledocumentviews) pointer variable that receives the interface pointer to the enumerator object.

### `ppView` [out]

A pointer to an [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) pointer variable that receives the interface pointer to a single view object.

## Return value

This method returns S_OK if the object supports multiple views, then *ppEnum* contains a pointer to the enumerator object, and *ppView* is **NULL**. Otherwise, *ppEnum* is **NULL**, and *ppView* contains an interface pointer on the single view.

Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory available for the operation. |
| **E_POINTER** | The address in *ppEnum* or *ppView* is invalid. The caller must pass valid pointers for both arguments. |

## Remarks

If a document object supports multiple views of its data, it must also implement [IEnumOleDocumentViews](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ienumoledocumentviews) and pass that interface's pointer in the out parameter *ppEnum*. Using this pointer, the container can enumerate the views supported by the document object.

If the document object supports only a single view, **IOleDocument::EnumViews** passes that view's [IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview) pointer in the out parameter *ppView*.

## See also

[IEnumOleDocumentViews](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ienumoledocumentviews)

[IOleDocument](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocument)

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)