# EMRSETPALETTEENTRIES structure

## Description

The **EMRSETPALETTEENTRIES** structure contains members for the [SetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpaletteentries) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `ihPal`

Palette handle index.

### `iStart`

Index of first entry to set.

### `cEntries`

Number of entries.

### `aPalEntries`

Array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures. Note that **peFlags** members in the structures do not contain any flags.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))

[SetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpaletteentries)