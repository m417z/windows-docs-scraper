# ITfContextOwner::GetScreenExt

## Description

The **ITfContextOwner::GetScreenExt** method returns the bounding box, in screen coordinates, of the display surface where the text stream is rendered.

## Parameters

### `prc` [out]

Receives the bounding box screen coordinates of the display surface of the document.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If the text is not currently displayed, for example if the document window is minimized, *prc* is set to { 0, 0, 0, 0 }.

## See also

[ITextStoreACP::GetScreenExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getscreenext)

[ITfContextOwner](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextowner)

[ITfContextView::GetScreenExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextview-getscreenext)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)