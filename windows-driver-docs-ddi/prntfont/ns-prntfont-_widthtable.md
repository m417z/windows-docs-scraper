# _WIDTHTABLE structure

## Description

The WIDTHTABLE structure is used to define the contents of [Unidrv font metrics files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.ufm files).

## Members

### `dwSize`

Specifies the size, in bytes, of the WIDTHTABLE structure, including the **WidthRun** array.

### `dwRunNum`

Specifies the number of elements in the **WidthRun** array.

### `WidthRun`

Is an array of [WIDTHRUN](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_widthrun) structures.

## Remarks

A .ufm file's WIDTHTABLE structure, which describes character widths, is accessed by a pointer in the file's [UNIFM_HDR](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unifm_hdr) structure.

## See also

[UNIFM_HDR](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unifm_hdr)

[WIDTHRUN](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_widthrun)