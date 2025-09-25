# ITextStoreAnchorSink::OnTextChange

## Description

Called when text in the text stream changes.

## Parameters

### `dwFlags` [in]

Contains a set of flags that specify additional information about the text change. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The text has changed. |
| **TS_TC_CORRECTION** | The text is a transform (correction) of existing content, and any special text markup information (metadata) is retained, such as .wav file data or a language identifier. This flag is used for applications that need to preserve data associated with the original text. |

### `paStart` [in]

Pointer to an anchor located at the start of the changed text.

### `paEnd` [in]

Pointer to an anchor located at the end of the changed text.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to create cloned anchors to contain the change. |
| **E_INVALIDARG** | *paStart* or *paEnd* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **TS_E_NOLOCK** | The TSF manager holds a lock on the document. This typically indicates that the method was called from within another [ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor) method, such as [ITextStoreAnchor::SetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-settext). |

## Remarks

This method is called only when the application modifies its own text, not when a client modifies text with one of the **ITextStoreAnchor** methods, such as **ITextStoreAnchor::SetText** or [ITextStoreAnchor::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-inserttextatselection).

When calling this method, the application must be able to grant a [document lock](https://learn.microsoft.com/windows/desktop/TSF/document-locks).

## See also

[Document Locks](https://learn.microsoft.com/windows/desktop/TSF/document-locks)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-inserttextatselection)

[ITextStoreAnchor::SetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-settext)

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)

[Miscellaneous Text Store Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-text-store-constants)