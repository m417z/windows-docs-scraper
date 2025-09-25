# ITextStoreACP::GetTextExt

## Description

The **ITextStoreACP::GetTextExt** method returns the bounding box, in screen coordinates, of the text at a specified character position. The caller must have a read-only lock on the document before calling this method.

## Parameters

### `vcView` [in]

Specifies the context view.

### `acpStart` [in]

Specifies the starting character position of the text to get in the document.

### `acpEnd` [in]

Specifies the ending character position of the text to get in the document.

### `prc` [out]

Receives the bounding box in screen coordinates of the text at the specified character positions.

### `pfClipped` [out]

Receives a Boolean value that specifies if the text in the bounding box has been clipped. If this parameter is **TRUE**, the bounding box contains clipped text and does not include the entire requested text range. The bounding box is clipped because the requested range is not visible.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_INVALIDARG** | The specified start and end character positions are equal. |
| **TS_E_INVALIDPOS** | The range specified by the *acpStart* and *acpEnd* parameters extends past the beginning or end of the document. |
| **TS_E_NOLAYOUT** | The application has not calculated a text layout. |
| **TS_E_NOLOCK** | The caller does not have a read-only lock on the document. |

## Remarks

If the document window is minimized, or if the specified text is not currently visible, the method returns S_OK with the *prc* parameter set to {0,0,0,0}.

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITfContextOwner::GetTextExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-gettextext)

[ITfContextView::GetTextExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextview-gettextext)