# ITextStoreACPSink::OnSelectionChange

## Description

Called when the selection within the document changes.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_NOLOCK** | The manager holds a lock on the document. |

## Remarks

**ITextStoreACPSink::OnSelectionChange** is never called when the selection is modified by one of the [ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp) interface methods, such as [ITextStoreACP::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-setselection) or [ITextStoreACP::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-inserttextatselection).

When calling this method, the application must be able to grant a [document lock](https://learn.microsoft.com/windows/desktop/TSF/document-locks).

## See also

[Document Locks](https://learn.microsoft.com/windows/desktop/TSF/document-locks)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-inserttextatselection)

[ITextStoreACP::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-setselection)

[ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink)