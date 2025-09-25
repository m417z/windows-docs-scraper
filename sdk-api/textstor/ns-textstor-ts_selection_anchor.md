# TS_SELECTION_ANCHOR structure

## Description

The **TS_SELECTION_ANCHOR** structure contains anchor-based text selection data.

## Members

### `paStart`

Contains the start anchor of the selection.

### `paEnd`

Contains the end anchor of the selection.

### `style`

A [TS_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selectionstyle) structure that contains additional selection data.

## See also

[ITextStoreAnchor::GetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getselection)

[ITextStoreAnchor::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-setselection)

[TS_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selectionstyle)