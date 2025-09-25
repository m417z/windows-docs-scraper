# IOleDocumentView::ApplyViewState

## Description

Initializes a view with view state previously saved in call to [IOleDocumentView::SaveViewState](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-saveviewstate).

## Parameters

### `pstm` [in]

A pointer to a stream containing data from which the view should initialize itself.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The value in *pstm* is **NULL**. |
| **E_NOTIMPL** | This view has no meaningful state to load. This error should be rare because most views will have at least some state information worth loading. |

## Remarks

Typically, this function is called after an existing view has been created in the container but before that view has been displayed. It is the responsibility of the view to validate the data in the view stream; the container does not attempt to interpret the view's state data.

## See also

[IOleDocument::CreateView](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-createview)

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)

[IOleDocumentView::SaveViewState](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-saveviewstate)