# ITextStoreACPSink::OnLayoutChange

## Description

Called when the layout (on-screen representation) of the document changes.

## Parameters

### `lcode` [in]

Contains a [TsLayoutCode](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tslayoutcode) value that defines the type of change.

### `vcView` [in]

Contains an application-defined cookie that identifies the document. For more information, see [ITextStoreACP::GetActiveView](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getactiveview).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

A layout change can be in response to a change to the text, font size, window movement, window resizing, or other change that affects the displayed text.

If a call to [ITextStoreACP::GetTextExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-gettextext) or [ITextStoreACP::GetACPFromPoint](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getacpfrompoint) returns TS_E_NOLAYOUT because the application has not calculated the layout, the application must call **ITextStoreACPSink::OnLayoutChange** when the layout is available.

## See also

[ITextStoreACP::GetACPFromPoint](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getacpfrompoint)

[ITextStoreACP::GetActiveView](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getactiveview)

[ITextStoreACP::GetTextExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-gettextext)

[ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink)

[TsLayoutCode](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tslayoutcode)