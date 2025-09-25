# ITextStoreACP2::SetSelection

## Description

Selects text within the document. The application must have a read/write lock on the document before calling this method.

## Parameters

### `ulCount` [in]

Specifies the number of text selections in *pSelection*.

### `pSelection` [in]

Specifies the style, start, and end character positions of the text selected through the [TS_SELECTION_ACP](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_acp) structure.

When the start and end character positions are equal, the method places a caret at that character position. There can be only one caret at a time in the document.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **TF_E_INVALIDPOS** | The character positions specified are beyond the text in the document. |
| **TF_E_NOLOCK** | The caller does not have a read/write lock. |

## See also

[GetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-getselection)

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[TS_SELECTION_ACP](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_acp)