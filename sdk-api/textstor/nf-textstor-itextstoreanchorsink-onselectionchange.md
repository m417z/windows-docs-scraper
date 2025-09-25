# ITextStoreAnchorSink::OnSelectionChange

## Description

The **ITextStoreAnchorSink::OnSelectionChange** method is called when the selection within the text stream changes. This method should be called whenever the return value of a potential call to [ITextStoreAnchor::GetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getselection) has changed.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_NOLOCK** | The manager holds a lock on the document. |

## Remarks

This method only needs to be called when the application modifies the selection itself, not when a client modifies the selection with [ITextStoreAnchor::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-setselection), [ITextStoreAnchor::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-inserttextatselection), or other [ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor) methods.

When calling this method, the application must be able to grant a [document lock](https://learn.microsoft.com/windows/desktop/TSF/document-locks).

Applications should expect reentrant client calls to [ITextStoreAnchor::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestlock) from within this method. An application can grant the lock request synchronously, or, because several changes have been cached, it can grant the lock asynchronously.

## See also

[Document Locks](https://learn.microsoft.com/windows/desktop/TSF/document-locks)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-inserttextatselection)

[ITextStoreAnchor::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-setselection)

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)