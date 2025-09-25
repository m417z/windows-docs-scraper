# TS_SELECTION_ACP structure

## Description

The **TS_SELECTION_ACP** structure contains ACP-based text selection data.

## Members

### `acpStart`

Contains the start position of the selection.

### `acpEnd`

Contains the end position of the selection.

### `style`

A [TS_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selectionstyle) structure that contains additional selection data.

## See also

[ITextStoreACP::GetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getselection)

[ITextStoreACP::SetSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-setselection)

[TS_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selectionstyle)