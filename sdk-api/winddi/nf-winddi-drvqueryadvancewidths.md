# DrvQueryAdvanceWidths function

## Description

The **DrvQueryAdvanceWidths** function returns character advance widths for a specified set of glyphs.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) that was previously returned by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `pfo`

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure that identifies the font instance.

### `iMode`

Specifies the type of information to be provided. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| QAW_GETEASYWIDTHS | The character advance widths are returned as an array of 12.4 fixed-point numbers. This mode will not be used if the widths exceed the range of the 12.4 representation. This routine should compute widths as quickly as possible. If the computation of a glyph's character advance width cannot be accomplished efficiently, the driver should write 0xFFFF into the buffer for that glyph. The function returns DDI_ERROR if an error occurs, **FALSE** if not all widths can be efficiently computed for this mode, or **TRUE** in all other cases. |
| QAW_GETWIDTHS | The character advance widths are recorded as an array of 12.4 fixed-point numbers. This mode will not be used if the widths exceed the range of the 12.4 representation. The function returns **TRUE** if successful. |

### `phg` [in]

Pointer to an array of glyph handles that specify the glyphs for which the driver will return character advance widths.

### `pvWidths` [out]

Pointer to a buffer where the driver will record data.

### `cGlyphs`

Specifies the number of glyphs in the input buffer pointed to by *phg*.

## Return value

The return value is dependent on the value of the *iMode* parameter.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)