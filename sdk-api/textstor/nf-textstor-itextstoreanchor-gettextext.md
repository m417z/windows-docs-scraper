# ITextStoreAnchor::GetTextExt

## Description

The **ITextStoreAnchor::GetTextExt** method returns the bounding box, in screen coordinates, of a range of text. The caller must have a read-only lock on the document before calling this method.

## Parameters

### `vcView` [in]

Specifies the context view.

### `paStart` [in]

Specifies the anchor positioned at the start of the range.

### `paEnd` [in]

Specifies the anchor positioned at the end of the range.

### `prc` [out]

Receives the bounding box of the text range in screen coordinates.

### `pfClipped` [out]

Receives a Boolean value that specifies if the text in the bounding box has been clipped. If **TRUE**, the bounding box contains clipped text and does not include the entire requested text range. The bounding box is clipped because the requested range is not visible.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to obtain a valid interface pointer to the start and/or end anchors. |
| **TS_E_INVALIDARG** | One or more of the input parameters is invalid. |
| **TS_E_INVALIDPOS** | The range specified by the *paStart* and *paEnd* parameters extends past the beginning or end of the document. |
| **TS_E_NOLAYOUT** | The application has not calculated a text layout. Any further calls will not succeed until the application calls [ITextStoreAnchorSink::OnLayoutChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onlayoutchange). |
| **TS_E_NOLOCK** | The caller does not have a read-only lock on the document. |

## Remarks

If the document window is minimized, or if the specified text is not currently visible, the method returns S_OK with the *prc* parameter set to {0,0,0,0}.

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITfContextOwner::GetTextExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-gettextext)

[ITfContextView::GetTextExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextview-gettextext)