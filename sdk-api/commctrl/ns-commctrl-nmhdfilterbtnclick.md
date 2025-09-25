# NMHDFILTERBTNCLICK structure

## Description

Specifies or receives the attributes of a filter button click.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

A handle of an [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information.

### `iItem`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the control to which this structure refers.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the client rectangle for the filter button.

## See also

[HDN_FILTERBTNCLICK](https://learn.microsoft.com/windows/desktop/Controls/hdn-filterbtnclick)