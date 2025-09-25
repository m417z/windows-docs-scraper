# ITextStoreACPSink::OnTextChange

## Description

Called when the text of a document changes.

## Parameters

### `dwFlags` [in]

Contains a set of flags that specify additional information about the text change. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The text has changed. |
| **TS_ST_CORRECTION** | The text is a transform (correction) of existing content, and any special text markup information (metadata) is retained, such as .wav file data or a language identifier. This flag is used for applications that need to preserve data associated with the original text. |

### `pChange` [in]

Pointer to a [TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange) structure that contains text change data.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pChange* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **TS_E_NOLOCK** | The TSF manager holds a lock on the document. This typically indicates that the method was called from within another [ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp) method, such as [ITextStoreACP::SetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-settext). |

## Remarks

**ITextStoreACPSink::OnTextChange** is never called when the text is modified by one of the **ITextStoreACP** interface methods, such as **ITextStoreACP::SetText** or [ITextStoreACP::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-inserttextatselection).

When calling this method, the application must be able to grant a [document lock](https://learn.microsoft.com/windows/desktop/TSF/document-locks).

## See also

[Document Locks](https://learn.microsoft.com/windows/desktop/TSF/document-locks)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-inserttextatselection)

[ITextStoreACP::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-requestlock)

[ITextStoreACP::SetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-settext)

[ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink)

[Miscellaneous Text Store Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-text-store-constants)

[TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange)