# ITextStoreACP2::SetText

## Description

Sets the text selection to the supplied character positions.

## Parameters

### `dwFlags` [in]

If set to the value of **TS_ST_CORRECTION**, the text is a transform (correction) of existing content, and any special text markup information (metadata) is retained, such as .wav file data or a language identifier. The client defines the type of markup information to be retained.

### `acpStart` [in]

Specifies the starting character position of the text to replace.

### `acpEnd` [in]

Specifies the ending character position of the text to replace. This parameter is ignored if the value is 1.

### `pchText` [in]

Specifies the pointer to the replacement text. The text string does not have to be **NULL** terminated, because the text character count is specified in the *cch* parameter.

### `cch` [in]

Specifies the number of characters in the replacement text.

### `pChange` [out]

Pointer to a [TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange) structure with the following data.

| Value | Meaning |
| --- | --- |
| **acpStart** | The starting application character position before the text is inserted into the document. |
| **acpOldEnd** | The ending position before the text is inserted into the document. This value is the same as *acpStart* for an insertion point. If this value is different from *acpStart*, then text was selected prior to the text insertion. |
| **acpNewEnd** | The ending position after the text insertion occurred. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_INVALIDPOS** | The *acpStart* or *acpEnd* parameter is outside of the document text. |
| **TS_E_NOLOCK** | The caller does not have a read/write lock. |
| **TS_E_READONLY** | The document is read-only. Content cannot be modified. |
| **TS_E_REGION** | An attempt was made to modify text across a region boundary. |

## Remarks

Applications should start a composition by first using [InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-inserttextatselection). **SetText** should be used only within an existing composition. If there is no active composition at the time **SetText** is called, the TSF manager creates a composition that lasts just long enough to wrap the call to **SetText**.

The *acpStart* and *acpEnd* character positions cannot be outside the document range.

Applications should not call the [OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-ontextchange) method in response to this method.

This method should call the [SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-setselection) method to select the text to be changed. After successfully executing the **SetSelection** method, this method then calls the [InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-inserttextatselection) method to perform the actual text change.

## See also

[Compositions](https://learn.microsoft.com/windows/desktop/TSF/compositions)

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[Miscellaneous Text Store Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-text-store-constants)

[OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-ontextchange)

[TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange)