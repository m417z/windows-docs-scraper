## Description

The UNIDRVINFO structure is used to specify printer-specific information within [Unidrv font metrics files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.ufm files).

## Members

### `dwSize`

Specifies the size, in bytes, of the UNIDRVINFO structure.

### `flGenFlags`

Contains one or more bit flags describing font characteristics. The following flags are defined:

| Flag | Definition |
|---|---|
| UFM_CART | The font is contained in a cartridge. |
| UFM_SCALABLE | The font is scalable. |
| UFM_SOFT | The font is a soft font, requiring downloading. |

### `wType`

Contains an integer constant describing the font type. The following constants are defined:

| Constant | Definition |
|---|---|
| DF_TYPE_CAPSL | Canon CAPSL scalable font |
| DF_TYPE_HPINTELLIFONT | HP Intellifont font |
| DF_TYPE_OEM1 | OEM-supplied scalable font |
| DF_TYPE_OEM2 | OEM-supplied scalable font |
| DF_TYPE_PST1 | Lexmark PPDS scalable font |
| DF_TYPE_TRUETYPE | HP PCLETTO font for LJ4 printers |

### `fCaps`

Contains one or more bit flags identifying limitations on the capabilities provided by a device font. The following flags are defined:

| Flag | Definition |
|---|---|
| DF_BKSP_OK | If set, a single backspace character can move the cursor to the beginning of the overstrike region. If not set, an x-movement cursor command must be sent. (Used only if MTYPE_PAIRED is specified for the character's [**TRANSDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_transdata) structure in [**MAPTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_maptable). Otherwise ignored.) |
| DF_NO_BOLD | The device font cannot be bolded using underline simulation. |
| DF_NO_DOUBLE_UNDERLINE | The device font cannot be double-underlined using double-underline simulation. |
| DF_NO_STRIKETHRU | The device font cannot be struck through using strike-through simulation. |
| DF_NOITALIC | The device font cannot be italicized using italic simulation. |
| DF_NOUNDER | The device font cannot be underlined using underline simulation. |
| DF_XM_CR | Unidrv must send a carriage return command after each line of text. |

### `wXRes`

Specifies the font's x-resolution.

### `wYRes`

Specifies the font's y-resolution.

### `sYAdjust`

Specifies the amount of vertical adjustment required before output of double-height characters on dot-matrix printers.

### `sYMoved`

Specifies the amount of vertical cursor movement that results when a double-height character is printed on a dot-matrix printer.

### `wPrivateData`

Can be used for printer-specific information such as, for example, HP DeskJet permutations.

### `sShift`

Specifies the number of pixels by which each character must be shifted. Used for the Microsoft Z1a cartridge.

### `SelectFont`

Is an [**INVOC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_invoc) structure containing the printer's font selection command.

### `UnSelectFont`

Is an INVOC structure containing the printer's font deselection command.

### `wReserved`

Not used.

## Remarks

A .ufm (Unidrv Font Metrics) file's UNIDRVINFO structure is accessed by a pointer in the file's [**UNIFM_HDR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unifm_hdr) structure.

## See also

[**INVOC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_invoc)