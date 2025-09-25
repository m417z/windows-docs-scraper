# IFIEXTRA structure

## Description

The IFIEXTRA structure defines additional information for a given typeface that GDI can use.

## Members

### `ulIdentifier`

Should be set to zero. This member was used by GDI to identify Type1 fonts on Windows NT 4.0.

### `dpFontSig`

Specifies the offset in bytes from the beginning of the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure to the FONTSIGNATURE structure (described in the Microsoft Window SDK documentation). The driver should set this member to zero if it does not support multiple character sets.

The character set information in FONTSIGNATURE should be consistent with the information provided in the character sets array to which the **dpCharSets** member of IFIMETRICS points.

### `cig`

Specifies the number of distinct glyphs in a font that supports glyph indices. The font's glyph handles are contiguous values that range from 0 to (**cig**-1). For OpenType fonts, this value is stored in the *numGlyphs* value of the *maxp* table.

Fonts that do not have contiguous glyph handles should set this member to zero. Note that the Window SDK glyph index APIs will not work for fonts that set this member to zero.

### `dpDesignVector`

Is the offset from the beginning of the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure to the DESIGNVECTOR structure for this font. The driver should set **dpDesignVector** only if this font is a multiple master font. The DESIGNVECTOR structure is described in the Window SDK documentation.

### `dpAxesInfoW`

Is the offset from the beginning of the IFIMETRICS structure to the AXESINFOW structure for this font. The driver should set **dpAxesInfoW** only if this font is a multiple master font. The AXESINFOW structure is described in the Window SDK documentation.

### `aulReserved`

Is reserved and should be ignored by the driver.

## Remarks

When used, this structure lies below the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure in memory.

## See also

[DrvQueryFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfont)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)