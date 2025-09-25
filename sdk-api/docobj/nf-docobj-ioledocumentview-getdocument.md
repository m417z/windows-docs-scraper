# IOleDocumentView::GetDocument

## Description

Obtains the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer on the document object that owns this view.

## Parameters

### `ppunk` [out]

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer that receives a pointer to the document object that owns this view.

## Return value

This method returns S_OK on success. S_OK is the only valid return value for this method.

## Remarks

The caller is responsible for incrementing the reference count on the interface pointer obtained by this method. The caller must call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on this pointer when it is no longer needed.

Because a view object must always be contained or aggregated in a document object, this method will always succeed. Before returning, this method should call [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer stored in *ppunk*.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)