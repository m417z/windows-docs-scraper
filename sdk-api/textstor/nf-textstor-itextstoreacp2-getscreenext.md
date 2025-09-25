# ITextStoreACP2::GetScreenExt

## Description

Gets the bounding box screen coordinates of the display surface where the text stream is rendered.

## Parameters

### `vcView` [in]

Specifies the context view.

### `prc` [out]

Receives the bounding box screen coordinates of the display surface of the document.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The specified *vcView* parameter is invalid. |

## Remarks

If the text is not currently displayed, for example, if the document window is minimized, the *prc* parameter is set to { 0, 0, 0, 0 }.

## See also

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[ITfContextOwner::GetScreenExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-getscreenext)

[ITfContextView::GetScreenExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextview-getscreenext)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)