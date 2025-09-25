# ITextStoreAnchor::SetSelection

## Description

Selects text within the document.

## Parameters

### `ulCount` [in]

Specifies the number of text selections in *pSelection*.

### `pSelection` [in]

Specifies the style, start, and end character positions of the text selected through the [TS_SELECTION_ANCHOR](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_anchor) structure. The start anchor member **paStart** of the structure must never follow the end anchor member **paEnd**, although they might be at the same location.

When **paStart** = **paEnd**, the method places a caret at the anchor location. There can be only one caret at a time in the text stream.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | The method was unable to allocate sufficient memory to complete the operation. |
| **TF_E_INVALIDPOS** | The anchor locations specified are beyond the text in the document. |
| **TF_E_NOLOCK** | The caller does not have a read/write lock. |

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::GetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getselection)

[TS_SELECTION_ANCHOR](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_anchor)