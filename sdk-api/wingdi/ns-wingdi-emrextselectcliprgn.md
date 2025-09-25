# EMREXTSELECTCLIPRGN structure

## Description

The **EMREXTSELECTCLIPRGN** structure contains members for the [ExtSelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extselectcliprgn) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `cbRgnData`

Size of region data, in bytes.

### `iMode`

Operation to be performed. This member must be one of the following values: RGN_AND, RGN_COPY, RGN_DIFF, RGN_OR, or RGN_XOR.

### `RgnData`

Buffer containing a [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure.

## See also

[ExtSelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extselectcliprgn)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)