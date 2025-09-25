## Description

The **UFF_FONTDIRECTORY** structure is used to specify the directory of font descriptions contained in a Unidrv font format file (.uff file).

## Members

### `dwSignature`

Specifies the font metrics record signature. This value must be FONT_REC_SIG.

### `wSize`

Specifies the size, in bytes, of the UFF_FONTDIRECTORY structure.

### `wFontID`

Specifies the font identifier. This value must match the **wDataID** member of a [**DATA_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_data_header) structure that specifies font metrics information within the .uff file.

### `sGlyphID`

Specifies the glyph set identifier. This value specifies the glyph set that is to be associated with the font. See the following Remarks section.

### `wFlags`

Is a set of bit flags. One or more of the following flags can be specified.

| Flag | Definition |
|---|---|
| FONT_FL_DEVICEFONT | The font is a device font. |
| FONT_FL_GLYPHSET_GTT | The glyph set is specified in [GTT](https://learn.microsoft.com/windows-hardware/drivers/) format. |
| FONT_FL_GLYPHSET_RLE | The glyph set is specified in [RLE](https://learn.microsoft.com/windows-hardware/drivers/) format. |
| FONT_FL_IFI | Font metrics are specified in IFI format. |
| FONT_FL_PERMANENT_SF | The font is a PCL permanent soft font. |
| FONT_FL_SOFTFONT | The font is a [PCL](https://learn.microsoft.com/windows-hardware/drivers/) soft font. |
| FONT_FL_UFM | Font metrics are specified in [UFM](https://learn.microsoft.com/windows-hardware/drivers/) format. |

### `dwInstallerSig`

Specifies the signature value of the font installer that installed the font.

### `offFontName`

Specifies the offset, in bytes, from the beginning of the .uff file to a DWORD-aligned, NULL-terminated, Unicode string representing the name of the font.

### `offCartridgeName`

Specifies the offset, in bytes, from the beginning of the .uff file to a DWORD-aligned, NULL-terminated, Unicode string representing the name of the font cartridge containing the font. If the font is not contained in a cartridge, this value should be zero.

### `offFontData`

Specifies the offset, in bytes, from the beginning of the .uff file to a DWORD-aligned [**DATA_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_data_header) structure specifying a font metrics section.

### `offGlyphData`

Specifies the offset, in bytes, from the beginning of the .uff file to a DWORD-aligned DATA_HEADER structure specifying a glyph set section. If **sGlyphID** is zero or negative, **offGlyphData** should be zero.

### `offVarData`

Specifies the offset, in bytes, from the beginning of the .uff file to a DWORD-aligned [**DATA_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_data_header) structure specifying a data section. If the FONT_FL_PERMANENT_SF flag is set in **wFlags**, **offVarData** must be zero.

## Remarks

If **sGlyphID** is a greater than zero, it must match the **wDataID** member of a [**DATA_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_data_header) structure that specifies a glyph set within the .uff file.

If **sGlyphID** is less than zero, it must be one of the CC_-prefixed constants defined in prntfont.h, which identify predefined glyph sets.

If **sGlyphID** is zero, Unidrv uses the glyph set resource identifier contained in the font's UNIFM_HDR structure. The glyph set resource must be contained in the minidriver's resource DLL, or else Unidrv uses the default glyph translation.

## See also

[**DATA_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_data_header)