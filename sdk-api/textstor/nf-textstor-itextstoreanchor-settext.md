# ITextStoreAnchor::SetText

## Description

The **ITextStoreAnchor::SetText** method sets the text selection between two supplied anchor locations.

## Parameters

### `dwFlags` [in]

If set to the value of TS_ST_CORRECTION, the text is a transform (correction) of existing content, and any special text markup information (metadata) is retained, such as .wav file data or a language identifier. The client defines the type of markup information to be retained.

### `paStart` [in]

Pointer to the anchor at the start of the range of text to replace.

### `paEnd` [in]

Pointer to the anchor at the end of the range of text to replace. Must always follow or be at the same position as *paStart*.

### `pchText` [in]

Pointer to the replacement text. The text string does not have to be **NULL** terminated, because the text character count is specified in the *cch* parameter.

### `cch` [in]

Specifies the number of characters in the replacement text.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method could not instantiate one of the anchors *paStart* or *paEnd*. |
| **TS_E_INVALIDPOS** | The location of *paStart* or *paEnd* is outside of the document text. |
| **TS_E_NOLOCK** | The caller does not have a read/write lock. |
| **TS_E_READONLY** | The document is read-only. Content cannot be modified. |
| **TS_E_REGION** | An attempt was made to modify text across a region boundary. |

## Remarks

Applications should start a composition by first using [ITextStoreAnchor::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-inserttextatselection). **ITextStoreAnchor::SetText** should be used only within an existing composition. If there is no active composition at the time **SetText** is called, the TSF manager creates a composition that lasts just long enough to wrap the call to **SetText**.

Callers must hold a write lock obtained through [ITextStoreAnchor::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestlock). Otherwise, **ITextStoreAnchor::SetText** will fail with TS_E_NOLOCK.

If *paStart* is at the same location as *paEnd*, then the operation is an insertion, and no existing text will be removed.

TS_CHAR_EMBEDDED cannot be passed into this method. For [embedded objects](https://learn.microsoft.com/windows/desktop/TSF/embedded-objects), use [ITextStoreAnchor::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-insertembedded) instead.

This method will fail if the range of text replaced covers any region boundary. Instead, callers should make multiple calls to the method, one for each region.

## See also

[Compositions](https://learn.microsoft.com/windows/desktop/TSF/compositions)

[Embedded Objects](https://learn.microsoft.com/windows/desktop/TSF/embedded-objects)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-insertembedded)

[ITextStoreAnchor::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestlock)

[ITextStoreAnchorSink::OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-ontextchange)

[Miscellaneous Text Store Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-text-store-constants)