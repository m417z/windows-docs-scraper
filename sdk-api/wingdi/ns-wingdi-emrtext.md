# EMRTEXT structure

## Description

The **EMRTEXT** structure contains members for text output.

## Members

### `ptlReference`

The logical coordinates of the reference point used to position the string.

### `nChars`

The number of characters in the string.

### `offString`

The offset to the string.

### `fOptions`

A value that indicates how to use the application-defined rectangle. This member can be a combination of the ETO_CLIPPED and ETO_OPAQUE values.

### `rcl`

An optional clipping and/or opaquing rectangle, in logical units.

### `offDx`

The offset to the intercharacter spacing array.

## Remarks

The **EMRTEXT** structure is used as a member in the [EMREXTTEXTOUT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emrexttextouta) and [EMRPOLYTEXTOUT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emrpolytextouta) structures.

## See also

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)