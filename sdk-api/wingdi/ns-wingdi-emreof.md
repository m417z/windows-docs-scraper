# EMREOF structure

## Description

The **EMREOF** structure contains data for the enhanced metafile record that indicates the end of the metafile.

## Members

### `emr`

The base structure for all record types.

### `nPalEntries`

The number of palette entries.

### `offPalEntries`

The offset, in bytes, to an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures.

### `nSizeLast`

The same size as the **nSize** member of the [EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr) structure. This member must be the last double word of the record. If palette entries exist, they precede this member.

## See also

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))