# IOleDocumentView::SaveViewState

## Description

Saves the view state into the specified stream.

## Parameters

### `pstm` [in]

 A pointer to the stream in which the view is to save its state data.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The value in pstm is **NULL**. |
| **E_NOTIMPL** | This view has no meaningful state to save. This error should be rare because most views have at least some state information worth saving. |

## Remarks

The view's state includes properties such as the view type, zoom factor, and location of insertion point. The container typically calls this function before deactivating the view. The stream can then later be used to reinitialize a view of the same document to this saved state through [IOleDocumentView::ApplyViewState](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-applyviewstate).

According to the rules governing [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream), a view must write its CLSID as the first element in the stream. Any cross-platform file format compatibility issues that apply to the document's storage representation also apply to this context.

## See also

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::ApplyViewState](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-applyviewstate)

[IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream)