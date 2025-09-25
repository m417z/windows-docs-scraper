# ITfContextView::GetTextExt

## Description

The **ITfContextView::GetTextExt** method returns the bounding box, in screen coordinates, of a range of text.

## Parameters

### `ec` [in]

Specifies an edit cookie with read-only access.

### `pRange` [in]

Specifies the range to query

### `prc` [out]

Receives the bounding box, in screen coordinates, of the range.

### `pfClipped` [out]

Receives the Boolean value that specifies if the text in the bounding box has been clipped. If this parameter is **TRUE**, the bounding box contains clipped text and does not include the entire requested range. The bounding box is clipped because of the requested range is not visible.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_NOLAYOUT** | The text is not rendered or the context has not calculated the text layout. |
| **TF_E_NOLOCK** | The edit cookie parameter is invalid. |

## Remarks

If the document window is minimized, or if the specified text is not currently visible, the method returns S_OK with the *prc* parameter set to {0,0,0,0}.

## See also

[ITfContextOwner::GetTextExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-gettextext)

[ITfContextView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextview)