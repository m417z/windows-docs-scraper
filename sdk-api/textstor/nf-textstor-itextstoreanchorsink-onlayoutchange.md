# ITextStoreAnchorSink::OnLayoutChange

## Description

The **ITextStoreAnchorSink::OnLayoutChange** method is called when the layout (on-screen representation) of the document changes.

## Parameters

### `lcode` [in]

Contains a [TsLayoutCode](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tslayoutcode) value that defines the type of change.

### `vcView` [in]

Contains an application-defined cookie that identifies the document. For more information, see [ITextStoreAnchor::GetActiveView](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getactiveview).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

A layout change can be in response to a change to the text, font size, window movement, window resizing, or other change that affects the displayed text.

If a call to [ITextStoreAnchor::GetTextExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-gettextext) or [ITextStoreAnchor::GetAnchorFromPoint](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getanchorfrompoint) returns TS_E_NOLAYOUT because the application has not calculated the layout, the application must call **ITextStoreAnchorSink::OnLayoutChange** when the layout is available.

## See also

[ITextStoreAnchor::GetActiveView](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getactiveview)

[ITextStoreAnchor::GetAnchorFromPoint](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getanchorfrompoint)

[ITextStoreAnchor::GetTextExt](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-gettextext)

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)

[TsLayoutCode](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tslayoutcode)