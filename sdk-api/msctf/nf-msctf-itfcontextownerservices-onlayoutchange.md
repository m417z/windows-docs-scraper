# ITfContextOwnerServices::OnLayoutChange

## Description

The **ITfContextOwnerServices::OnLayoutChange** method is called by the context owner when the on-screen representation of the text stream is updated during a composition. Text stream updates include when the position of the window that contains the text is changed or if the screen coordinates of the text change.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

A call to **ITfContextOwnerServices::OnLayoutChange** could be in response to a text edit, font size change, window movement/resizing, and so on.

If a call to [ITfContextView::GetTextExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-gettextext) or [ITfContextOwner::GetACPFromPoint](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getacpfrompoint) fails because the application did not calculate the screen layout (Return Value: TS_E_NOLAYOUT), the application must then call **ITfContextOwnerServices::OnLayoutChange** when the information is ready.

## See also

[ITfContextOwner::GetACPFromPoint](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getacpfrompoint)

[ITfContextOwnerServices](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextownerservices)

[ITfContextView::GetTextExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-gettextext)