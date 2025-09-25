# EMREXTCREATEPEN structure

## Description

The **EMREXTCREATEPEN** structure contains members for the [ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen) enhanced metafile record. If the record contains a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure, it is followed by the bitmap bits that form a packed device-independent bitmap (DIB).

## Members

### `emr`

The base structure for all record types.

### `ihPen`

Index to pen in handle table.

### `offBmi`

Offset to [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure, if any.

### `cbBmi`

Size of [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure, if any.

### `offBits`

Offset to brush bitmap bits, if any.

### `cbBits`

Size of brush bitmap bits, if any.

### `elp`

Extended logical pen, including the **elpStyleEntry** member of the [EXTLOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-extlogpen) structure.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[EXTLOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-extlogpen)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)