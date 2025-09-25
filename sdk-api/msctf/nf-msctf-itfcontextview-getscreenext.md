# ITfContextView::GetScreenExt

## Description

The **ITfContextView::GetScreenExt** method returns the bounding box, in screen coordinates, of the document display.

## Parameters

### `prc` [out]

Receives the bounding box, in screen coordinates, of the display surface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The *prc* parameter is cleared to {0,0,0,0} if the document is not currently displayed.

## See also

[ITextStoreACP::GetScreenExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getscreenext)

[ITfContextOwner::GetScreenExt](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-getscreenext)

[ITfContextView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextview)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)