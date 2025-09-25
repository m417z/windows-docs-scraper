# ITextStoreACP2::InsertTextAtSelection

## Description

Inserts text at the insertion point or selection. A caller must have a read/write lock on the document before inserting text.

## Parameters

### `dwFlags` [in]

### `pchText` [in]

### `cch` [in]

### `pacpStart` [out]

### `pacpEnd` [out]

### `pChange` [out]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The values of the *pacpStart* and the *pacpEnd* parameters depend upon how the client application inserts text into a document. For example, if the application sets the cursor at the start of the inserted text after text insertion, then the value for the *pacpStart* and *pacpEnd* parameters is the same as the **acpStart** member of the [TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange) structure.

Applications should not call the [OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-ontextchange) method in response to this method.

## See also

[Compositions](https://learn.microsoft.com/windows/desktop/TSF/compositions)

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-ontextchange)

[TF_IAS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants)

[TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange)