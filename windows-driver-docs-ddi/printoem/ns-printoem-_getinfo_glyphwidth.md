## Description

The **GETINFO_GLYPHWIDTH** structure is used as input to the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Members

### `dwSize`

Size, in bytes, of the **GETINFO_GLYPHWIDTH** structure. Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `dwType`

Specifies the type of the glyph specifier array pointed to by **pGlyph**. Valid values are:

- TYPE_GLYPHHANDLE

- TYPE_GLYPHID

Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `dwCount`

Specifies the number of elements in the array pointed to by **pGlyph**. Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `pGlyph`

Pointer to an array of glyph specifiers. The array element type is indicated by **dwType**. Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `plWidth`

Pointer to a location into which Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function places the width value. The pointer is supplied by the UNIFONTOBJ_GetInfo caller.

## Remarks

To obtain the width of a set of glyphs, a rendering plug-in can supply the address of a GETINFO_GLYPHWIDTH structure when calling Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function. The callback function calculates the total width of all the glyphs described by the input array, and places the calculated value in the location pointed to by **plWidth**.

## See also

[UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo)