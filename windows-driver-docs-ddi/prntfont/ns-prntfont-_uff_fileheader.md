## Description

The UFF_FILEHEADER structure is used to define the contents of [Unidrv font format files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.uff files).

## Members

### `dwSignature`

Specifies the signature for .uff files. This value must be UFF_FILE_MAGIC.

### `dwVersion`

Specifies the format version for .uff files. This value must be UFF_VERSION_NUMBER. The HIWORD contains the major version number and the LOWORD contains the minor version number.

### `dwSize`

Specifies the size, in bytes, of the UFF_FILEHEADER structure.

### `nFonts`

Specifies the number of fonts specified within the .uff file and identified by [**DATA_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_data_header) structures. This is also the number of [**UFF_FONTDIRECTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uff_fontdirectory) structures within the .uff file.

### `nGlyphSets`

Specifies the number of glyph sets specified within the .uff file and identified by DATA_HEADER structures. Some fonts might share a glyph set.

### `nVarData`

Specifies the number of variable data sections specified within the .uff file and identified by DATA_HEADER structures.

### `offFontDir`

Specifies the offset, in bytes, from the beginning of the .uff file to the beginning of the first [**UFF_FONTDIRECTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uff_fontdirectory) structure.

### `dwFlags`

Is a set of bit flags, as specified in the following table.

| Flag | Definition |
|---|---|
| FONT_DIR_SORTED | The array of UFF_FONTDIRECTORY structures (specified by **offFontDir**) is sorted by the contents of that structure's **wFontID** member. |

### `dwReserved`

Reserved. Must be set to zero.

## See also

[**DATA_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_data_header)

[**UFF_FONTDIRECTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uff_fontdirectory)