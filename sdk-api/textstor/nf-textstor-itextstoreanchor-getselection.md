# ITextStoreAnchor::GetSelection

## Description

The **ITextStoreAnchor::GetSelection** method returns the offset of a text selection in a text stream. This method supports multiple text selections. The caller must have a read-only lock on the document before calling this method.

## Parameters

### `ulIndex` [in]

Specifies the text selections that start the process. If the [TF_DEFAULT_SELECTION](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants) constant is specified for this parameter, the input selection starts the process, and only a single selection (the one appropriate for input operations) will be returned.

### `ulCount` [in]

Specifies the maximum number of selections to return.

### `pSelection` [out]

Receives the style, start, and end character positions of the selected text. These values are put into the [TS_SELECTION_ANCHOR](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_anchor) structure.

### `pcFetched` [out]

Receives the number of *pSelection* structures returned.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to load the start or end anchor into the **TS_SELECTION_ANCHOR** structure. |
| **E_OUTOFMEMORY** | The method was unable to allocate memory for the selection. |
| **TS_E_NOLOCK** | The caller does not have a read-only lock on the document. |
| **TS_E_NOSELECTION** | The document has no selection. |

## See also

[Edit Contexts](https://learn.microsoft.com/windows/desktop/TSF/edit-contexts)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-setselection)

[Miscellaneous Framework Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants)

TF_DEFAULT_SELECTION

[TS_SELECTION_ANCHOR](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_anchor)