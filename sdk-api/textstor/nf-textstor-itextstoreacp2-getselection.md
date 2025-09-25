# ITextStoreACP2::GetSelection

## Description

Gets the character position of a text selection in a document. This method supports multiple text selections. The caller must have a read-only lock on the document before calling this method.

## Parameters

### `ulIndex` [in]

Specifies the text selections that start the process. If the [TF_DEFAULT_SELECTION](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants) constant is specified for this parameter, the input selection starts the process.

### `ulCount` [in]

Specifies the maximum number of selections to return.

### `pSelection` [out]

Receives the style, start, and end character positions of the selected text. These values are put into the [TS_SELECTION_ACP](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_acp) structure.

### `pcFetched` [out]

Receives the number of *pSelection* structures returned.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_NOLOCK** | The caller does not have a read-only lock on the document. |
| **TS_E_NOSELECTION** | The document has no selection. |

## See also

[Edit Contexts](https://learn.microsoft.com/windows/desktop/TSF/edit-contexts)

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[ITextStoreACP::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-setselection)

[Miscellaneous Framework Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants)

[TS_SELECTION_ACP](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_acp)